/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:03:24 by iel-mach          #+#    #+#             */
/*   Updated: 2023/03/25 01:54:43 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>

class PmergeMe{
    private:
    std::vector<int>vec_arg;
    std::vector< std::pair <int,int> > pair_vec;
    public:
    PmergeMe();
    PmergeMe(PmergeMe const &o);
    // PmergeMe const &operator=(PmergeMe const &o);
    void    set_vec_arg(char **av, int ac);
    void    set_pair();
    class ErrorArgs : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif