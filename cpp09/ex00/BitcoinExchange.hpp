/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:45:53 by iel-mach          #+#    #+#             */
/*   Updated: 2023/03/17 13:10:25 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

const std::string WHITESPACE = " \n\r\t\f\v";

class BitcoinExchange{
    private:
        std::map <std::string, double> csv;
    public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &o);
    BitcoinExchange const &operator=(BitcoinExchange const &o);
    void    set_csv(std::string key, double value);
    std::map <std::string, double> const &get_csv() const;
};

#endif