
#include "MyParallelServer.h"

void server_side::MyParallelServer::open(int port, ClientHandler* clientHandler) {
    if ((m_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(m_serverSocket, SOL_SOCKET, SO_REUSEADDR, &sock_val,
                   sizeof(sock_val))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    m_server.sin_family = AF_INET;
    m_server.sin_addr.s_addr = INADDR_ANY;
    m_server.sin_port = htons(port);

    // Forcefully attaching socket to the port 8080
    if (bind(m_serverSocket, (struct sockaddr *) &m_server, sizeof(m_server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(m_serverSocket, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

void server_side::MyParallelServer::accept() {
    //TODO
}

void server_side::MyParallelServer::stop() {
    //TODO
}
