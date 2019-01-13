//
// Created by evya on 1/12/19.
//

#include "AlgoUtils.h"

std::string AlgoUtils::printPath(State *begin, State *end) {
    std::string res = "";
    int i1;
    int i2;
    int j1;
    int j2;
    std::cout << end->getCost() << std::endl;
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
        std::cout << end->getCost() << std::endl;
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
    return res;
}
