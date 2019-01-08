//
// Created by lidor on 03/01/19.
//

#ifndef S_O_L_I_D_STRINGREVERSER_H
#define S_O_L_I_D_STRINGREVERSER_H
#include "Solver.h"
#include <string>
#include <bits/stdc++.h>

class StringReverser : public Solver<std::string,std::string> {

    std::string solve(std::string problem) override;
};


#endif //S_O_L_I_D_STRINGREVERSER_H
