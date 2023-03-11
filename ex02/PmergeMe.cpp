/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:30:51 by pwolff            #+#    #+#             */
/*   Updated: 2023/03/11 09:30:51 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(unsigned int nb, char **datas) : _timeSet(0), _timeList(0) {
    
    std::string error = "Error";
    struct timespec start, end;

    // ---------  sort set ----------------
    clock_gettime(CLOCK_REALTIME, &start);
    for (unsigned int i = 1; i <= nb; i++)
    {
        if (!testNum(datas[i]))
            throw   error;
        _contSet.insert(atoi(datas[i]));
    }
    clock_gettime(CLOCK_REALTIME, &end);
    _timeSet = (end.tv_sec - start.tv_sec) +
                (end.tv_nsec - start.tv_nsec) / BILLION;

    // --------- sort list -----------
    clock_gettime(CLOCK_REALTIME, &start);
    for (unsigned int i = 1; i <= nb; i++)
    {
        if (!testNum(datas[i]))
            throw   error;
        // test doublons ----------------------
        bool    test = true;
        for (std::list<unsigned int>::iterator it = _contList.begin(); it != _contList.end(); it++)
        {
            if (*it == static_cast<unsigned int>(atoi(datas[i])))
            {
                test = false;
                break;
            }           
        }
        if (test)
            _contList.push_back(atoi(datas[i]));
    }
    _contList.sort();
    clock_gettime(CLOCK_REALTIME, &end);
    _timeList = (end.tv_sec - start.tv_sec) +
                (end.tv_nsec - start.tv_nsec) / BILLION;

    std::cout << "Constructor\n";
}

PmergeMe::~PmergeMe() {
    std::cout << "Destructor\n";
}

void    PmergeMe::displaySet(unsigned int nb, char **datas)
{
    std::cout << "Before: ";
    for (unsigned int i = 1; i <= nb; i++)
    {
        if (i == 1)
            std::cout << datas[i];
        else
            std::cout << " - " <<  datas[i];
    } 
    std::cout << "\nAfter (set)  : ";
    for (std::set<unsigned int>::iterator it = _contSet.begin(); it != _contSet.end(); it++)
    {
        if (it == _contSet.begin())
            std::cout << *it;
        else
            std::cout << " - " <<  *it;
    }
    std::cout << "\nAfter (list) : ";
    for (std::list<unsigned int>::iterator it = _contList.begin(); it != _contList.end(); it++)
    {
        if (it == _contList.begin())
            std::cout << *it;
        else
            std::cout << " - " <<  *it;
    }
    std::cout << "\nTime to process a range of " << nb  << " elements with std::set  : " << _timeSet << " us" << std::endl;
    std::cout << "Time to process a range of " << nb  << " elements with std::list : " << _timeList << " us" << std::endl;        
}



bool    PmergeMe::testNum(char *datas)
{
    for (unsigned int i = 0; datas[i]; i++)
        if (datas[i] < '0' || datas[i] > '9')
            return false;
    return true;
}