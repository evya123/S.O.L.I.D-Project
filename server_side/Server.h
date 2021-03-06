//
// Created by lidor on 03/01/19.
//

#ifndef SOLID_SERVER_H
#define SOLID_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    class Server {
    public:
        virtual void open(int port) = 0;

        virtual int acceptClient() = 0;

        virtual void stop() = 0;

        virtual ~Server(){};
    };
};
#endif //SOLID_SERVER_H
