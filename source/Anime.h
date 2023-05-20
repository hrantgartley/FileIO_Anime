#ifndef ANIME_QUEUE_MANAGER_H
#define ANIME_QUEUE_MANAGER_H

#include <string>
#include <vector>

class AnimeQueueManager {
   private:
    std::vector<std::string> MainVector;
    std::vector<std::string> newTitles;
    std::string FileName;

   public:
    AnimeQueueManager(const std::string& file) : FileName(file) {}
    void Run();

   private:
    void addToArray(std::vector<std::string>& array, int numTitles);
    std::vector<std::string> getInput();
    int getNum();
};

#endif
