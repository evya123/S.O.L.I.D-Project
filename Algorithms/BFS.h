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
        std::cout << " 0 " << std::endl;
        std::queue<State> queue;
        std::cout << " 1 " << std::endl;
        State current = searchable->getInitialState();
        std::cout << " 2 " << std::endl;
        State end = searchable->getGoalState();
        std::cout << " 3 " << std::endl;
        if (current.getPlace().first == -1 && current.getCost() > 0) {
            std::cout << " 4 " << std::endl;

            ++m_numOfNodes;
        }
        std::vector<State> neighbors;
        while (!queue.empty()) {
            if (current == end) {
                break;
            }
            current = queue.front();
            queue.pop();
            neighbors = searchable->getAllPossibleStates(current.getPlace()
                                                                 .first,
                                                         current.getPlace()
                                                                 .second);
            State *tmp;
            for (int k = 0; k < neighbors.size(); ++k) {
                *tmp = neighbors[k];
                if (tmp->getCost() != -1) {
                    queue.push(*tmp);
                    tmp->setCameFrom(&current);
                    tmp->setVisit(true);
                }
            }
            ++m_numOfNodes;
        }
        return "manmanmanmaniak";
    }

    int getNumberOfNodesEvaluated() override {
        return m_numOfNodes;
    }

};

#endif //S_O_L_I_D_BFS_H
