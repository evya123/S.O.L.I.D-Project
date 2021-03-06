
#ifndef SOLID_MYSERIALSERVER_H
#define SOLID_MYSERIALSERVER_H

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#define TIME_OUT -5
#define FAILD -1
#define QUEUE_SIZE 50

const int sock_val = 1;

namespace server_side {
    class MyParallelServer : public Server {
    public:
        MyParallelServer(){
            timeout.tv_sec = 10;
            timeout.tv_usec = 0;
        }
        void open(int port) override;

        int acceptClient() override;

        void stop() override;


        ~MyParallelServer() override;

    private:
        timeval timeout;
        int m_sockID;
    };
}

#endif //SOLID_MYSERIALSERVER_H
