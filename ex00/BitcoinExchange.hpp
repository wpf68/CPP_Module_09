/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:52:37 by pwolff            #+#    #+#             */
/*   Updated: 2023/03/15 10:20:51 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>
#include <cstdlib>
#include <iomanip> 

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

#define FICHIER_CSV "data.csv"
#define FLOAT_MAX   999999

class BitcoinExchange
{
public:
    BitcoinExchange(char *fichierTxt);
    virtual ~BitcoinExchange();

    void    calcValueBitcoin();

private:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &);

    BitcoinExchange operator=(BitcoinExchange const &);

    void    displayDatas();
    bool    testDate(std::string const &date);
    bool    testDateValide(std::string const &date);

    std::map<std::string, float>    _datas;
    std::string                     _fichierTxt;
};