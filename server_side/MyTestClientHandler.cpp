
#include <Algorithms/DFS.h>
#include "MyTestClientHandler.h"

auto sendFunc = [](std::string& s, int newsockfd){
    char buff[MAXPACKETSIZE];
    int n;
    memset(buff, 0, MAXPACKETSIZE);
    std::copy(s.begin(),s.end(),buff);
    n = write(newsockfd,buff, s.size());
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
        MatrixSearcher *problem =
                new MatrixSearcher(args.matrix,args.startPos,args.goalPos);
        std::vector<std::string> solutions;
        solutions = m_solver->solve(problem);
        m_cache->addAnswerAndQuestion(toMap,solutions);
        for(std::string s : solutions){
            sendFunc(s,newsockfd);
        }
    }
}