//
// Created by lidor on 08/01/19.
//

#ifndef S_O_L_I_D_ISEARCHABLE_H
#define S_O_L_I_D_ISEARCHABLE_H

#include <list>
template<class T>
class ISearchable {
public:
    T *getInitialState() = 0;
    T *getGoalState() = 0;
    std::list<T> getAllPossibleStates(T) = 0;


};

#endif //S_O_L_I_D_ISEARCHABLE_H
