#include <iostream>
#include "PolishNotation.h"
#include <string>

int main() {
    std::cout << "Enter expression" << std::endl;
    std::string str;
    getline(std::cin, str);

    PolishNotation a;
    std::cout << "if you compare expression, it return 1 when its true, 0 when its false\n Result :"
              << a.CalcExpression(str);
    return 0;
}
