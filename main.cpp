#include <thread>
#include <string>
#include <stack>
#include <Input/LexerParser.h>

#define PAIR std::pair<int,int>

int main(int argc, char *argv[]) {

    std::string check = argv[1];
    LexerParser *lxpar = new LexerParser();
    std::vector<std::vector<State<PAIR > *>> result;
    int i = 0;
    while (check != "end") {
        result.push_back(lxpar->LexerMatrix(check, i));
        ++i;
    }

    return 0;
}