#include "Anime.h"

#include <fstream>
#include <iostream>

void AnimeQueueManager::ClearQueue() {
    MainVector.clear();
}

void AnimeQueueManager::Run() {
    std::cout << "Welcome to the anime show queue manager\n";
    int Number = getNum();
    std::vector<std::string> ItemsToAdd = getInput();
    if (ItemsToAdd.empty()) {
        std::cout << "No anime titles found in the file.\n";
        return;
    }

    addToArray(MainVector, Number);
    std::cout << "Items in the queue: " << MainVector.size() << std::endl;
    for (const auto& Item : MainVector) {
        std::cout << Item << std::endl;
    }

    std::cout << "Search for a title: ";
    std::string Keyword;
    std::cin >> Keyword;
    std::vector<std::string> SearchResults = SearchTitles(Keyword);

    if (SearchResults.empty()) {
        std::cout << "No results found.\n";
        return;
    }

    std::cout << "Results found: " << SearchResults.size() << std::endl;
    for (const auto& Item : SearchResults) {
        std::cout << Item << std::endl;
    }
}

void AnimeQueueManager::addToArray(std::vector<std::string>& Array, int NumTitles) {
    for (int i = 0; i < NumTitles; i++) {
        Array.push_back(getInput()[i % NumTitles]);
    }
}

std::vector<std::string> AnimeQueueManager::getInput() {
    std::vector<std::string> AnimeTitles;
    std::string Line;
    std::ifstream AnimeFile(FileName);

    if (!AnimeFile.is_open()) {
        std::cout << "Failed to open the file: " << FileName << std::endl;
        return AnimeTitles;
    }

    while (std::getline(AnimeFile, Line)) {
        AnimeTitles.push_back(Line);
    }

    AnimeFile.close();
    return AnimeTitles;
}

int AnimeQueueManager::getNum() {
    int num{};
    std::cout << "How many anime to read? ";
    std::cin >> num;
    return num;
}

std::vector<std::string> AnimeQueueManager::SearchTitles(const std::string& Keyword) {
    std::vector<std::string> AnimeTitles;
    std::string Line;
    std::ifstream AnimeFile(FileName);

    if (!AnimeFile.is_open()) {
        std::cout << "Failed to open the file: " << FileName << std::endl;
        return AnimeTitles;
    }

    std::string lowercaseKeyword = ToLowerCase(Keyword);  // Convert the keyword to lowercase
    while (std::getline(AnimeFile, Line)) {
        std::string lowercaseLine = ToLowerCase(Line);  // Convert the line to lowercase
        if (lowercaseLine.find(lowercaseKeyword) != std::string::npos) {
            AnimeTitles.push_back(Line);
        }
    }
    AnimeFile.close();
    return AnimeTitles;
}

std::string AnimeQueueManager::ToLowerCase(const std::string& str) {
    std::string result;
    result.reserve(str.size());
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}
