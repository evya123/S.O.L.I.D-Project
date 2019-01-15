//
// Created by lidor on 03/01/19.
//

#include <fstream>
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

bool server_side::FileCacheManager::saveToFile(const std::string &cacheFileName,const std::string &solutionFilename) {
    std::ofstream ofile;
    ofile.open(cacheFileName.c_str());
    std::ofstream solutionFile;
    solutionFile.open(solutionFilename.c_str());
    if (!ofile)
        return false;           //file does not exist and cannot be created.
    auto iter = m_cacheMap.begin();
    for (iter; iter != m_cacheMap.end(); ++iter) {
        ofile << iter->first << "\n";
        for(std::string v : iter->second){
            solutionFile<<v<<"\n";
        }
    }
    return true;
}

bool server_side::FileCacheManager::loadFromFile(const std::string &filename) {
    std::ifstream ifile;
    try {
        ifile.open(filename);
    }
    catch (const std::ifstream::failure &e) {
        std::cerr << "Exception opening/reading file";
    }
    std::string details;
    std::vector <std::string> v_str;
//    while (ifile >> details)
//        splitString(v_str, details, '|');
//    return v_str;
}
