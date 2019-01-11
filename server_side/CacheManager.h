//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_CACHEMANAGER_H
#define S_O_L_I_D_CACHEMANAGER_H

template<class Question, class Answer>
class CacheManager {

public:
    virtual bool isExist(const Question item) const = 0;

    virtual Answer getAnswer(Question question) = 0;

    virtual bool addAnswerAndQuestion(Question question, Answer answer) = 0;
};

#endif //S_O_L_I_D_CACHEMANAGER_H
