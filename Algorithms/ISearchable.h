//
// Created by lidor on 08/01/19.
//

#ifndef S_O_L_I_D_ISEARCHABLE_H
#define S_O_L_I_D_ISEARCHABLE_H

#include <list>
#include "vector"

template<class T>
class ISearchable {
public:
    virtual T getInitialState() = 0;

    virtual T getGoalState() = 0;

    virtual std::vector<T> getAllPossibleStates(int i, int j) = 0;


};

#endif //S_O_L_I_D_ISEARCHABLE_H
