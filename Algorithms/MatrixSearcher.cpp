//
// Created by lidor on 10/01/19.
//

#include "MatrixSearcher.h"

State<PAIR > MatrixSearcher::getGoalState() {
    return m_goal_state;
}

State<PAIR > MatrixSearcher::getInitialState() {
    return m_initial_state;
}

std::vector<State<PAIR>> MatrixSearcher::getAllPossibleStates(
        State<PAIR > t) {
    std::list<State<PAIR>> listOfStates;
    int i = t.getState().first;
    int j = t.getState().second;

}


