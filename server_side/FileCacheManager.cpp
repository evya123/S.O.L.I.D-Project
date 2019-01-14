//
// Created by lidor on 03/01/19.
//

#include "FileCacheManager.h"
std::mutex m_lock;


bool server_side::FileCacheManager::addAnswerAndQuestion(const std::string &key, const std::vector<std::string>& value) {
    if (isExist(key)) return false;
    std::unique_lock<std::mutex> lock(m_lock);
    m_cacheMap.insert({key, value});
    return true;
}


bool server_side::FileCacheManager::isExist(const std::string &key) const {
    std::unique_lock<std::mutex> lock(m_lock);
    return m_cacheMap.find(key) != m_cacheMap.end() ? true : false;
}

std::vector<std::string> server_side::FileCacheManager::getAnswer
                                                (const std::string &key) const {
    std::unique_lock<std::mutex> lock(m_lock);
    return m_cacheMap.find(key)->second;
}

server_side::FileCacheManager::~FileCacheManager() {

}

