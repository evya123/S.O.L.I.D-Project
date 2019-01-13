//
// Created by evya on 1/10/19.
//

#include "LexerParser.h"

std::vector<std::vector<State*>>
LexerParser::LexerMatrix(std::vector<std::string>::iterator &matrixIterStart,
                        std::vector<std::string>::iterator &matrixIterEnd) {
    std::vector<std::vector<State*>> ret;
    std::vector<State*> result;
    int iVecNum = 0;
    int j;
    ssize_t size;
    while(matrixIterStart != matrixIterEnd){
        j = 0;
        result;
        while (size = (*matrixIterStart).size()) {
            // find the ","
            unsigned long index = (*matrixIterStart).find(",");
            if (index != -1) {
                State *state = new State(PAIR(iVecNum, j));
                try {
                    state->setCost(std::stod((*matrixIterStart).substr(0, index)));
                } catch (...){
                    std::__throw_invalid_argument("Invalid argument!");
                }
                result.emplace_back(state);
                (*matrixIterStart) = (*matrixIterStart).substr(index + 1);
                ++j;
                // its the last state
            } else {
                State *state = new State(PAIR(iVecNum, j));
                try {
                    state->setCost(std::stod((*matrixIterStart).substr(0, size)));
                }catch (...){
                    std::__throw_invalid_argument("Invalid argument!");
                };
                result.emplace_back(state);
                (*matrixIterStart) = "";
            }
        }
        ret.emplace_back(result);
        result.clear();
        ++iVecNum;
        ++matrixIterStart;
    }
    return ret;
}

std::pair<int, int> LexerParser::LexerInitialAndGoalPoints(std::string line) {
    unsigned long index = line.find(",");
    int first, second;
    try {
        first = std::stoi(line.substr(0, index));
    }catch (...){
        std::__throw_invalid_argument("Invalid argument!");
    };
    try {
        second = std::stoi(line.substr(index + 1, line.size()));
    }catch (...){
        std::__throw_invalid_argument("Invalid argument!");
    };
    return std::make_pair(first, second);
}


auto set = [](MatrixArgs& args, auto matrixIterEnd, auto pairIterEnd, LexerParser* self){
    int idx = 0;
    while(matrixIterEnd != pairIterEnd){
        switch (idx){
            case 0:
                args.startPos = self->LexerInitialAndGoalPoints((*matrixIterEnd));
                ++matrixIterEnd;
                ++idx;
                continue;
            case 1:
                args.goalPos = self->LexerInitialAndGoalPoints((*matrixIterEnd));
                ++matrixIterEnd;
                continue;
        }
    }
};

MatrixArgs LexerParser::FullLexer(std::vector<std::string> &vec) {
    auto matrixIterStart = vec.begin();
    auto matrixIterEnd = vec.end() - 2;
    auto pairIterEnd = vec.end();
    MatrixArgs args;
    args.matrix = LexerMatrix(matrixIterStart,matrixIterEnd);
    set(args,matrixIterEnd,pairIterEnd,this);
    return args;
}
