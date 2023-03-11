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