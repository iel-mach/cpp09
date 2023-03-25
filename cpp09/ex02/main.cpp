/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:02:55 by iel-mach          #+#    #+#             */
/*   Updated: 2023/03/25 01:54:33 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    check_arg(char **av, int ac)
{
    int j;
    for(int i = 0; i < ac; i++)
    {
        j = 0;
        while(av[i][j])
        {
            if(!isdigit(av[i][j]))
                throw PmergeMe::ErrorArgs();
            j++;
        }
    }
}

int main(int ac, char **av)
{
    try
    {
        PmergeMe sr;
        if(ac > 1 && ac < 3001)
        {
            check_arg(av, ac);
            sr.set_vec_arg(av, ac);
            sr.set_pair();
        }
        else
            throw PmergeMe::ErrorArgs();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}