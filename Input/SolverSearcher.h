//
// Created by evya on 1/10/19.
//

#ifndef S_O_L_I_D_MYSOLVER_H
#define S_O_L_I_D_MYSOLVER_H

#include <string>
#include <map>
#include "Algorithms/ISearcher.h"

class SolverSearcher
        : public Solver<MatrixSearcher*, std::vector<std::string>> {
private:
    std::vector<ISearcher<State*>*> m_bankOfSolvers;
public:
    SolverSearcher(std::vector<ISearcher<State*>*>& solvers){ m_bankOfSolvers = solvers;};

    std::vector<std::string> solve(MatrixSearcher *problem) override {
        std::vector<std::string> ret;
        for(ISearcher<State*>* i : m_bankOfSolvers){
            std::string tmp = i->search(problem);
            ret.push_back(tmp);
        }
        return ret;
    }
};

#endif //S_O_L_I_D_MYSOLVER_H
