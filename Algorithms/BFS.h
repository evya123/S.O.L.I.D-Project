//
// Created by lidor115 on 1/11/19.
//

#ifndef S_O_L_I_D_BFS_H
#define S_O_L_I_D_BFS_H

#include <queue>
#include "Algorithms/AlgoUtils.h"

class BFS : public ISearcher<State *> {
private:
    int m_numOfNodes;
public:
    BFS() {
        m_numOfNodes = 0;
    }

    std::string search(ISearchable<State *> &searchable) override {
        m_numOfNodes = 0;
        // vector of all the states (
        std::vector<State *> allStates;
        // the queue
        std::queue<State *> queue;
        State *current = searchable.getInitialState();
        State *end = searchable.getGoalState();
        if (current->getPlace().first != -1 && current->getCost() >= 0) {
            current->setVisit(true);
            allStates.push_back(current);

            queue.push(current);
        }
        std::vector<State *> neighbors;
        while (!queue.empty()) {
            current = queue.front();
            queue.pop();
            ++m_numOfNodes;
            if (current == end) {
                break;
            }//takes all the neighbors
            neighbors = searchable.getAllPossibleStates(current->getPlace()
                                                                .first,
                                                        current->getPlace()
                                                                .second);
            State *tmp;
            for (int k = 0; k < neighbors.size(); ++k) {
                tmp = neighbors[k];
                if (tmp->getCost() != -1 && !tmp->isVisit()) {
                    if (tmp == end) {
                        tmp->setCameFrom(current);
                        end->setCameFrom(current);
                        tmp->setVisit(true);
                        allStates.push_back(tmp);
                        while (!queue.empty()) {
                            queue.pop();
                        }
                        break;
                    }
                    queue.push(tmp);
                    tmp->setCameFrom(current);
                    tmp->setVisit(true);
                    allStates.push_back(tmp);
                }
            }

        }
//printPath
        AlgoUtils<State *>::ShortestPath(searchable.getInitialState(),
                                         end);
        return AlgoUtils<State *>::printPath(searchable.getInitialState(),
                                             searchable.getGoalState());

    }

    int getNumberOfNodesEvaluated() override {
        return m_numOfNodes;
    }

    ~BFS() override {

    }

};

#endif //S_O_L_I_D_BFS_H
