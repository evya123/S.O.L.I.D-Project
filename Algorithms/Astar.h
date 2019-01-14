//
// Created by lidor115 on 1/13/19.
//

#ifndef S_O_L_I_D_ASTAR_H
#define S_O_L_I_D_ASTAR_H

#include <unordered_set>
#include "ISearcher.h"
#include "State.h"
#include "MyPriorityQueue.h"
#include "AlgoUtils.h"

class CompareStatesAstar {
public:
    bool operator()(const State *left, const State *right) {
        return left->getCost() + left->getHeuristicCost() >
               right->getCost() + right->getHeuristicCost();
    }
};

class Astar : public ISearcher<State *> {
private:
    int numOfnodes;
    // priority queue
    MyPriorityQueue<CompareStatesAstar> *open;
public:
    Astar() {
        numOfnodes = 0;
        open = new MyPriorityQueue<CompareStatesAstar>();
    }

    std::string search(ISearchable<State *> &searchable) override {

        // set
        std::unordered_set<State *> close;
        // insert the initial state to the priority queue
        searchable.getInitialState()->setHeuristicCost(f_calc_hueristic
                                                               (searchable.getInitialState(),
                                                                searchable.getGoalState()));
        open->push_Priority_Queue(searchable.getInitialState());
        ++numOfnodes;
        // goal state
        State *goal = searchable.getGoalState();
        //heuristic Function
        double f;
        State *top;
        while (!open->isEmpty_Priority_Queue()) {
            // put the top in the Priority Queue
            top = open->Pop_Priority_Queue();
            f = f_calc_hueristic(top, goal);
            double cost = f + top->getPathCost();
            // if the top is the goal - send to the user
            if (top->equals(goal)) {
                return AlgoUtils<State *>::printPath(
                        searchable.getInitialState(),
                        goal);
            }

            // if not in close - continue
            if (close.find(top) != close.end()) {
                continue;
            } else {
                /**
                 * for each successor:
                 * 1. set path cost
                 * 2. set cameFrom to top
                 * 3. set his heuristic Cost
                 * 4. add to open
                 * 5.++num of nodes
                 */
                State *neigh;
                std::vector<State *> neighbors = searchable.getAllPossibleStates
                        (top->getPlace().first, top->getPlace().second);
                double pathCost;
                for (int k = 0; k < neighbors.size(); ++k) {
                    neigh = neighbors[k];
                    if (neigh->getCost() == -1) {
                        continue;
                    }
                    if (!open->isInPriorityQueue(neigh) && close.find(neigh) ==
                                                           close.end()) {
                        neigh->setPathCost(
                                top->getPathCost() + neigh->getCost());
                        neigh->setCameFrom(top);
                        neigh->setHeuristicCost(f_calc_hueristic(neigh, goal));
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
                            neigh->setHeuristicCost(
                                    f_calc_hueristic(neigh, goal));
                            open->push_Priority_Queue(neigh);
                            ++numOfnodes;
                            // if it's in "open"
                        } else {
                            neigh->setHeuristicCost(
                                    f_calc_hueristic(neigh, goal));
                            open->Update_Priority_Queue(neigh, top);
                        }
                    }

                }
                close.insert(top);
            }
        }
        return "-1";

    }


    int getNumberOfNodesEvaluated() override {
        return numOfnodes;
    }

    double f_calc_hueristic(State *current, State *goal) {
        int iCurrent = current->getPlace().first;
        int jCurrent = current->getPlace().second;
        int iGoal = goal->getPlace().first;
        int jGoal = goal->getPlace().second;
        // heuristic function
        double f = abs(iCurrent - iGoal) + abs(jCurrent - jGoal);
        return f;
    }

    ~Astar() override {
        delete open;
    }


};

#endif //S_O_L_I_D_ASTAR_H
