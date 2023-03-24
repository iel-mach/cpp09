/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 03:35:21 by iel-mach          #+#    #+#             */
/*   Updated: 2023/03/23 17:07:25 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int check_operator(char c)
{
    if(c != '*' && c != '/' && c != '-' && c !=  '+')
        return 0;
    return 1;
}

int operator_int(int num1, int num2, char c)
{
    int res = 0;
    if(c == '*')
        res = num1 * num2;
    else if (c == '-')
        res = num1 - num2;
    else if (c == '+')
        res = num1 + num2;
    else if (c == '/')
        res = num1 / num2;
    return(res);
}

int main(int ac, char **av)
{
    try{
    if(ac == 2)
    {
        int i = 0;
        int num1 = 0;
        int num2 = 0;
        int x;
        RPN nums;
        while(av[1][i])
        {
            if(av[1][i] == ' ')
            {
                i++;
                continue;
            }
            else if(isdigit(av[1][i]))
            {
                x = av[1][i] - 48;
                nums.set_num(x);
            }
            else if (check_operator(av[1][i]))
            {
                if(nums.get_num().size() >= 2)
                {
                    num1 = nums.get_num().top();
                    nums.rpn_pop();
                    num2 = nums.get_num().top();
                    nums.rpn_pop();
                    nums.set_num(operator_int(num1, num2, av[1][i]));
                }
                else
                    throw RPN::ErrorArgs();
            }
            else
                throw RPN::ErrorChar();
            i++;
        }
        if(nums.get_num().size() == 1)
            std::cout << nums.get_num().top() << std::endl;
        else
            throw RPN::ErrorArgs();
    }
    else
        throw RPN::ErrorArgs();
    }
    catch (RPN::ErrorArgs &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (RPN::ErrorChar &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}