//
// Created by evya on 1/10/19.
//

#ifndef S_O_L_I_D_LEXERPARSER_H
#define S_O_L_I_D_LEXERPARSER_H

#include <string>
#include <vector>
#include "Algorithms/State.h"

#define MATRIX_DEF State*

#define PAIR std::pair<int,int>
//#define MATRIX_DEF State<std::pair<int,int>*>

class LexerParser {
public:
    std::vector<State*> LexerMatrix(std::string &ling, int iVecNum);

    std::pair<int, int> LexerInitialAndGoalPoints(std::string line);
};


#endif //S_O_L_I_D_LEXERPARSER_H
