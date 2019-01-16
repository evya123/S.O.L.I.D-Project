#include "server_side/ClientHandler.h"
#include "server_side/FileCacheManager.h"
#include "server_side/MyTestClientHandler.h"
#include "server_side/MyParallelServer.h"
#include "Algorithms/DFS.h"
#include "Algorithms/Astar.h"
#include "Algorithms/BestFirstSearch.h"
#include "ThreadPool.h"
#define PORT 1
#define NUM_OF_THREADS 10
typedef std::string PART_A;
typedef std::vector<std::string> PART_B;

using namespace server_side;


void startHandle(int s, CacheManager<PART_A, PART_B> *f){
    std::vector<ISearcher<State*>*> solvers {new BestFirstSearch,
                                             new DFS, new BFS,
                                             new Astar};
    MyTestClientHandler a(solvers, f);
    a.handleClient(s);
}

int main(int argc, char *argv[]) {


    FileCacheManager* cache = new FileCacheManager();
    MyParallelServer ps;
    std::vector<ISearcher<State*>*> solvers {nullptr, nullptr, nullptr,
                                             nullptr};
    MyTestClientHandler a(solvers, cache);
    int port;
    try {
        port = std::stoi(argv[PORT]);
    } catch (...) {
        std::cerr<<"Problem with passing arguments"<<std::endl;
        delete(cache);
    }

    ps.open(port);

    ThreadPool pool(NUM_OF_THREADS);

    while(true){
        int sockid = ps.acceptClient();
        switch (sockid){
            case TIME_OUT:;
                std::cout<<"Exiting!!\n";
                cache->saveToFile("Success.txt");
                delete(cache);
                exit(EXIT_SUCCESS);
            default:
                pool.taskQueue(startHandle,sockid,cache);
                continue;
        }
    }
}