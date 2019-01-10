//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_MYTESTCLIENTHANDLER_H
#define S_O_L_I_D_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Input/Solver.h"
#include "CacheManager.h"
#include <unistd.h>
#include <string>
#include <cstring>

#define MAXPACKETSIZE 1024
namespace server_side {
    class MyTestClientHandler : public ClientHandler {
    public:
        void handleClient(int sockID) override;

    private:
        Solver<std::string, std::string> *solver;
        CacheManager<std::string, std::string> *cache;

    };
}

#endif //S_O_L_I_D_MYTESTCLIENTHANDLER_H
