//
// Created by evya on 1/12/19.
//

#ifndef S_O_L_I_D_ALGOUTILS_H
#define S_O_L_I_D_ALGOUTILS_H
#include "MatrixSearcher.h"
#include <algorithm>
#define MATRIX_DEF State*
auto set = [](State& s) { s.setVisit(false);};

auto setVecToFalse = [](std::vector<State>& vec) {
    std::for_each(vec.begin(), vec.end(),set);};
template <class T>
class AlgoUtils {
public:
    void markUnvisited(ISearchable<T>& ms) {
        auto start = ms.begin();
        auto end = ms.end();
        std::for_each(start,end,setVecToFalse);

    }
};


#endif //S_O_L_I_D_ALGOUTILS_H
