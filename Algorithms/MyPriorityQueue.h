//
// Created by lidor115 on 1/13/19.
//

#ifndef S_O_L_I_D_MYPRIORITYQUEUE_H
#define S_O_L_I_D_MYPRIORITYQUEUE_H

#include "State.h"
#include <functional>
#include <queue>
#include <vector>

class CompareStates {
public:
    bool operator()(const State *left, const State *right) {
        return left->getPathCost() > right->getPathCost();
    }
};

class MyPriorityQueue {
private:
    std::priority_queue<State *, std::vector<State *>, CompareStates>
            m_priorityQueue;
unsigned long QueueSize(){
    return m_priorityQueue.size();
}

State* PoP_Priority_Queue()

};

#endif //S_O_L_I_D_MYPRIORITYQUEUE_H
