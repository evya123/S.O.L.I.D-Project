
#ifndef SOLID_MYSERIALSERVER_H
#define SOLID_MYSERIALSERVER_H

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
const int sock_val = 1;

namespace server_side {
    class MyParallelServer : public Server {
    public:
        void open(int port, server_side::ClientHandler* clientHandler) override;

        void accept() override;

        void stop() override;

    private:
        int m_serverSocket;
        struct sockaddr_in m_server;
    };
}

#endif //SOLID_MYSERIALSERVER_H
