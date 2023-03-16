/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:23:25 by pwolff            #+#    #+#             */
/*   Updated: 2023/03/10 10:23:25 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

enum {MULT=42, PLUS=43, MOIN=45, DIVI=47};

Rpn::Rpn() {
    //std::cout << "Constructor Rpn" << std::endl;
}

Rpn::~Rpn() {
    //std::cout << "Destructor Rpn" << std::endl;
}

void    Rpn::calcPolish(char *pol) {
    int result = 0;
    int nb = 0;
    int i = 0;

    std::string error = "\nError";
    std::string errorByZero = "\nError By Zero";

    while (pol[i])
    {
        if (pol[i] == ' ')
        {
            i++;
            continue;
        }
        if (!testAlpha(pol[i]) && !testOperation(pol[i]))
        {
            throw error;
        }
        if (testAlpha(pol[i]))
        {
            _datas.push(pol[i] - '0');
            i++;
            continue;
        }
        if (_datas.size() < 2)
            throw error;

        result = _datas.top();
        _datas.pop();
        nb = _datas.top();
        _datas.pop();

        switch(pol[i])
        {
            case PLUS :
                std::cout << YELLOW << nb << RED " + " CYANE << result << WHITE " = ";
                result = nb + result;
                std::cout << YELLOW << result << std::endl;
                _datas.push(result);
                i++;
                continue;
            case MOIN :
                std::cout << YELLOW << nb << RED " - " CYANE << result << WHITE " = ";
                result = nb - result;
                std::cout << YELLOW << result << std::endl;
                _datas.push(result);
                i++;
                continue;
            case MULT :
                std::cout << YELLOW << nb << RED " * " CYANE << result << WHITE " = ";
                result = nb * result;
                std::cout << YELLOW << result << std::endl;
                _datas.push(result);
                i++;
                continue;
            case DIVI :
                if (result == 0)
                    throw errorByZero;
                std::cout << YELLOW << nb << RED " / " CYANE << result << WHITE " = ";
                result = nb / result;
                std::cout << YELLOW << result << std::endl;
                _datas.push(result);
                i++;
                continue;
        }
    }
    if (_datas.size() == 1)
    {
        result = _datas.top();
        std::cout << GREEN << result << NONE << std::endl;
        _datas.pop();
        return;
    }
    result = _datas.top();
    std::cout << GREEN << result << NONE << std::endl;
    std::stack<int>   temp;
    while (!_datas.empty())
    {
        temp.push(_datas.top());
        _datas.pop();
    }
    std::cout << YELLOW << "Reste : ";
    while (!temp.empty())
    {
        std::cout << CYANE << temp.top() << " ";
        temp.pop();
    }
    std::cout << NONE << std::endl;
}

bool    Rpn::testAlpha(char alpha) const{
    if (alpha < '0' || alpha > '9')
        return false;
    return true;
}

bool    Rpn::testOperation(char alpha) const{
    if (alpha != '-' && alpha != '+' && alpha != '/' && alpha != '*')
        return false;
    return true;
}
