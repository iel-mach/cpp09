/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:03:17 by iel-mach          #+#    #+#             */
/*   Updated: 2023/03/25 01:54:13 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe const &o)
{
    *this = o;
}

void    PmergeMe::set_vec_arg(char **av, int ac)
{
    for(int i = 0; i < ac; i++)
        this->vec_arg.push_back(atoi(av[i]));
}

void    PmergeMe::set_pair()
{
    for(size_t i = 0; i < (this->vec_arg.size() - 1); i += 2)
    {
        this->pair_vec.push_back(std::make_pair(this->vec_arg[i], this->vec_arg[i + 1]));
    }
    std::vector<std::pair<int , int> >::iterator it = this->pair_vec.begin();
    std::vector<std::pair<int , int> >::iterator ite = this->pair_vec.end();
    for (; it != ite; ++it)
    {
        std::cout << it->first << " " << it->second <<std::endl;
    }
}

const char* PmergeMe::ErrorArgs::what() const throw()
{
    return("Error: Bad Arg");
}