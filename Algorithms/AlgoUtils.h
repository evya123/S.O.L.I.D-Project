//
// Created by evya on 1/12/19.
//

#ifndef S_O_L_I_D_ALGOUTILS_H
#define S_O_L_I_D_ALGOUTILS_H
#include "MatrixSearcher.h"
#include <algorithm>
#define MATRIX_DEF State

class AlgoUtils {
protected:
    void markUnvisited(MatrixSearcher* ms);

private:
    void setVecToFalse(std::vector<State> *vec);

};


#endif //S_O_L_I_D_ALGOUTILS_H
