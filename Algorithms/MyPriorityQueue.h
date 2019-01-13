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

    unsigned long QueueSize() {
        return m_priorityQueue.size();
    }

    State *Pop_Priority_Queue() {
        State *tmpState = m_priorityQueue.top();
        m_priorityQueue.pop();
        return tmpState;
    }

    void push_Priority_Queue(State *newSt) {
        m_priorityQueue.push(newSt);
    }

    State *top_Priority_Queue() {
        return m_priorityQueue.top();
    }

    bool isEmpty_Priority_Queue() {
        return m_priorityQueue.empty();
    }

    bool isInPriorityQueue(State *st) {
        std::vector<State *> tmpVec;
        bool ret = false;
        while (!isEmpty_Priority_Queue()) {

        }
    }


    void Update_Priority_Queue(State *oldSt, State *newSt) {
        std::vector<State *> tmpVec;
        while (!isEmpty_Priority_Queue()) {
            // take the top and pop out from queue
            State *top = Pop_Priority_Queue();
            tmpVec.push_back(top);
            /**
             *if old is equals to  the current top, we set that top came from
             * the updated state and update the cost of the path to the state
             */
            if (oldSt->equals(top)) {
                top->setCameFrom(newSt);
                top->setPathCost(newSt->getPathCost() + oldSt->getPathCost());
                break;
            }
        }
        // return the states to the priority queue
        for(int i=0; i<tmpVec.size(); ++i){
            push_Priority_Queue(tmpVec[i]);
        }
    }


};

#endif //S_O_L_I_D_MYPRIORITYQUEUE_H
