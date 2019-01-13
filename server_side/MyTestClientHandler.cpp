
#include <Algorithms/DFS.h>
#include "MyTestClientHandler.h"

void server_side::MyTestClientHandler::handleClient(int sockID) {
    int newsockfd = sockID;
    ssize_t n;
    std::vector<std::string> buff;
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
    }

    MatrixArgs args;
    args = m_lexer->FullLexer(buff);
    MatrixSearcher *problem =
            new MatrixSearcher(args.matrix,args.startPos,args.goalPos);
    std::vector<std::string> solutions;
    solutions = m_solver->solve(problem);
    for(std::string s : solutions)
        std::cout<<"Result : "<<s<<std::endl;
}