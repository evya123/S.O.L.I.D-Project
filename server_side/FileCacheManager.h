//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_FILECACHEMANAGER_H
#define S_O_L_I_D_FILECACHEMANAGER_H

#include <string>
#include <unordered_map>
#include "../Algorithms/MatrixSearcher.h"
#include <mutex>
#include "CacheManager.h"


namespace server_side {
    class FileCacheManager
            : public CacheManager<std::string,std::vector<std::string>> {
    private:
        std::unordered_map<std::string,std::vector<std::string>> m_cacheMap;
    public:

        std::vector<std::string> getAnswer(const std::string &question) const override;

        bool isExist(const std::string &item) override;

        bool addAnswerAndQuestion(const std::string &question, const std::vector<std::string>& value) override;

        bool saveToFile(const std::string &cacheFileName);

        bool loadFromFile(const std::string &cacheFileName, FileCacheManager* f);

        ~FileCacheManager() override;
    };
}


#endif //S_O_L_I_D_FILECACHEMANAGER_H