
#include "MyTestClientHandler.h"

void server_side::MyTestClientHandler::handleClient(int sockID) {
    int newsockfd = sockID;
    int n;
    char msg[MAXPACKETSIZE];
    while (true) {
        memset(msg, 0, MAXPACKETSIZE);
        n = read(newsockfd, msg, MAXPACKETSIZE);
        if (n == 0) {
            close(newsockfd);
            break;
        }
        //Lexer parser
    }
}
