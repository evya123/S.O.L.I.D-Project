//
// Created by evya on 1/10/19.
//

#ifndef S_O_L_I_D_MYSOLVER_H
#define S_O_L_I_D_MYSOLVER_H

#include <string>
#include "Algorithms/ISearcher.h"

class SolverSearcher
        : public Solver<MatrixSearcher *, std::string> {
private:
    ISearcher<State> *m_searcher;
public:
    SolverSearcher() {};

    void setSercher(ISearcher<State> *searcher) {
        m_searcher = searcher;
    }

    std::string
    solve(MatrixSearcher *problem) override {
        return m_searcher->search(problem);
    }
};

#endif //S_O_L_I_D_MYSOLVER_H
