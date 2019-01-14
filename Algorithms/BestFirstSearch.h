//
// Created by lidor115 on 1/13/19.
//

#ifndef S_O_L_I_D_BESTFIRSTSEARCH_H
#define S_O_L_I_D_BESTFIRSTSEARCH_H

#include "MyPriorityQueue.h"
#include "ISearcher.h"
#include "AlgoUtils.h"
#include <unordered_set>

class CompareStates {
public:
    bool operator()(const State *left, const State *right) {
        return left->getPathCost() > right->getPathCost();
    }
};


class BestFirstSearch : public ISearcher<State *> {
private:
    int numOfnodes;
    // priority queue
    MyPriorityQueue<CompareStates> *open;

public:

    BestFirstSearch() {
        open = new MyPriorityQueue<CompareStates>();
        numOfnodes = 0;
    }

    std::string search(ISearchable<State *> *searchable) override {
        // set
        std::unordered_set<State *> close;
        // insert the initial state to the priority queue
        open->push_Priority_Queue(searchable->getInitialState());
        ++numOfnodes;
        // goal state
        State *goal = searchable->getGoalState();
        // tmp - to iterate the priority queue
        State *father;

        while (!open->isEmpty_Priority_Queue()) {
            // take from the priority queue the min
            father = open->Pop_Priority_Queue();
            // insert to the set the minimum
            close.insert(father);
            // if finds the goal - return and break.
            if (father == goal) {
                //need to save to a vector and to sum the shortest path
                return AlgoUtils<State *>::printPath(
                        searchable->getInitialState(),
                        goal);
            }
            // the neighbors of each state
            State *neigh;
            std::vector<State *> neighbors = searchable->getAllPossibleStates
                    (father->getPlace().first, father->getPlace().second);
            double pathCost;
            for (int k = 0; k < neighbors.size(); ++k) {
                /**
                * for each neighbor that that not in open and not in close:
                * 1. update his father to tmp
                * 2. add the neighbor to "open" (MyPriorityQueue)
                */
                neigh = neighbors[k];
                if (neigh->getCost() == -1) {
                    continue;
                }
                pathCost = father->getPathCost() + neigh->getCost();
                if (!open->isInPriorityQueue(neigh) && close.find(neigh) ==
                                                       close.end()) {
                    neigh->setCameFrom(father);
                    neigh->setPathCost(pathCost);
                    open->push_Priority_Queue(neigh);
                    ++numOfnodes;
                }
                    /**
                     * else:
                     * 1. if not in "open" (MyPriorityQueue) - add to open
                     *  else:
                     *    1.update the priority of neigh
                     */
                else if (pathCost < neigh->getPathCost()) {
                    // if its not in "open"
                    if (!open->isInPriorityQueue(neigh)) {
                        open->push_Priority_Queue(neigh);
                        ++numOfnodes;
                        // if it's in "open"
                    } else {
                        open->Update_Priority_Queue(neigh, father);
                    }
                }

            }
        }

    }


    int getNumberOfNodesEvaluated()

    override {
        return
                numOfnodes;
    }

    ~BestFirstSearch() {
        delete (open);
    }

};

#endif //S_O_L_I_D_BESTFIRSTSEARCH_H
