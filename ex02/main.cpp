/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:37:42 by pwolff            #+#    #+#             */
/*   Updated: 2023/03/11 09:37:42 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << RED "Error arg\n" NONE;
        return 1;
    }

    try
    {
        PmergeMe    sort(argc - 1, argv);
        sort.displaySet(argc - 1, argv);
    }
    catch(std::string const & e)
    {
        std::cerr << RED << e << NONE << '\n';
    }
    
    
    




    return 0;
}