//
// Created by evya on 1/12/19.
//

#ifndef S_O_L_I_D_ALGOUTILS_H
#define S_O_L_I_D_ALGOUTILS_H

#include <algorithm>
#include <iostream>
#include <functional>
#include "ISearchable.h"
#include "State.h"

#define MATRIX_DEF State*
auto set = [](State *s) { s->setVisit(false); };

auto setVecToFalse = [](std::vector<State *> &vec) {
    std::for_each(vec.begin(), vec.end(), set);
};

template<class T>
class AlgoUtils {
public:
    AlgoUtils() = default;

    static std::string printPath(State *begin, State *end) {
        std::string res = "";
        int i1;
        int i2;
        int j1;
        int j2;
        i1 = end->getPlace().first;
        i2 = end->getCameFrom()->getPlace().first;
        j1 = end->getPlace().second;
        j2 = end->getCameFrom()->getPlace().second;
        if (j1 == j2) {
            i1 > i2 ? res = ", Down " + res : res = ", UP " + res;
        } else {
            j1 > j2 ? res = ", Right " + res : res = ", Left " + res;
        }
        end = end->getCameFrom();
        while (end != begin) {
            i1 = end->getPlace().first;
            i2 = end->getCameFrom()->getPlace().first;
            j1 = end->getPlace().second;
            j2 = end->getCameFrom()->getPlace().second;
            if (j1 == j2) {
                i1 > i2 ? res = ", Down " + res : res = ", UP " + res;
            } else {
                j1 > j2 ? res = ", Right " + res : res = ", Left " + res;
            }
            end = end->getCameFrom();
        }
        res.erase(0, 2);
        return res + "\n";
    }

    static void ShortestPath(State *begin, State *end) {
        State *current = end;
        double s = 0;
        // end cost
        s += current->getCost();
        current = current->getCameFrom();
        while (!current->equals(begin)) {
            s += current->getCost();
            current = current->getCameFrom();
        }
        //begin;
        s += current->getCost();
        end->setPathCost(s);
        std::cout << "num ofPath : " << end->getPathCost() << std::endl;
    }
};


#endif //S_O_L_I_D_ALGOUTILS_H
