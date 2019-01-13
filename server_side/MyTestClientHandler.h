//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_MYTESTCLIENTHANDLER_H
#define S_O_L_I_D_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Input/Solver.h"
#include "server_side/CacheManager.h"
#include "server_side/FileCacheManager.h"
#include <unistd.h>
#include <string>
#include <cstring>
#include "Input/SolverSearcher.h"
#include "FileCacheManager.h"
#include "Algorithms/MatrixSearcher.h"
#include "Input/LexerParser.h"
#include "Algorithms/BFS.h"

#define MAXPACKETSIZE 1024
namespace server_side {
    class MyTestClientHandler : public ClientHandler {
    public:
        MyTestClientHandler() {
            m_solver = new SolverSearcher();
            //m_cache = new FileCacheManager();
            m_lexer = new LexerParser();
        };

        void handleClient(int sockID) override;

    private:
        Solver<MatrixSearcher *, std::vector<std::string>> *m_solver;
        //CacheManager<std::string, std::pair<MatrixSearcher *, std::string>> *m_cache;
        LexerParser *m_lexer;
    };
}

#endif //S_O_L_I_D_MYTESTCLIENTHANDLER_H
