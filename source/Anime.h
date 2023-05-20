#ifndef ANIME_QUEUE_MANAGER_H
#define ANIME_QUEUE_MANAGER_H

#include <string>
#include <vector>
#include <iostream>

class AnimeQueueManager {
   private:
    std::vector<std::string> MainVector;
    std::string FileName;

   public:
    AnimeQueueManager(const std::string& file) : FileName(file) {}
    ~AnimeQueueManager();
    void Run();
    void ClearQueue();

   private:
    void addToArray(std::vector<std::string>& array, int numTitles);
    std::vector<std::string> getInput();
    int getNum();
    std::vector<std::string> SearchTitles(const std::string& Keyword);
    std::string ToLowerCase(const std::string& Str);
};

#endif
