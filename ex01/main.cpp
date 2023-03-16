/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:20:11 by pwolff            #+#    #+#             */
/*   Updated: 2023/03/10 10:20:11 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
    Test :
    https://www.dcode.fr/notation-polonaise-inverse
*/

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED "Error" NONE << std::endl;
        return 1;
    }

    Rpn polish;

    try
    {
        polish.calcPolish(argv[1]);
    }
    catch(std::string e)
    {
        std::cerr << RED << e << NONE "\n";
    }

    return 0;
}