/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:45:46 by iel-mach          #+#    #+#             */
/*   Updated: 2023/03/17 13:13:59 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange()
{
    this->csv.clear();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &o)
{
    *this = o;
}

BitcoinExchange const &BitcoinExchange::operator=(BitcoinExchange const &o)
{
    this->csv = o.csv;
    return *this;
}

void    BitcoinExchange::set_csv(std::string key, double value)
{
    this->csv.insert(std::make_pair(key, value));
}

std::map <std::string, double> const &BitcoinExchange::get_csv() const
{
    return this->csv;
}