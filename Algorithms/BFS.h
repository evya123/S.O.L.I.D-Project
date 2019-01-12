//
// Created by lidor115 on 1/11/19.
//

#ifndef S_O_L_I_D_BFS_H
#define S_O_L_I_D_BFS_H

#include <queue>

template<class T, class S>
class BFS : public ISearcher<T> {
private:
    int m_numOfNodes;
public:
    BFS() {
        m_numOfNodes = 0;
    }

    std::string search(ISearchable<T> *searchable) override {
        std::queue<State<T> *> queue;
        State<T> *current = searchable->getInitialState();
        State<T> *end = searchable->getGoalState();
        if (current != nullptr && current->getCost() > 0) {
            ++m_numOfNodes;
            queue.push(current);
        }
        std::vector<State<T> *> neighbors;
        while (!queue.empty()) {


        }

    }

    int getNumberOfNodesEvaluated() override {
        return m_numOfNodes;
    }

};

#endif //S_O_L_I_D_BFS_H
