/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 03:36:36 by iel-mach          #+#    #+#             */
/*   Updated: 2023/03/23 05:22:11 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(RPN const &o)
{
    *this = o;
}

RPN const &RPN::operator=(RPN const &o)
{
    this->num = o.num;
    return *this;
}

RPN::~RPN()
{
    std::stack<int>().swap(num);
}

void    RPN::set_num(int n)
{
    this->num.push(n);
}

void    RPN::rpn_pop()
{
    this->num.pop();
}

std::stack<int> const &RPN::get_num() const
{
    return this->num;
}

const char* RPN::ErrorArgs::what() const throw()
{
    return("Error: Bad Arg");
}

const char* RPN::ErrorChar::what() const throw()
{
    return("Error: Character Not Suport");
}
