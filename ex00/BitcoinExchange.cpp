/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:52:51 by pwolff            #+#    #+#             */
/*   Updated: 2023/03/12 11:54:02 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *fichierTxt) : _fichierTxt(fichierTxt) {
    std::string errorOpen = "Error: could not open file.";

    std::ofstream monFlux;

    monFlux.open(FICHIER_CSV);
    if (!monFlux)
        throw errorOpen;

    
    


    monFlux.close();
    std::cout << "Constructor\n"; 
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "Destructor\n"; 
}


void    BitcoinExchange::calcValueBitcoin(){
    
}
