//
// Created by evya on 1/10/19.
//

#ifndef S_O_L_I_D_LEXERPARSER_H
#define S_O_L_I_D_LEXERPARSER_H

#include <string>
#include <vector>

#define PAIR std::pair<int,int>

#include "Algorithms/State.h"

class LexerParser {
public:
    std::vector<State<PAIR>*> LexerMatrix(std::string ling, int iVecNum);
};


#endif //S_O_L_I_D_LEXERPARSER_H
