//
// Created by evya on 1/10/19.
//

#ifndef S_O_L_I_D_MYSOLVER_H
#define S_O_L_I_D_MYSOLVER_H


#include "Solver.h"
#include <string>

class SolverSearcher : public Solver<std::string, std::string>{
public:
    std::string solve(std::string problem, Searcher *search) override;
private:
    Searcher* m_searcher;
};


#endif //S_O_L_I_D_MYSOLVER_H