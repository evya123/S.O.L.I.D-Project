//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_SOLVER_H
#define S_O_L_I_D_SOLVER_H
template <class Problem, class Soultion>
class Solver {
    virtual Soultion solve (Problem problem) = 0 ;
};

#endif //S_O_L_I_D_SOLVER_H
