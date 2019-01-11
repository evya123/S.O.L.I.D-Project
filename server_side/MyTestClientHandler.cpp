
#include <Algorithms/MatrixSearcher.h>
#include "MyTestClientHandler.h"
void server_side::MyTestClientHandler::handleClient(int sockID) {
    int newsockfd = sockID;
    std::vector<std::vector<State<PAIR>*>> allCombined;
    int n;
    int counter = 0, matrixCounter = 0;
    char line[MAXPACKETSIZE];
    PAIR tmpS;
    PAIR tmpE;
    while (true) {
        memset(line, 0, MAXPACKETSIZE);
        n = read(newsockfd, line, MAXPACKETSIZE);
        if (!strcmp(line,"end"))
            break;
        line[n] = 0;
        if (n == 0) {
            close(newsockfd);
            break;
        }
        switch (counter){
            case 0:
                counter++;
                tmpS = m_lexer->LexerInitialAndGoalPoints(line);
                break;
            case 1:
                tmpE = m_lexer->LexerInitialAndGoalPoints(line);
                counter++;
                break;
            default:
                allCombined.push_back(m_lexer->LexerMatrix(line,matrixCounter));
                matrixCounter++;
                break;
        }
    }
    MatrixSearcher* problem = new MatrixSearcher(allCombined,&tmpS,&tmpE);
    std::string solution = m_solver->solve(problem);
    m_cache->addAnswerAndQuestion(problem,solution);
}
