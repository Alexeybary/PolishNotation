//
// Created by Lenovo on 21.11.2020.
//

#ifndef POLISHNOTATION_POLISHNOTATION_H
#define POLISHNOTATION_POLISHNOTATION_H

#include <iostream>

#include <string>
#include <vector>
#include "stackList.h"
#include <sstream>
#include <cctype>

enum ItemType {
    NUMBER,
    SIGN
};


class NotationItem {
public:
    std::string value;
    ItemType type;
};

class PolishNotation {
public:
    double CalcExpression(const std::string &) const;

    QueueOnList<NotationItem> StrToPolish(std::string) const;

    double PolishToInt(const QueueOnList<NotationItem>) const;
};

int priority(std::string chr) {
    if (chr == "/" || chr == "*" || chr == "%")
        return 14;
    if (chr == "+" || chr == "-")
        return 13;
    if (chr == "<<" || chr == ">>")
        return 12;
    if (chr == "<=" || chr == ">=" || chr == "<" || chr == ">")
        return 11;
    if (chr == "==" || chr == "!=")
        return 10;
    if (chr == "&")
        return 9;
    if (chr == "^")
        return 8;
    if (chr == "|")
        return 7;
    if (chr == "&&")
        return 6;
    if (chr == "||")
        return 5;
    if (chr == "(")
        return 4;
    if (chr == "=")
        return 3;
}

double operation(double b, double a, std::string symbol) {
    if (symbol == "*")
        return b * a;
    if (symbol == "/") {
        try {
            if (a == 0) {
                throw std::exception();
            }
            return b / a;
        }
        catch (std::exception &e) {

            std::cout << e.what();
            abort();

        }
    }
    if (symbol == "+")
        return b + a;
    if (symbol == "-")
        return b - a;
    if (symbol == "%") {
        try {
            if (a == 0) {
                throw 1;
            }
            return (int) b % (int) a;
        }
        catch (int i) {
            std::cout << "error /0";
            abort();
        }
    }

    try {
        if ((int) a - a != 0 || (int) b - b != 0) {
            throw 1;
        }


        if (symbol == "&")
            return (int) b & (int) a;

        if (symbol == "^")
            return (int) b ^ (int) a;
        if (symbol == "|")
            return (int) b | (int) a;

        if (symbol == "<<")
            return (int) b << (int) a;
        if (symbol == ">>")
            return (int) b >> (int) a;
    }
    catch (int i) {
        std::cout << "error /0";
        abort();
    }

    if (symbol == "&&")
        return b && a;
    if (symbol == "||")
        return b || a;
    if (symbol == "<=")
        return b <= a;
    if (symbol == ">=")
        return b >= a;
    if (symbol == "<")
        return b < a;
    if (symbol == ">")
        return b > a;
    if (symbol == "==")
        return b == a;
    if (symbol == "!=")
        return b != a;
}


double PolishNotation::CalcExpression(const std::string &str) const {
    return PolishToInt(StrToPolish(str));
}

QueueOnList<NotationItem> PolishNotation::StrToPolish(std::string str) const {
    QueueOnList<NotationItem> queue;
    StackOnList<std::string> signs;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        if (std::isdigit(str[i])) {
            int temp_i = 0;
            NotationItem temp;
            temp.type = NUMBER;
            if (i > 1)
                if ((str[i - 1] == '-') && (str[i - 2] == '('))
                    temp.value += str[i - 1];

            while (std::isdigit(str[i]) || str[i] == '.') {
                temp.value += str[i];
                i++;
                temp_i++;
            }
            queue.push(temp);

        } else if (str[i] == ')') {
                try {
                    if (signs.isEmpty()) {
                        throw 2;
                    }



            while (signs.Top()->value != "(") {
                NotationItem temp;
                temp.type = SIGN;
                temp.value = signs.Pop();
                queue.push(temp);
                try {
                    if (signs.isEmpty()) {
                        throw 2;
                    }}    catch (int i) {
                    std::cout << "error invalid syntax";
                    abort();
                }

            }
            signs.Pop();
            i++;}
                    catch (int i) {
                        std::cout << "error invalid syntax";
                        abort();
                    }
        } else {
            if (str[i] == '-' && str[i - 1] == '(') {
                i++;
                continue;
            }
            std::string temp;
            temp = str[i];

            if ((str[i] == '<' || str[i] == '>' || str[i] == '=' || str[i] == '&' || str[i] == '!' ||
                 str[i + 1] == '|') && (str[i + 1] == '<' || str[i + 1] == '>' || str[i + 1] == '=' ||
                                        str[i + 1] == '&' || str[i + 1] == '|')) {
                temp += str[i + 1];
                i += 2;
            } else i++;
            if (signs.isEmpty()) {
                signs.push(temp);
            } else if (priority(signs.Top()->value) < priority(temp) || (temp == "(")) {
                signs.push(temp);
            } else {
                while (signs.Top()->value != "(") {
                    NotationItem temp;
                    temp.type = SIGN;
                    temp.value = signs.Pop();
                    queue.push(temp);
                    if (signs.isEmpty())
                        break;
                }
                signs.push(temp);
            }
        }
    }
    return queue;
}

double PolishNotation::PolishToInt(const QueueOnList<NotationItem> queue) const {
    StackOnList<NotationItem> Result;
    double sum = 0;
    QueueOnList<NotationItem> queue1 = queue;
    while (!queue1.isEmpty()) {
        while (queue1.Top()->value.type != SIGN) {
            Result.push(queue1.Pop());
        }
        double a, b;
        try {
            if (Result.isEmpty()) {
                throw 1;
            }

            std::istringstream ist(Result.Pop().value);
            ist >> a;
            if (Result.isEmpty()) {
                throw 1;
            }
            std::istringstream ist2(Result.Pop().value);
            ist2 >> b;
            if (queue1.isEmpty()) {
                throw 1;
            }
            std::string symbol = queue1.Pop().value;
            sum = operation(b, a, symbol);
            std::ostringstream stream;
            stream << sum;
            std::string stringSum = stream.str();
            NotationItem c;
            c.value = stringSum;
            c.type = NUMBER;
            Result.push(c);
        }

    catch (int i) {
        std::cout << "invalid sentax";
        abort();
    }
    }
    return sum;
}

#endif //POLISHNOTATION_POLISHNOTATION_H
