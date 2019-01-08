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
        virtual void handleClient(std::ofstream inputstream, std::ostream outputStream) = 0;
    };
}
#endif //S_O_L_I_D_CLIENTHANDLER_H
