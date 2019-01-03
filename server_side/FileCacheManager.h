//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_FILECACHEMANAGER_H
#define S_O_L_I_D_FILECACHEMANAGER_H

#include <string>
#include <unordered_map>

#include "CacheManager.h"

class FileCacheManager : public CacheManager<std::string, std::string> {
private:
    std::unordered_map<std::string, std::string> m_cacheMap;
public:
    bool isItem(const std::string &item) const override;

    std::string getAnswer(std::string question) override;

    bool addAnswerAndQuestion(std::string question, std::string answer) override;


};


#endif //S_O_L_I_D_FILECACHEMANAGER_H
