
#ifndef SOLID_MYSERIALSERVER_H
#define SOLID_MYSERIALSERVER_H

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>

#define FAILD 0
#define QUEUE_SIZE 50

const int sock_val = 1;

namespace server_side {
    class MyParallelServer : public Server {
    public:
        void open(int port, server_side::ClientHandler* clientHandler) override;

        int acceptClient() override;

        void stop() override;

    private:
        int m_sockID;
    };
}

#endif //SOLID_MYSERIALSERVER_H
