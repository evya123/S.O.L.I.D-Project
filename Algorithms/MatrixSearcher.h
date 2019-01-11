//
// Created by lidor on 10/01/19.
//

#ifndef S_O_L_I_D_MATRIXSEARCHER_H
#define S_O_L_I_D_MATRIXSEARCHER_H


#include <vector>
#include "ISearchable.h"
#include "State.h"

#define PAIR std::pair<int,int>

class MatrixSearcher : public ISearchable<State<PAIR>> {
private:
    std::vector<std::vector<State<PAIR>*>> m_Matrix;
    State<PAIR>* m_initial_state;
    State<PAIR>* m_goal_state;
public:
    MatrixSearcher(std::vector<std::vector<State<PAIR>*>>& matrix,
                   State<PAIR>* initial,
                   State<PAIR>* goal) : m_initial_state(initial),
                                        m_goal_state(goal) {
        m_Matrix = matrix;
    }

    virtual State<PAIR > getGoalState();

    State<PAIR > getInitialState() override;
    virtual std::vector<State<PAIR>> getAllPossibleStates(State<PAIR> t);
};


#endif //S_O_L_I_D_MATRIXSEARCHER_H
