#include "Anime.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

AnimeQueueManager::~AnimeQueueManager() {
    std::cout << "ANIME DESTRUCTOR CALLED\n";
}

void AnimeQueueManager::Run() {
    BeginningPrompt();
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
    std::cout << std::endl;

    std::cout << "Search for a title: ";
    std::string Keyword;
    std::cin >> Keyword;
    std::vector<std::string> SearchResults = SearchTitles(Keyword);

    if (SearchResults.empty()) {
        std::cout << "No results found.\n";
        return;
    }

    std::cout << "Results found: " << SearchResults.size() << std::endl;
    SortByFirstWord();
    for (const auto& Item : SearchResults) {
        std::cout << Item << std::endl;
    }
    ClearQueue();
    EndingPrompt();
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
    int Num{};
    std::cout << "How many anime to read? ";
    std::cin >> Num;
    return Num;
}

std::vector<std::string> AnimeQueueManager::SearchTitles(const std::string& Keyword) {
    std::vector<std::string> AnimeTitles;
    std::string Line;
    std::ifstream AnimeFile(FileName);

    if (!AnimeFile.is_open()) {
        std::cout << "Failed to open the file: " << FileName << std::endl;
        return AnimeTitles;
    }

    std::string LowercaseKeyword = ToLowerCase(Keyword);
    while (std::getline(AnimeFile, Line)) {
        std::string lowercaseLine = ToLowerCase(Line);
        if (lowercaseLine.find(LowercaseKeyword) != std::string::npos) {
            AnimeTitles.push_back(Line);
        }
    }
    AnimeFile.close();
    return AnimeTitles;
}

std::string AnimeQueueManager::ToLowerCase(const std::string& str) {
    std::string Result;
    Result.reserve(str.size());
    for (char c : str) {
        Result += std::tolower(c);
    }
    return Result;
}

void AnimeQueueManager::ClearQueue() {
    MainVector.clear();
}

void AnimeQueueManager::BeginningPrompt() const {
    std::cout << "Welcome to the anime show queue manager\n";
}
void AnimeQueueManager::EndingPrompt() const {
    std::cout << "\n";
    std::cout << "Thank you for using the anime queue manager\n";
}

void AnimeQueueManager::SortByFirstWord() {
    for (int i = 1; i < MainVector.size(); i++) {
        std::string Key = MainVector[i];
        int j = i - 1;
        while (j >= 0 && MainVector[j] > Key) {
            MainVector[j + 1] = MainVector[j];
            j--;
        }
        MainVector[j + 1] = Key;
    }
}
