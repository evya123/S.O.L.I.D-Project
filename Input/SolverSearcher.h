//
// Created by evya on 1/10/19.
//

#ifndef S_O_L_I_D_MYSOLVER_H
#define S_O_L_I_D_MYSOLVER_H

#include <string>
#include <map>
#include "Algorithms/ISearcher.h"
#include "Solver.h"
typedef struct returnVal{
    std::vector<std::string> matrix;
    std::vector<std::string> solutions;

}returnVal;
class SolverSearcher
        : public Solver<MatrixSearcher&, returnVal> {
private:
    std::vector<ISearcher<State*>*> m_bankOfSolvers;
public:
    SolverSearcher(std::vector<ISearcher<State*>*>& solvers){ m_bankOfSolvers = solvers;};

    returnVal solve(MatrixSearcher &problem) override {
        std::vector<std::string> retMatrix;
        std::vector<std::string> ret;
        for(ISearcher<State*>* i : m_bankOfSolvers){
            problem.resetVisited();
            std::string tmp = i->search(problem);
            retMatrix.push_back(tmp);
            ret.emplace_back(std::to_string(i->getNumberOfNodesEvaluated())+":"
            + std::to_string(problem.getGoalState()->getPathCost()));
        }
        returnVal r;
        r.matrix = retMatrix;
        r.solutions = ret;
        return r;
    }

    ~SolverSearcher() override {
        for(ISearcher<State*>* s : m_bankOfSolvers)
            delete(s);
    }


};

#endif //S_O_L_I_D_MYSOLVER_H
