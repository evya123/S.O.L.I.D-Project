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

bool server_side::FileCacheManager::saveToFile(const std::string &cacheFileName) {
    std::ofstream ofile;
    ofile.open(cacheFileName.c_str());
    std::ofstream solutionFile;
    if (!ofile)
        return false;           //file does not exist and cannot be created.
    auto iter = m_cacheMap.begin();
    for (iter; iter != m_cacheMap.end(); ++iter) {
        ofile << iter->first << "\n"<<"Solution\n";
        for (std::string s : iter->second)
            ofile<<s;
        ofile<<"End"<<std::endl;
    }
    ofile.close();
    return true;
}

bool server_side::FileCacheManager::loadFromFile(const std::string &cacheFileName, FileCacheManager* f) {
    std::ifstream ifile;
    try {
        ifile.open(cacheFileName);
    }
    catch (const std::ifstream::failure &e) {
        std::cerr << "Exception opening/reading file";
    }
    std::string line;
    std::string key;
    std::string buff;
    std::vector<std::string> value;
    while (std::getline(ifile,line)){
        if(line == "Solution"){
            while (line != "End"){
                std::getline(ifile,line);
                if(line == "End")
                    continue;
                value.emplace_back(line+"\n");
            }
            f->addAnswerAndQuestion(key,value);
            key.clear();
            value.clear();
        } else {
            key += line+"\n";
        }
    }
    ifile.close();
    return true;
}
