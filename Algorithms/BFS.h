//
// Created by lidor115 on 1/11/19.
//

#ifndef S_O_L_I_D_BFS_H
#define S_O_L_I_D_BFS_H

#include <queue>

template<class T>
class BFS : public ISearcher<T> {
private:
    int m_numOfNodes;
public:
    BFS() {
        m_numOfNodes = 0;
    }

    std::string search(ISearchable<T> *searchable) override {
        std::queue<State *> queue;
        State *current = searchable->getInitialState();
        State *end = searchable->getGoalState();
        if (current != nullptr && current->getCost() > 0) {
            ++m_numOfNodes;
        }
        std::vector<State *> neighbors;
        while (!queue.empty()) {
            if (current == end) {
                break;
            }
            current = queue.front();
            queue.pop();
            neighbors = searchable->getAllPossibleStates(current->getPlace()
                                                                 .first,
                                                         current->getPlace().second);
            State *tmp;
            for (int k = 0; k < neighbors.size(); ++k) {
                tmp = neighbors[k];
                if (tmp->getCost() != -1) {
                    queue.push(tmp);
                    tmp->setCameFrom(current);
                    tmp->setVisit(true);
                }
            }
            ++m_numOfNodes;
        }
    }

    int getNumberOfNodesEvaluated() override {
        return m_numOfNodes;
    }

};

#endif //S_O_L_I_D_BFS_H
