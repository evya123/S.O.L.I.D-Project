//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_CACHEMANAGER_H
#define S_O_L_I_D_CACHEMANAGER_H

namespace server_side{
    template<class Question, class Answer>
    class CacheManager {

    public:
        virtual bool isExist(const Question& item)= 0;

        virtual Answer getAnswer(const Question &question) const = 0;

        virtual bool addAnswerAndQuestion(const Question& question, const Answer& answer) = 0;

        virtual ~CacheManager(){};
    };
}

#endif //S_O_L_I_D_CACHEMANAGER_H
