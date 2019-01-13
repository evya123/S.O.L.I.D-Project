//
// Created by lidor115 on 1/13/19.
//

#ifndef S_O_L_I_D_BESTFIRSTSEARCH_H
#define S_O_L_I_D_BESTFIRSTSEARCH_H

#include "MyPriorityQueue.h"
#include "ISearchable.h"
#include "ISearcher.h"

class BestFirstSearch : public ISearcher<State *> {
private:
    int numOfnodes = 0;
public:
    std::string search(ISearchable<State *> *searchable) override {
        MyPriorityQueue *open = new MyPriorityQueue();



    }

    int getNumberOfNodesEvaluated() override {
        return numOfnodes;
    }

};

#endif //S_O_L_I_D_BESTFIRSTSEARCH_H
