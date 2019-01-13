//
// Created by lidor115 on 1/13/19.
//

#ifndef S_O_L_I_D_ASTAR_H
#define S_O_L_I_D_ASTAR_H

#include <unordered_set>
#include "ISearcher.h"
#include "State.h"
#include "MyPriorityQueue.h"

class Astar : public ISearcher<State *> {
private:
    int numOfnodes;
    // priority queue
    MyPriorityQueue *open;
public:
    Astar() {
        numOfnodes = 0;
        open = new MyPriorityQueue();
    }

    std::string search(ISearchable<State *> *searchable) override {
        // set
        std::unordered_set<State *> close;
        // insert the initial state to the priority queue
        open->push_Priority_Queue(searchable->getInitialState());
        ++numOfnodes;
        // goal state
        State *goal = searchable->getGoalState();


    }

    int getNumberOfNodesEvaluated() override {
        return numOfnodes;
    }
};

#endif //S_O_L_I_D_ASTAR_H
