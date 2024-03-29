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

# ifndef COLOR
#  define COLOR
#  define CLEAR		"\x1B[2J\x1B[H"
#  define NONE		"\033[0;37m"
#  define WHITE		"\033[1;37m"
#  define RED		"\033[1;31m"
#  define GREEN		"\033[1;32m"
#  define CYANE		"\033[1;36m"
#  define ORANGE	"\033[1,38m"
#  define YELLOW	"\033[1;33m"
#  define BLUE		"\033[1,34m"
#  define GREY		"\033[1,37m"
#  define ROSE		"\033[35m"
#  define UNDER		"\033[4m"
#  define END		"\033[0m"
# endif


class Rpn
{
public:
    Rpn();
    ~Rpn();

    std::stack<std::string>     getData() const;
    void                        calcPolish(char *argv);

private:
    Rpn(Rpn const &);

    Rpn &operator=(Rpn const &);

    bool    testAlpha(char alpha) const;
    bool    testOperation(char alpha) const;

    std::stack<int>   _datas;
};
