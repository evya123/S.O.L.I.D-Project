//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_FILECACHEMANAGER_H
#define S_O_L_I_D_FILECACHEMANAGER_H

#include <string>
#include <unordered_map>
#include <Algorithms/MatrixSearcher.h>
#include "CacheManager.h"
namespace server_side {
    class FileCacheManager : public CacheManager<MatrixSearcher*, std::string> {
    private:
        std::unordered_map<MatrixSearcher*, std::string> m_cacheMap;
    public:
        bool isExist(MatrixSearcher *const item) const override;

        std::string getAnswer(MatrixSearcher* question) override;

        bool addAnswerAndQuestion(MatrixSearcher*, std::string answer) override;


    };
}


#endif //S_O_L_I_D_FILECACHEMANAGER_H
