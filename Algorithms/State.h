//
// Created by lidor on 08/01/19.
//

#ifndef S_O_L_I_D_STATE_H
#define S_O_L_I_D_STATE_H

/**
 * State - with cost and the prev State (cameFrom)
 * @tparam T type of the State
 */
template<class T>
class State {
private:
    T m_state;
    double m_cost;
    State *m_cameFrom;
public:
    State(T s) : m_state(s) {};

    void setCost(double c) {
        m_cost = c;
    }

    void setCameFrom(State *st) {
        m_cameFrom = st;
    }
};


#endif //S_O_L_I_D_STATE_H
