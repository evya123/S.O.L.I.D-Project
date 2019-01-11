
#include <Algorithms/MatrixSearcher.h>
#include "MyTestClientHandler.h"

void server_side::MyTestClientHandler::handleClient(int sockID) {
    int newsockfd = sockID;
    std::vector<std::vector<State<PAIR>*>> allCombined;
    int n;
    int counter = 0;
    std::string line (MAXPACKETSIZE,0);
    State<PAIR>* tmpS;
    State<PAIR>* tmpE;
    while (line != "end") {
        line.clear();
        n = read(newsockfd, &line[0], MAXPACKETSIZE);
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
                allCombined.push_back(m_lexer->LexerMatrix(line,counter));
                counter++;
                break;
        }
    }
    MatrixSearcher* problem = new MatrixSearcher(allCombined,tmpS,tmpE);
    m_solver->solve(problem);
}
