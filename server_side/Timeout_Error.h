//
// Created by evya on 1/8/19.
//

#ifndef S_O_L_I_D_TIMEOUT_ERROR_H
#define S_O_L_I_D_TIMEOUT_ERROR_H

#include <stdexcept>

using namespace std;

class Timeout_Error : public runtime_error{
    explicit Timeout_Error (const string& what_arg)
        : runtime_error(what_arg){}
    explicit Timeout_Error (const char* what_arg)
        : runtime_error(what_arg){}
};

#endif //S_O_L_I_D_TIMEOUT_ERROR_H
