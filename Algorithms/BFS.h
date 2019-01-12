//
// Created by lidor115 on 1/11/19.
//

#ifndef S_O_L_I_D_BFS_H
#define S_O_L_I_D_BFS_H

#include <queue>


class BFS : public ISearcher<State> {
private:
    int m_numOfNodes;
public:
    BFS() {
        m_numOfNodes = 0;
    }

    std::string search(ISearchable<State> *searchable) override {

        std::vector<State> path;
        std::queue<State> queue;
        State current = searchable->getInitialState();
        State end = searchable->getGoalState();
        if (current.getPlace().first != -1 && current.getCost() > 0) {
            std::cout << " nodes : " << m_numOfNodes << " value : "
                      << current.getCost() << std::endl;
            current.setVisit(true);
            queue.push(current);
        }
        std::vector<State> neighbors;
        while (!queue.empty()) {
            current = queue.front();
            queue.pop();
            if (current == end) {
                break;
            }
            neighbors = searchable->getAllPossibleStates(current.getPlace()
                                                                 .first,
                                                         current.getPlace()
                                                                 .second);
            State *tmp;
            for (int k = 0; k < neighbors.size(); ++k) {
                *tmp = neighbors[k];
                std::cout << tmp->getCost() << " is neighbor of :" <<
                          current.getCost() << std::endl;
                if (tmp->getCost() != -1 && !tmp->isVisit()) {
                    queue.push(*tmp);
                    tmp->setCameFrom(&current);
                    tmp->setVisit(true);
                }
            }
            std::cout << " nodes : " << m_numOfNodes << " value : "
                      << current.getCost() << std::endl;

            ++m_numOfNodes;
        }
        return "manmanmanmaniak";
    }

    int getNumberOfNodesEvaluated() override {
        return m_numOfNodes;
    }

};

#endif //S_O_L_I_D_BFS_H
