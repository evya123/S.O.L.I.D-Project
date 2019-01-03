
#include "TcpServer.h"


/**
 * Function name: setup
 * @param port
 * @param ip
 * The function initialize the server arguments, create the socket,
 * bind the socket to the port and ip and the make the server
 * listen to the port and wait for connection.
 */
int TcpServer::setup(int port) {
    int opt = 1;
    struct sockaddr_in server, client;

    // Creating socket file descriptor
    if ((m_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(m_serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    // Forcefully attaching socket to the port 8080
    if (bind(m_serverSocket, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(m_serverSocket, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}