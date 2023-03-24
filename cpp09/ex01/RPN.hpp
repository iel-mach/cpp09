/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 03:36:42 by iel-mach          #+#    #+#             */
/*   Updated: 2023/03/23 05:22:15 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN{
    private:
        std::stack<int> num;
    public:
    RPN();
    RPN(RPN const &o);
    RPN const &operator=(RPN const &o);
    ~RPN();
    void    set_num(int n);
    std::stack<int> const &get_num() const;
    void    rpn_pop();
    class ErrorArgs : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class ErrorChar : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};
#endif