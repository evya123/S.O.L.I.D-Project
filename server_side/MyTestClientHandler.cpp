#include "MyTestClientHandler.h"

auto sendFunc = [](std::string& s, int newsockfd){
    ssize_t n;
    n = write(newsockfd,&s[POINTER_TO_STRING], s.size());
    s.clear();
    switch (n){
        case -1:
            perror("Couldn't write to client\n");
            exit(EXIT_FAILURE);
        default:;
    }
};

void server_side::MyTestClientHandler::handleClient(int sockID) {
    int newsockfd = sockID;
    ssize_t n;
    char line[MAXPACKETSIZE];
    std::string toMap;
    std::string smallBuff;
    do {
        smallBuff.clear();
        memset(line, 0, MAXPACKETSIZE);
        n = read(newsockfd, line, MAXPACKETSIZE);
        line[n] = 0;
        if (n == 0) {
            close(newsockfd);
            break;
        }
        toMap += line;
        smallBuff += line;
        if(smallBuff.empty())
            if (toMap.find("end") == std::string::npos)
                break;
            else
                std::cout<<"There is a problem"<<std::endl;
    } while(smallBuff.find("end") == std::string::npos);



    MatrixArgs args;
    bool sendToClient = true;
    if (m_cache->isExist(toMap)){
        std::vector<std::string> answer = m_cache->getAnswer(toMap);
        sendToClient = false;
        for(std::string s : answer){
            sendFunc(s,newsockfd);
        }
    }

    auto split  = [](const std::string & s,std::vector<std::string>& splittedVec,
                     const char delim){
        std::stringstream ss(s);
        std::string item;
        while(std::getline(ss, item, delim)) {
            splittedVec.emplace_back(item);
        }
        splittedVec.pop_back();
    };
    std::vector<std::string> buff;
    split(toMap,buff,'\n');

    if (sendToClient){
        args = m_lexer->FullLexer(buff);
        MatrixSearcher problem(args.matrix,args.startPos,args.goalPos);
        std::vector<std::string> solutions;
        solutions = m_solver->solve(problem);
        m_cache->addAnswerAndQuestion(toMap,solutions);
        for(std::string s : solutions){
            sendFunc(s,newsockfd);
        }
    }
}

server_side::MyTestClientHandler::~MyTestClientHandler() {
    delete m_solver;
    delete m_lexer;
}
