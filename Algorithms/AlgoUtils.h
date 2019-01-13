//
// Created by evya on 1/12/19.
//

#ifndef S_O_L_I_D_ALGOUTILS_H
#define S_O_L_I_D_ALGOUTILS_H
#include <algorithm>
#include <iostream>
#include "State.h"

#define MATRIX_DEF State*
//auto set = [](State* s) { s->setVisit(false);};
//
//auto setVecToFalse = [](std::vector<State*>& vec) {
//    std::for_each(vec.begin(), vec.end(),set);};

class AlgoUtils {
public:
    AlgoUtils() = default;
    static std::string printPath(State *begin, State *end);

//    void markUnvisited(ISearchable<T>* ms) {
//        auto start = ms->begin();
//        auto end = ms->end();
//        std::for_each(start,end,setVecToFalse);
//    }
};


#endif //S_O_L_I_D_ALGOUTILS_H
