//
// Created by evya on 1/10/19.
//

#include "LexerParser.h"

std::vector<MATRIX_DEF>
LexerParser::LexerMatrix(std::string &line, int iVecNum) {
    std::vector<MATRIX_DEF> result;
    int j = 0;
    unsigned long size;
    while (size = line.size()) {
        // find the ","
        unsigned long index = line.find(",");
        if (index != -1) {
            State *state = new State(PAIR(iVecNum, j));
            state->setCost(std::stod(line.substr(0, index)));
            result.push_back(state);
            line = line.substr(index + 1);
            ++j;
            // its the last state
        } else {
            State *state = new State(PAIR(iVecNum, j));
            state->setCost(std::stod(line.substr(0, size)));
            result.push_back(state);
            line = "";
        }
    }
    return result;
}

std::pair<int, int> LexerParser::LexerInitialAndGoalPoints(std::string line) {
    unsigned long index = line.find(",");
    int first = std::stoi(line.substr(0, index));
    int second = std::stoi(line.substr(index + 1, line.size()));
    return std::make_pair(first, second);
}
