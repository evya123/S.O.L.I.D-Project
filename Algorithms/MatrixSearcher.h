//
// Created by lidor on 10/01/19.
//

#ifndef S_O_L_I_D_MATRIXSEARCHER_H
#define S_O_L_I_D_MATRIXSEARCHER_H


#include <vector>
#include "ISearchable.h"
#include "State.h"
#include "AlgoUtils.h"
#include <algorithm>

typedef std::vector<std::vector<State *>>::iterator MatrixIter;

class MatrixSearcher : public ISearchable<State *> {
private:
    std::vector<std::vector<State *>> m_Matrix;
    State *m_initial_state;
    State *m_goal_state;


public:

    MatrixSearcher(std::vector<std::vector<State *>> matrix,
                   std::pair<int, int> *initial, std::pair<int, int> *goal)
            : m_Matrix(matrix),
              m_initial_state(m_Matrix[initial->first][initial->second]),
              m_goal_state(m_Matrix[goal->first][goal->second]) {};


    virtual State *getGoalState() {
        return m_goal_state;
    }

    virtual State *getInitialState() override {
        return m_initial_state;
    }

    virtual std::vector<State *> getAllPossibleStates(int i, int j) override {
        std::vector<State *> listOfStates;

        int jSize = m_Matrix[0].size() - 1;
        int iSize = m_Matrix.size() - 1;

        if (i > 0 && i <= iSize) {
            listOfStates.push_back(m_Matrix[i - 1][j]);
        }
        if (i >= 0 && i < iSize) {
            listOfStates.push_back(m_Matrix[i + 1][j]);
        }
        if (j > 0 && j <= jSize) {
            listOfStates.push_back(m_Matrix[i][j - 1]);
        }
        if (j >= 0 && j < jSize) {
            listOfStates.push_back(m_Matrix[i][j + 1]);
        }
        return listOfStates;
    }

    void resetVisited() {
        for(std::vector<State*> v : m_Matrix){
            auto vecSet = [](std::vector<State*>& v) {std::for_each(v.begin(),v.end(),set) ;};
            std::for_each(v.begin(),v.end(), set);
        }
    }
};

#endif //S_O_L_I_D_MATRIXSEARCHER_H
