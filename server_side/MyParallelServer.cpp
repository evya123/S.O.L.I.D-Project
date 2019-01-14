
#include "MyParallelServer.h"

void server_side::MyParallelServer::open(int port) {
    struct sockaddr_in serverAddr;

    if ((m_sockID = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == FAILD) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(m_sockID, SOL_SOCKET, SO_REUSEADDR, &sock_val,
                   sizeof(sock_val)) == FAILD) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    //Set all bits of the padding field to 0
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    if (bind(m_sockID, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == FAILD) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(m_sockID, QUEUE_SIZE) == FAILD) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

int server_side::MyParallelServer::acceptClient() {
    int newSocket;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size = sizeof(serverStorage);
    if (setsockopt (m_sockID, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
                    sizeof(timeout)) < 0)
        perror("setsockopt failed\n");
    newSocket = accept(m_sockID, (struct sockaddr *) &serverStorage, &addr_size);
    if (newSocket == FAILD){
        shutdown(m_sockID,SHUT_RDWR);
        perror("Timeout : ");
        return TIME_OUT;
    }
    return newSocket;
}

void server_side::MyParallelServer::stop() {
    if (shutdown(m_sockID, SHUT_RDWR) > 0) {
        perror("TcpServer->detach->shutdown 1: ");
    }
    sleep(1);
    if (close(m_sockID) > 0) {
        perror("TcpServer->detach->close 1: ");
    }
}

server_side::MyParallelServer::~MyParallelServer() {
    stop();
}
