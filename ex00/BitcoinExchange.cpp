/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:52:51 by pwolff            #+#    #+#             */
/*   Updated: 2023/03/14 16:12:31 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *fichierTxt) : _fichierTxt(fichierTxt) {
    std::string errorOpen = "Error: could not open file.";
    std::string errorFormat = "Error: error format in the file.";
    std::string errorBadInput = "Error: bad input =>";
    std::string errorTooLargeNumber = "Error: too large a number.";
    std::string errorNegativeNumber = "Error: not a positive number.";

    std::ifstream   monFlux;
    std::string     buffer;
    std::string     temp;
    float           val;
    

    // Traitement fichier .csc ---------------------

    monFlux.open(FICHIER_CSV);
    if (!monFlux)
        throw errorOpen;
    
    getline(monFlux, buffer); 
    while (getline(monFlux, buffer))
    {
        size_t  i = buffer.find("\r");  // 1 heure ....
        if (i != std::string::npos)
            buffer.erase(i);

        i = buffer.find(",");
        if (i == std::string::npos)
            throw errorFormat;
        val = atof(buffer.substr(i + 1).c_str());
        if (val > FLOAT_MAX)
            throw errorTooLargeNumber;
        if (val < 0)
            throw errorNegativeNumber;

        if (i)
            buffer.erase(i);
        else
            throw errorBadInput;

        _datas.insert(std::pair<std::string, float>(buffer, val));
        
    }
    monFlux.close();
    // std::cout << YELLOW "\n** Constructor ** \n" NONE; 
    displayDatas();
    
}

BitcoinExchange::~BitcoinExchange() {
    // std::cout << YELLOW "\n** Destructor ** \n" NONE; 
}


void    BitcoinExchange::calcValueBitcoin(){
    std::string errorOpen = "Error: could not open file.";
    std::string errorFormat = "Error: error format in the file.";
    std::string errorBadInput = "Error: bad input => ";
    std::string errorTooLargeNumber = "Error: too large a number.";
    std::string errorNegativeNumber = "Error: not a positive number.";

    std::ifstream   monFlux;
    std::string     buffer;
    std::string     temp;
    float           val;
    float           nbBitcoin;

    // Traitement fichier .txt ---------------------

    monFlux.open(_fichierTxt.c_str());
    if (!monFlux)
        throw errorOpen;

    getline(monFlux, buffer); 
    while (getline(monFlux, buffer))
    {
        size_t  i = buffer.find("\r"); 
        if (i != std::string::npos)
            buffer.erase(i);

        i = buffer.find("| ");
        if (i == std::string::npos)
        {
            std::cout << RED << errorFormat << NONE << std::endl;
            continue;
        }
        
        nbBitcoin = atof(buffer.substr(i + 2).c_str());
        if (nbBitcoin > FLOAT_MAX)
        {
            std::cout << RED <<  errorTooLargeNumber << NONE << std::endl;
            continue;
        }
        if (nbBitcoin < 0)
        {
            std::cout << RED <<  errorNegativeNumber << NONE << std::endl;
            continue;
        }
        if (i)
            buffer.erase(i - 1);
        else
        {
            std::cout << RED <<  errorBadInput << NONE << std::endl;
            continue;
        }

        if (testDate(buffer))
            val = _datas[buffer];
        else
        {
            std::cout << RED <<  errorBadInput << buffer << NONE << std::endl;
            continue;
        }
        std::cout << std::setprecision(2) << buffer << " => " << nbBitcoin <<  " = " << val * nbBitcoin << std::endl;
        

        

        //_datas.insert(std::pair<std::string, float>(buffer, val));
        
    }


    monFlux.close();

}

void    BitcoinExchange::displayDatas() {
    std::cout << GREEN "\n****** BitCoin price data ********\n\n" NONE;
    for (std::map<std::string, float>::iterator it = _datas.begin(); it != _datas.end(); it++)
    {
        std::cout << "Date : " YELLOW << it->first << NONE " -- price : " CYANE << std::setprecision(3) << std::fixed << std::setw(13) << it->second << NONE << std::endl;
    }
    std::cout << GREEN "\n**********************************\n\n" NONE;
}

bool    BitcoinExchange::testDate(std::string const &date){
    bool    status = false;
    for (std::map<std::string, float>::iterator it = _datas.begin(); it != _datas.end(); it++)
    {
        if (date == it->first)
        {
            status = true;
            break;
        }   
    }
    return status;
}