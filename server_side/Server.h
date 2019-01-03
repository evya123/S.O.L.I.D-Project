//
// Created by lidor on 03/01/19.
//

#ifndef SOLID_SERVER_H
#define SOLID_SERVER_H

#include "ClientHandler.h"

class Server {
    virtual void open(int port, ClientHandler clientHandler) = 0;

    virtual void stop() = 0;
};

#endif //SOLID_SERVER_H
