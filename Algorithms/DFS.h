//
// Created by evya on 1/11/19.
//

#ifndef S_O_L_I_D_PROJECT_DFS_H
#define S_O_L_I_D_PROJECT_DFS_H

#include "ISearcher.h"
#include "State.h"

class DFS : public ISearcher<State>{
public:
    std::string search(ISearchable<State> *searchable) override;
};


#endif //S_O_L_I_D_PROJECT_DFS_H
