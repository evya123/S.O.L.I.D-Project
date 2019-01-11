//
// Created by evya on 1/10/19.
//

#include "LexerParser.h"

std::vector<State<PAIR > *>
LexerParser::LexerMatrix(std::string line, int iVecNum) {
    std::vector<State<PAIR > *> result;
    int j = 0;
    unsigned long size;
    while (size = line.size()) {
        // find the ","
        unsigned long index = line.find(",");
        if (index != -1) {
            State<PAIR > *state = new State<PAIR >(PAIR(iVecNum, j));
            state->setCost(std::stod(line.substr(0, index)));
            result.push_back(state);
            line = line.substr(index + 1);
            ++j;
            // its the last state
        } else {
            State<PAIR > *state = new State<PAIR >(PAIR(iVecNum, j));
            state->setCost(std::stod(line.substr(0, size)));
            result.push_back(state);
            line = "";
        }
    }
    return result;
}

State<PAIR > *LexerParser::LexerInitialAndGoalPoints(std::string line) {
    unsigned long index = line.find(",");
    int first = std::stoi(line.substr(0, index));
    int second = std::stoi(line.substr(index + 1, line.size()));
    State<PAIR > *state = new State<PAIR >(PAIR(first, second));
}