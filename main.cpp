#include <thread>
#include <string>
#include <stack>
#include <Input/LexerParser.h>
#include <iostream>

#define PAIR std::pair<int,int>

int main(int argc, char *argv[]) {
    std::string check = argv[1];
    LexerParser *lxpar = new LexerParser();

    State<PAIR > *state = lxpar->LexerInitialAndGoalPoints(check);
    std::cout << state->getState().first << " , " << state->getState().second <<
              std::endl;

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