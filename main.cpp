#include <thread>
#include <string>
#include <stack>
#include <Input/LexerParser.h>
#include <iostream>
#include <server_side/MyParallelServer.h>
#include "server_side/MyTestClientHandler.h"
#define PAIR std::pair<int,int>
using namespace server_side;

int main(int argc, char *argv[]) {
    Server* ps = new MyParallelServer();
    ClientHandler* a = new MyTestClientHandler();
    ps->open(55555,a);
    int sockid = ps->acceptClient();
    a->handleClient(sockid);
    /*
    std::string check = argv[1];
    LexerParser *lxpar = new LexerParser();
    std::vector<std::vector<State<PAIR > *>> result;
    int i = 0;
    int counter = 1;
    for (int j = 1; j < argc; ++j) {
         i = 0;
        if ((check = argv[counter]) != "end") {
            // std::string check = argv[counter];
            result.push_back(lxpar->LexerMatrix(check, i));
            ++i;
            ++counter;
        }
    }
    std::cout << result[0][0]->getCost() << std::endl;
    std::cout << result[0][1]->getCost() << std::endl;
    std::cout << result[0][2]->getCost() << std::endl;
    std::cout << result[1][0]->getCost() << std::endl;
    std::cout << result[1][1]->getCost() << std::endl;
    std::cout << result[1][2]->getCost() << std::endl;
*/

    return 0;
}