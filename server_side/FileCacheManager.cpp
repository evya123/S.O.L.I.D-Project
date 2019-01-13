//
// Created by lidor on 03/01/19.
//

#include "FileCacheManager.h"

bool server_side::FileCacheManager::addAnswerAndQuestion(const std::string &key, const std::string &value) {
    if (isExist(key)) return false;
    m_cacheMap.insert({key, value});
    return true;
}


bool server_side::FileCacheManager::isExist(const std::string &key) const {
    return m_cacheMap.find(key) != m_cacheMap.end() ? true : false;
}

std::string server_side::FileCacheManager::getAnswer
                                                (const std::string &key) const {
    return m_cacheMap.find(key)->second;
}
