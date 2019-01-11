//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_MYTESTCLIENTHANDLER_H
#define S_O_L_I_D_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Input/Solver.h"
#include "CacheManager.h"
#include <unistd.h>
#include <string>
#include <cstring>
#include <Input/SolverSearcher.h>
#include "Input/LexerParser.h"
#include "FileCacheManager.h"

#define MAXPACKETSIZE 1024
namespace server_side {
    class MyTestClientHandler : public ClientHandler {
    public:
        MyTestClientHandler() { m_lexer = new LexerParser();
                                m_solver = new SolverSearcher();
                                m_cache = new FileCacheManager();};
        void handleClient(int sockID) override;
    private:
        Solver<MatrixSearcher*, std::string> *m_solver;
        CacheManager<MatrixSearcher*, std::string> *m_cache;
        LexerParser* m_lexer;
    };
}

#endif //S_O_L_I_D_MYTESTCLIENTHANDLER_H
