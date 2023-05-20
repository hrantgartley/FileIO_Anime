#include "Anime.h"

#include <fstream>
#include <iostream>

void AnimeQueueManager::run() {
    std::cout << "Welcome to the anime show queue manager\n";
    int Number = getNum();
    std::vector<std::string> itemsToAdd = getInput();
    if (itemsToAdd.empty()) {
        std::cout << "No anime titles found in the file.\n";
        return;
    }
    addToArray(mainVector, Number);
    std::cout << "Items in the queue: " << mainVector.size() << std::endl;
    for (const auto& item : mainVector) {
        std::cout << item << std::endl;
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
    std::ifstream AnimeFile(fileName);
    if (!AnimeFile.is_open()) {
        std::cout << "Failed to open the file: " << fileName << std::endl;
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
