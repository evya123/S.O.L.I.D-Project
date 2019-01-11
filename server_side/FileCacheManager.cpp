//
// Created by lidor on 03/01/19.
//

#include "FileCacheManager.h"

bool server_side::FileCacheManager::isExist(const std::string &key) const {
    return m_cacheMap.find(key) != m_cacheMap.end() ? true : false;
}

std::pair<MatrixSearcher<MATRIX_DEF> *, std::string>
        server_side::FileCacheManager::getAnswer
                                                (const std::string &key) const {
    return m_cacheMap.find(key)->second;
}

bool server_side::FileCacheManager::addAnswerAndQuestion(const std::string &key,
                                                        const std::pair<MatrixSearcher<MATRIX_DEF> *,
                                                        std::string> &pair) {
    if (!isExist(key)) {
        m_cacheMap.insert({key, pair});
        return true;
    } else return false;
}

std::string server_side::FileCacheManager::returnAnswer(const std::string &question) const {
    return getAnswer(question).second;
}
