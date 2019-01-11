//
// Created by lidor on 10/01/19.
//

#include "MatrixSearcher.h"

State<std::pair<int, int>>* MatrixSearcher::getGoalState() {
    return m_goal_state;
}

State<std::pair<int, int>> * MatrixSearcher::getInitialState() {
    return m_initial_state;
}

std::vector<State<PAIR>*> MatrixSearcher::getAllPossibleStates(
        State<PAIR > t) {
    std::vector<State<PAIR>*> listOfStates;
    int i = t.getState().first;
    int j = t.getState().second;
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


