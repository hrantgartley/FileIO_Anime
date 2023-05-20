#include "Anime.h"


int main() {
    AnimeQueueManager manager("source/anime.txt");
    manager.run();
    return 0;
}
