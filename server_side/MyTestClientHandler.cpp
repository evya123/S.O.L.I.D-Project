#include <thread>
#include <Algorithms/DFS.h>
#include "MyTestClientHandler.h"
auto sendFunc = [](std::string& s, int newsockfd){
    ssize_t n;
    n = write(newsockfd,&s[POINTER_TO_STRING], s.size());
    s.clear();
    switch (n){
        case -1:
            perror("Couldn't write to client\n");
            exit(0);
        default:;
    }
};

void server_side::MyTestClientHandler::handleClient(int sockID) {
    int newsockfd = sockID;
    ssize_t n;
    std::vector<std::string> buff;
    std::string toMap = "";
    char line[MAXPACKETSIZE];
    while (true) {

        memset(line, 0, MAXPACKETSIZE);
        n = read(newsockfd, line, MAXPACKETSIZE);
        if (!strcmp(line, "end"))
            break;
        line[n] = 0;
        if (n == 0) {
            close(newsockfd);
            break;
        }
        buff.emplace_back(line);
        toMap += line;
    }

    MatrixArgs args;
    bool sendToClient = true;
    if (m_cache->isExist(toMap)){
        std::vector<std::string> answer = m_cache->getAnswer(toMap);
        sendToClient = false;
        for(std::string s : answer){
            sendFunc(s,newsockfd);
        }
    }
    if (sendToClient){
        args = m_lexer->FullLexer(buff);
        std::cout<<"---------------"<<std::this_thread::get_id()<<"---------------"<<std::endl;
        MatrixSearcher problem(args.matrix,args.startPos,args.goalPos);
        std::vector<std::string> solutions;
        solutions = m_solver->solve(problem);
        m_cache->addAnswerAndQuestion(toMap,solutions);
        for(std::string s : solutions){
            sendFunc(s,newsockfd);
        }
    }
}

server_side::MyTestClientHandler::~MyTestClientHandler() {
    delete m_solver;
    delete m_lexer;
}
