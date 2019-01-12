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
    BFS(){
        m_numOfNodes = 0;
    }

    std::string search(ISearchable<T> *searchable) override {
        return std::__cxx11::string();
    }

    int getNumberOfNodesEvaluated() override {
        return m_numOfNodes;
    }

};

#endif //S_O_L_I_D_BFS_H
