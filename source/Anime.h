#ifndef ANIME_QUEUE_MANAGER_H
#define ANIME_QUEUE_MANAGER_H

#include <string>
#include <vector>

class AnimeQueueManager {
   private:
    std::vector<std::string> mainVector;
    std::vector<std::string> newTitles;
    std::string fileName;

   public:
    AnimeQueueManager(const std::string& file) : fileName(file) {}

    void run();

   private:
    void addToArray(std::vector<std::string>& array, int numTitles);
    std::vector<std::string> getInput();
    int getNum();
};

#endif
