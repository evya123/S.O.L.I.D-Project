//
// Created by lidor on 03/01/19.
//

#include "FileCacheManager.h"
std::mutex m_locker;

bool server_side::FileCacheManager::addAnswerAndQuestion(const std::string &key, const std::vector<std::string>& value) {
    if (isExist(key)) return false;
    std::unique_lock<std::mutex> lock(m_locker);
    m_cacheMap.insert({key, value});
    return true;
}


bool server_side::FileCacheManager::isExist(const std::string &key){
    std::unique_lock<std::mutex> lock(m_locker);
    bool ret = m_cacheMap.find(key) != m_cacheMap.end() ? true : false;
    return ret;
}

std::vector<std::string> server_side::FileCacheManager::getAnswer
                                                (const std::string &key) const {
    std::unique_lock<std::mutex> lock(m_locker);
    return m_cacheMap.find(key)->second;
}

server_side::FileCacheManager::~FileCacheManager() {

}
