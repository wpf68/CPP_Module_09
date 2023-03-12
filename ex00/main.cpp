/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:51:42 by pwolff            #+#    #+#             */
/*   Updated: 2023/03/12 11:21:42 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        if (argc == 1)
            std::cerr << RED "Error: could not open file." NONE << std::endl;
        else
            std::cerr << RED "Error, too many arguments." NONE << std::endl;
        return 1;
    }
    
    try
    {
        BitcoinExchange bitCoin(argv[1]);
        bitCoin.calcValueBitcoin();
    }
    catch(const std::string &e)
    {
        std::cerr << RED <<  e << NONE "\n";
    }
    




    return 0;
}