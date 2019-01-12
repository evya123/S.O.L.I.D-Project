//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_FILECACHEMANAGER_H
#define S_O_L_I_D_FILECACHEMANAGER_H

#include <string>
#include <unordered_map>
#include <Algorithms/MatrixSearcher.h>
#include "CacheManager.h"

#define MATRIX_DEF State*

namespace server_side {
    class FileCacheManager
            : public CacheManager<std::string, std::pair<MatrixSearcher *,
                    std::string>> {
    private:
        std::unordered_map<std::string, std::pair<MatrixSearcher *, std::string>> m_cacheMap;
        std::pair<MatrixSearcher *, std::string>
        getAnswer(const std::string &question) const override;

    public:
        std::string returnAnswer(const std::string &question) const;

        bool isExist(const std::string &item) const override;

        bool addAnswerAndQuestion(const std::string &question,
                                  const std::pair<MatrixSearcher *, std::string> &answer) override;
    };
}


#endif //S_O_L_I_D_FILECACHEMANAGER_H
