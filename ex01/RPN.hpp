/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:22:59 by pwolff            #+#    #+#             */
/*   Updated: 2023/03/10 10:22:59 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <exception>
#include <cstdlib>
//#include <algorithm>

//#include <cmath>


class Rpn
{
public:
    Rpn(char *argc);
    ~Rpn();

    std::stack<std::string> getData() const;
    float                     calcPolish();

    // pour tests
    void    emptyRpn();


private:
    Rpn();
    Rpn(Rpn const &);

    Rpn &operator=(Rpn const &);

    void    testAlpha(std::string &alpha) const;
    void    testOperation(std::string &alpha) const;

    std::stack<std::string>   _datas;
};

    // pour tests
std::ostream     &operator<<(std::ostream &os, Rpn const &rhs);