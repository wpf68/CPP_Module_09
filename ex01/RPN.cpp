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

Rpn::Rpn(char *argc) {
    std::cout << "Constructor Rpn" << std::endl;
    std::string temp = argc;

    //std::cout << "temp : --" << temp << "--" << std::endl;
    while (true)
    {
        std::size_t pos = temp.rfind(" ");
        if (pos == std::string::npos)
            break;
        std::string temp2 = temp.substr(pos + 1);
        _datas.push(temp2);
        temp.erase(pos);
    }
    _datas.push(temp);
}

Rpn::~Rpn() {
    std::cout << "Destructor Rpn" << std::endl;
}

std::stack<std::string> Rpn::getData() const {
    return _datas;
}

float Rpn::calcPolish() {
    float   result = 0;
    int     nb = 0;
    std::string error = "Error";
    std::string errorByZero = "\nError By Zero";

    testAlpha(_datas.top());
    result = static_cast<float>(atoi(_datas.top().c_str()));

    _datas.pop();
    while (!_datas.empty())
    {
        testAlpha(_datas.top());
        nb = atoi(_datas.top().c_str());
        
        _datas.pop();
        if (_datas.empty())
            throw error;

        testOperation(_datas.top());    
        std::cout << result << " " << _datas.top() << " " << nb << " = ";  // -- test
        if (_datas.top() == "-")
            result -= nb;
        else if (_datas.top() == "+")
            result += nb;
        else if (_datas.top() == "*")
            result *= nb;
        else if (_datas.top() == "/")
        {
            if (!nb)
                throw errorByZero;
            result /= nb;
        }
        else
            throw error;
        std::cout << result << std::endl;  //  test ---
        _datas.pop();

    }

    return result;
}

void    Rpn::testAlpha(std::string &alpha) const{
    std::string error = "Error";
    for (std::string::iterator it = alpha.begin(); it != alpha.end(); it++)
    {
        if (it != alpha.begin())
        {
            if (*it < 48 || *it > 57)
                throw error;
        }
        else
        {
            if ((*it < 48 || *it > 57) && *it != '-')
                throw error;
        }
    }
}

void    Rpn::testOperation(std::string &alpha) const{
    std::string error = "Error";

    if (alpha.size() != 1)
        throw error;
    // if (alpha != "-" && alpha != "+" && alpha != "/" && alpha != "*")
    //     throw error;
}



//---------------------  pour tests ----------------------------------

void    Rpn::emptyRpn(){
    while (!_datas.empty())
    {
        std::cout << _datas.top() << " // ";
        _datas.pop();
    }
    std::cout << std::endl;
}

std::ostream     &operator<<(std::ostream &os, Rpn const &rhs) {
    
    os << "size : " << rhs.getData().size() << " // top = " << rhs.getData().top();
    return os;
}