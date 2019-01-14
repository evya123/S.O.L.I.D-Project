//
// Created by evya on 1/11/19.
//

#ifndef S_O_L_I_D_PROJECT_DFS_H
#define S_O_L_I_D_PROJECT_DFS_H

#include "ISearcher.h"
#include "State.h"
#include <list>
#include "AlgoUtils.h"
#include <queue>

class DFS : public ISearcher<State*>{
public:
    DFS(){m_numOfNodes = -1;};
    void DepthFirstSearch(State *start, State *target, ISearchable<State *> &searchable);
    std::string search(ISearchable<State*>& searchable) override;

    int getNumberOfNodesEvaluated() override;

    ~DFS() override {

    }

private:
    std::queue<State*> fromVecToQueue(State *root, std::vector<State *> &toBeCleared);
    int m_numOfNodes;

};


#endif //S_O_L_I_D_PROJECT_DFS_H
