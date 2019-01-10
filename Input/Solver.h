//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_SOLVER_H
#define S_O_L_I_D_SOLVER_H

#include <Algorithms/Searcher.h>

template <class Problem, class Soultion>
class Solver {
public:
    virtual std::string solve(std::string problem, Searcher *search) = 0 ;
};

#endif //S_O_L_I_D_SOLVER_H
