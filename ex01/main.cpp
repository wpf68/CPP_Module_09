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

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED "Error" NONE << std::endl;
        return 1;
    }

    Rpn polish(argv[1]);
    // polish.emptyRpn();
    // exit (0);

    try
    {
        std::cout << polish.calcPolish() << NONE << std::endl;
    }
    catch(std::string e)
    {
        std::cerr << RED << e << NONE "\n";
    }
    

    // std::cout << polish << std::endl;
    // polish.emptyRpn();
    


    return 0;
}