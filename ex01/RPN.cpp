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
    //std::cout << "Constructor Rpn" << std::endl;
    std::string temp = argc;

    //std::cout << "temp : --" << temp << "--" << std::endl;
    while (true)
    {
        std::size_t pos = temp.rfind(" ");
        if (pos == std::string::npos)
            break;
        std::string temp2 = temp.substr(pos + 1);
        if (temp2 != "")
        {
            if (temp2.size() == 1)
                _datas.push(temp2);
            else 
            {
                _datas.push(temp2.substr(1));
                temp2.erase(1);
                _datas.push(temp2);
            }
        }
        temp.erase(pos);
    }
    if (temp.size() == 1)
        _datas.push(temp);
    else 
    {
        _datas.push(temp.substr(1));
        temp.erase(1);
        _datas.push(temp);
    }
}

Rpn::~Rpn() {
    //std::cout << "Destructor Rpn" << std::endl;
}

std::stack<std::string> Rpn::getData() const {
    return _datas;
}

float Rpn::calcPolish() {
    int result = 0;
    int result2 = 0;
    int nb = 0;

    std::stack<std::string>     temp;
    std::string                 error = "\nError";
    std::string                 errorByZero = "\nError By Zero";

    if (testAlpha(_datas.top()))
        result = static_cast<float>(atoi(_datas.top().c_str()));
    else 
        throw error;

    _datas.pop();
    while (!_datas.empty())
    {

        if (!(testOperation(_datas.top()) || testAlpha(_datas.top())))
            throw error;
        if (testOperation(_datas.top()) && temp.empty())
            throw error;
        if (testOperation(_datas.top()))
        {
            if (temp.size() == 1)
            {
                nb = atoi(temp.top().c_str());
                temp.pop();
                std::cout << YELLOW << result << RED " " << _datas.top() << " " CYANE << nb << WHITE " = ";  // -- test

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
                std::cout << YELLOW << result << std::endl;  //  test ---
                _datas.pop();
            }
            else
            {
                nb = atoi(temp.top().c_str());
                temp.pop();
                result2 = atoi(temp.top().c_str());
                temp.pop();
                std::cout << YELLOW << result2 << RED " " << _datas.top() << " " CYANE << nb << WHITE " = ";  // -- test
                if (_datas.top() == "-")
                    result2 = result2 - nb;
                else if (_datas.top() == "+")
                    result2 = result2 + nb;
                else if (_datas.top() == "*")
                    result2 = result2 * nb;
                else if (_datas.top() == "/")
                {
                    if (!nb)
                        throw errorByZero;
                    result2 = result2 / nb;
                }
                std::cout << YELLOW << result2 << std::endl;  //  test ---
                _datas.pop();
                std::string in(std::to_string(result2));
                temp.push((in));              

            }

        }
        else
        {
            temp.push(_datas.top());
            _datas.pop();
        }

    }
    std::cout << GREEN;
    return result;
}

bool    Rpn::testAlpha(std::string &alpha) const{
    if (alpha < "0" || alpha > "9")
        return false;
    return true;
}

bool    Rpn::testOperation(std::string &alpha) const{
    if (alpha != "-" && alpha != "+" && alpha != "/" && alpha != "*")
        return false;
    return true;
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