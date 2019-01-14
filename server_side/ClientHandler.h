//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_CLIENTHANDLER_H
#define S_O_L_I_D_CLIENTHANDLER_H

#include <iostream>
#include <fstream>
namespace server_side {
    class ClientHandler {
    public:
        virtual void handleClient(int sockID) = 0;

        virtual ~ClientHandler(){};
    };
}
#endif //S_O_L_I_D_CLIENTHANDLER_H
