//
// Created by evya on 1/10/19.
//

#include "LexerParser.h"

std::vector<State<PAIR > *> LexerParser::LexerMatrix(std::string line, int
iVecNum) {
    std::vector<State<PAIR > *> result;
    int j = 0;
    while (line.size()) {
        int index = line.find(",");
        if (index != std::string::npos) {
            State<PAIR > *state = new State<PAIR >(PAIR(iVecNum, j));
            result.push_back(state);
            line = line.substr(index + 1);
            ++j;
        }
        return result;
    }
}
