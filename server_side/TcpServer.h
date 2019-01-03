
#ifndef UAV_PROJECT_TCPSERVER_H
#define UAV_PROJECT_TCPSERVER_H
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstdio>

#define MAXPACKETSIZE 256

class TcpServer {
public:
    TcpServer() = default;

    int setup(int port);

  //  int receive();

    void detach();



private:
    int m_serverSocket, m_accVal;
    struct sockaddr_in m_serverAddress;
    struct sockaddr_in m_clientAddress;
};

#endif //UAV_PROJECT_TCPSERVER_H
