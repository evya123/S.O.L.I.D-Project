//
// Created by lidor on 08/01/19.
//

#ifndef S_O_L_I_D_ISEARCHER_H
#define S_O_L_I_D_ISEARCHER_H

#include "ISearchable.h"

template<class Solution,class T>
class ISearcher {
public:
    virtual Solution search(ISearchable<T> searchable) = 0;

    virtual int getNumberOfNodesEvaluated() = 0;
};

#endif //S_O_L_I_D_ISEARCHER_H
