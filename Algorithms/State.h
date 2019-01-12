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
    bool m_visit;
public:
    T getState() {
        return m_state;
    }

    State(T s) : m_state(s) {
        m_visit = false;
    };

    void setCost(double c) {
        m_cost = c;
    }

    void setCameFrom(State *st) {
        m_cameFrom = st;
    }

    State operator>(const State &st2) const {
        return (m_cost > st2.getCost());
    }

    State operator<(const State &st2) {
        return (m_cost < st2.getCost());
    }

    State operator==(const State &st2) {
        return (m_cost == st2.getCost());
    }

    double getCost() {
        return m_cost;
    }

    void setVisit(bool visit) {
        m_visit = visit;
    }


};


#endif //S_O_L_I_D_STATE_H
