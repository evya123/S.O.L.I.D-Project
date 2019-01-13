
#include <Algorithms/DFS.h>
#include "MyTestClientHandler.h"
//#define MATRIX_DEF State<std::pair<int,int>*>

void server_side::MyTestClientHandler::handleClient(int sockID) {
    int newsockfd = sockID;
    std::vector<std::vector<State*>> allCombined;
    int n;
    int counter = 0, matrixCounter = 0;
    std::string sumOfAll = "";
    char line[MAXPACKETSIZE];
    PAIR tmpS;
    PAIR tmpE;
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
        sumOfAll += line;
        switch (counter) {
            case 0:
                counter++;
                tmpS = m_lexer->LexerInitialAndGoalPoints(line);
                break;
            case 1:
                tmpE = m_lexer->LexerInitialAndGoalPoints(line);
                counter++;
                break;
            default:
                std::string tmp = line;
                allCombined.push_back(m_lexer->LexerMatrix(tmp,
                        matrixCounter));
                matrixCounter++;
                break;
        }
    }
    MatrixSearcher *problem =
            new MatrixSearcher(allCombined, &tmpS, &tmpE);
    std::vector<std::string> solutions;
    solutions = m_solver->solve(problem);
    for(std::string s : solutions)
        std::cout<<"Result : "<<s<<std::endl;
}