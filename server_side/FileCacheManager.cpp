//
// Created by lidor on 03/01/19.
//

#include "FileCacheManager.h"

bool server_side::FileCacheManager::addAnswerAndQuestion(std::string question,
                                            std::string answer) {
    if (isExist(question))
        return false; //pair is already exist
    m_cacheMap.insert(std::make_pair(question, answer));
    return true;
}

std::string server_side::FileCacheManager::getAnswer(std::string question) {
    return m_cacheMap.at(question);
}

bool server_side::FileCacheManager::isExist(const std::string &question) const {
    return !(m_cacheMap.find(question) == m_cacheMap.end());
}