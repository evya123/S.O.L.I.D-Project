//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_MYTESTCLIENTHANDLER_H
#define S_O_L_I_D_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include <string>

class MyTestClientHandler : public ClientHandler {
private:
    Solver<std::string, std::string>* solver;
    CacheManager<std::string, std::string>* cache;


};

#endif //S_O_L_I_D_MYTESTCLIENTHANDLER_H
