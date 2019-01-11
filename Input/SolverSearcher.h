//
// Created by evya on 1/10/19.
//

#ifndef S_O_L_I_D_MYSOLVER_H
#define S_O_L_I_D_MYSOLVER_H

#include <string>
#include "Algorithms/ISearcher.h"

template<class P>
class SolverSearcher : public Solver<P, std::string> {
private:
    ISearcher<P> *m_searcher;
public:
    SolverSearcher(ISearcher<P> *searcher) {
        m_searcher = searcher;
    }

    std::string solve(P problem) override {
        return m_searcher->search(problem);
    }
};

#endif //S_O_L_I_D_MYSOLVER_H
