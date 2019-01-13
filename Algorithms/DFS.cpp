
#include "DFS.h"

std::string DFS::search(ISearchable<State*> *searchable) {
    State* root = searchable->getInitialState();
    State* goal = searchable->getGoalState();
    m_numOfNodes = 0;
    DepthFirstSearch(root, goal, searchable);
    std::cout<<"----------- DONE -----------"<<std::endl;
    return AlgoUtils<State*>::printPath(root, goal);

}

void DFS::DepthFirstSearch(State *start, State *target, ISearchable<State *> *searchable) {
    if (!target->isVisit()){
        std::cout<<start->getCost()<<std::endl;
        start->setVisit(true);
        std::vector<State*> adjList = searchable->getAllPossibleStates(
                start->getPlace().first,
                start->getPlace().second);
        std::queue<State*> adjQueue = fromVecToQueue(start, adjList);
        while (!adjQueue.empty()){
            State* state = adjQueue.front();
            adjQueue.pop();
            if (!state->isVisit()){
                ++m_numOfNodes;
                state->setCameFrom(start); //set the father node
                DepthFirstSearch(state, target, searchable);
            }
        }
    }


}

std::queue<State*> DFS::fromVecToQueue(State *root, std::vector<State *> &toBeCleared){
    std::queue<State*> ret;
    for (State* tmp : toBeCleared){
        std::pair<int,int> rootPos = root->getPlace();
        std::pair<int,int> tmpPos = tmp->getPlace();
        if (rootPos.first > tmpPos.first){
            // removes all elements with the value of tmp
            continue;
        }else if (rootPos.second > tmpPos.second) {
            // removes all elements with the value of tmp
            continue;
        }
        ret.push(tmp);
    }
    return ret;
}

int DFS::getNumberOfNodesEvaluated() {
    return m_numOfNodes;
}
