
#ifndef UAV_PROJECT_TCPSERVER_H
#define UAV_PROJECT_TCPSERVER_H
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstdio>

#define MAXPACKETSIZE 256

namespace server_side {
    class TcpServer {
    public:
        TcpServer() = default;

        int setup(int port);

        void detach();

    private:
        int m_serverSocket, m_accVal;
    };
}
#endif //UAV_PROJECT_TCPSERVER_H
