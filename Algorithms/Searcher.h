//
// Created by lidor on 08/01/19.
//

#ifndef S_O_L_I_D_SEARCHER_H
#define S_O_L_I_D_SEARCHER_H


#include "ISearcher.h"
#include "State.h"
#include <string>

class Searcher : public ISearcher<std::string, State<std::pair<int, int >>> {
private:

};


#endif //S_O_L_I_D_SEARCHER_H
