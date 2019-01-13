//
// Created by evya on 1/10/19.
//

#ifndef S_O_L_I_D_LEXERPARSER_H
#define S_O_L_I_D_LEXERPARSER_H

#include <string>
#include <vector>
#include "Algorithms/State.h"

#define PAIR std::pair<int,int>
//#define MATRIX_DEF State<std::pair<int,int>*>
typedef struct args{
    std::vector<std::vector<State*>> matrix;
    std::pair<int, int> startPos;
    std::pair<int, int> goalPos;
}MatrixArgs;
class LexerParser {
public:

    MatrixArgs FullLexer(std::vector <std::string> &vec);

    std::vector<std::vector<State*>>
    LexerMatrix(std::vector<std::string>::iterator &matrixIterStart, std::vector<std::string>::iterator &matrixIterEnd);

    std::pair<int, int> LexerInitialAndGoalPoints(std::string line);
};


#endif //S_O_L_I_D_LEXERPARSER_H
