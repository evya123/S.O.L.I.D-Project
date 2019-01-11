//
// Created by lidor on 10/01/19.
//

#ifndef S_O_L_I_D_MATRIXSEARCHER_H
#define S_O_L_I_D_MATRIXSEARCHER_H


#include <vector>
#include "ISearchable.h"
#include "State.h"

template<class T>
class MatrixSearcher : public ISearchable<T> {
private:
    std::vector<std::vector<T>> m_Matrix;
    T m_initial_state;
    T m_goal_state;
public:

    MatrixSearcher(std::vector<std::vector<T>> matrix,
                   std::pair<int, int> *initial, std::pair<int, int> *goal) {
        m_Matrix = matrix;
        m_initial_state = m_Matrix[initial->first][initial->second];
        m_goal_state = m_Matrix[goal->first][goal->second];
    }

    virtual T getGoalState() {
        return m_goal_state;
    }

    T getInitialState() override {
        return m_initial_state;
    }

    std::vector<T> getAllPossibleStates(int i, int j) override {
        std::vector<T> listOfStates;
        int size = m_Matrix.size();
        if (i > 0 && i <= size) {
            listOfStates.push_back(m_Matrix[i - 1][j]);
        }
        if (i >= 0 && i < size) {
            listOfStates.push_back(m_Matrix[i + 1][j]);
        }
        if (j > 0 && j <= size) {
            listOfStates.push_back(m_Matrix[i][j - 1]);
        }
        if (j >= 0 && j < size) {
            listOfStates.push_back(m_Matrix[i][j + 1]);
        }
        return listOfStates;
    }

};


#endif //S_O_L_I_D_MATRIXSEARCHER_H
