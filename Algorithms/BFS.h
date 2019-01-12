//
// Created by lidor115 on 1/11/19.
//

#ifndef S_O_L_I_D_BFS_H
#define S_O_L_I_D_BFS_H

#include <queue>


class BFS : public ISearcher<State *> {
private:
    int m_numOfNodes;
public:
    BFS() {
        m_numOfNodes = 0;
    }

    std::string search(ISearchable<State *> *searchable) override {

        std::vector<State *> path;
        std::queue<State *> queue;
        State *current = searchable->getInitialState();
        State *end = searchable->getGoalState();
        if (current->getPlace().first != -1 && current->getCost() >= 0) {
            current->setVisit(true);
            queue.push(current);
        }
        std::vector<State *> neighbors;
        while (!queue.empty()) {
            current = queue.front();
            queue.pop();
            if (current == end) {
                break;
            }
            neighbors = searchable->getAllPossibleStates(current->getPlace()
                                                                 .first,
                                                         current->getPlace()
                                                                 .second);
            State *tmp;
            for (int k = 0; k < neighbors.size(); ++k) {
                tmp = neighbors[k];
                if (tmp->getCost() != -1 && !tmp->isVisit()) {
                    if (tmp == end) {
                        tmp->setCameFrom(current);
                        tmp->setVisit(true);
                        ++m_numOfNodes;
                        current = tmp;
                        while (!queue.empty()) {
                            queue.pop();
                        }
                        break;
                    }
                    queue.push(tmp);
                    tmp->setCameFrom(current);
                    tmp->setVisit(true);
                }
            }

            ++m_numOfNodes;
        }
        /// print path
        std::string res = "";
        State *tmp1 = current;
        int i1;
        int i2;
        int j1;
        int j2;
        std::cout << tmp1->getCost() << std::endl;
        i1 = tmp1->getPlace().first;
        i2 = tmp1->getCameFrom()->getPlace().first;
        j1 = tmp1->getPlace().second;
        j2 = tmp1->getCameFrom()->getPlace().second;
        if (j1 == j2) {
            i1 > i2 ? res = ", Down " + res : res = ", UP " + res;
        } else {
            j1 > j2 ? res = ", Right " + res : res = ", Left " + res;
        }
        tmp1 = tmp1->getCameFrom();
        while (tmp1 != searchable->getInitialState()) {
            std::cout << tmp1->getCost() << std::endl;
            i1 = tmp1->getPlace().first;
            i2 = tmp1->getCameFrom()->getPlace().first;
            j1 = tmp1->getPlace().second;
            j2 = tmp1->getCameFrom()->getPlace().second;
            if (j1 == j2) {
                i1 > i2 ? res = ", Down " + res : res = ", UP " + res;
            } else {
                j1 > j2 ? res = ", Right " + res : res = ", Left " + res;
            }
            tmp1 = tmp1->getCameFrom();
        }
        res.erase(0, 2);
        std::cout << res << std::endl;


        return "res";
    }

    int getNumberOfNodesEvaluated() override {
        return m_numOfNodes;
    }

};

#endif //S_O_L_I_D_BFS_H
