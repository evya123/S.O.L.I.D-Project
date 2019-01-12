//
// Created by lidor on 08/01/19.
//

#ifndef S_O_L_I_D_STATE_H
#define S_O_L_I_D_STATE_H

/**
 * State - with cost and the prev State (cameFrom)
 * @tparam T type of the State
 */
class State {
private:
    double m_cost;
    State *m_cameFrom;
    bool m_visit;
    // the place i,j
    std::pair<int, int> m_place;
public:
    std::pair<int, int> getPlace() {
        return m_place;
    }

    State(std::pair<int, int> ij) : m_place(ij) {
        m_visit = false;
    };

    void setCost(double c) {
        m_cost = c;
    }

    void setCameFrom(State *st) {
        m_cameFrom = st;
    }

    double getCost() const {
        return m_cost;
    }

    bool operator>(const State &st2) const {
        return (m_cost > st2.getCost());
    }

    bool operator<(const State &st2) {
        return (m_cost < st2.getCost());
    }

    bool operator==(const State &st2) {
        return (m_cost == st2.getCost());
    }

    void setVisit(bool visit) {
        m_visit = visit;
    }

};


#endif //S_O_L_I_D_STATE_H
