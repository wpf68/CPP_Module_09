/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:31:04 by pwolff            #+#    #+#             */
/*   Updated: 2023/03/11 09:31:04 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// https://www.techiedelight.com/fr/find-execution-time-c-program/

// https://www.delftstack.com/fr/howto/cpp/cpp-timing/
// https://en.cppreference.com/w/cpp/chrono/duration



#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

#include <set>
#include <list>

#define BILLION  1000000.0

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

class PmergeMe
{
public:
    PmergeMe(unsigned int nb, char **datas);
    virtual ~PmergeMe();

    void    displaySet(unsigned int nb, char **datas);


private:
    PmergeMe();
    PmergeMe(PmergeMe const &);

    PmergeMe    &operator=(PmergeMe const &);

    bool    testNum(char *datas);

    std::set<unsigned int>      _contSet;
    std::list<unsigned int>     _contList;
    double                      _timeSet;
    double                      _timeList;

};