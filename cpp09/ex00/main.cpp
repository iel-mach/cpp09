/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:04:52 by iel-mach          #+#    #+#             */
/*   Updated: 2023/03/18 19:04:46 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

int    check_date(std::string date)
{
    std::stringstream ss(date);
    std::string year = "";
    std::string month = "";
    std::string day = "";
    int y = 0;
    int m = 0;
    int d = 0;
    getline(ss, year, '-');
    getline(ss, month, '-');
    getline(ss, day);
    std::stringstream ssy(year);
    std::stringstream ssm(month);
    std::stringstream ssd(day);
    ssy >> y;
    ssm >> m;
    ssd >> d;
    if(y < 2009 || y > 2022)
        return 0;
    if(m < 1 || m > 12)
        return 0;
    if (d < 1 || d > 31)
        return 0;
    return 1;
}

BitcoinExchange get_files(void)
{
    std::ifstream fd_csv;
    BitcoinExchange bitc;
    double v;
    fd_csv.open("data.csv", std::ifstream::in);
    if (!fd_csv) 
    {
        std::cout << "Error: csv not found" << std::endl;
        exit(1);
    }
    std::string get;
    std::string value;
    std::string date;
    getline(fd_csv, get);
    while(getline(fd_csv, get))
    {
        if(!get.empty())
        {
            std::stringstream ss(get);
            getline(ss, date, ',');
            getline(ss, value, '\n');
            std::stringstream sse(value);
            v = stod(value);
            bitc.set_csv(date, v);
        }
    }
    return (bitc);
}

int check_value(long value)
{
    if(value < 0)
        return -1;
    if (value > 1000)
        return 0;
    return 1;
}

double get_date(std::map <std::string, double> csv, std::string date)
{
    std::map <std::string, double>::iterator it = csv.begin();
    // std::map <std::string, double>::iterator ite = csv.end();
    // std::stringstream sse(date);
    // std::string day;
    // std::string month;
    // std::string year;
    // int d;
    // int y;
    // int m;
    // std::string _day;
    // std::string _month;
    // std::string _year;
    // int _d;
    // int _y;
    // int _m;
    // getline(sse, year, '-');
    // getline(sse, month, '-');
    // getline(sse, day);
    // std::stringstream ssy(year);
    // std::stringstream ssm(month);
    // std::stringstream ssd(day);
    // ssy >> y;
    // ssm >> m;
    // ssd >> d;
    // double exchange = 0;
    it = csv.lower_bound(date);
    if(it->first != date)
        it--;
    // for (; it != ite; ++it)
    // {
    //     std::stringstream ss(it->first);
    //     getline(ss, _year, '-');
    //     getline(ss, _month, '-');
    //     getline(ss, _day);
    //     std::stringstream _ssy(_year);
    //     std::stringstream _ssm(_month);
    //     std::stringstream _ssd(_day);
    //     _ssy >> _y;
    //     _ssm >> _m;
    //     _ssd >> _d;
    //     // std::cout << it->first << std::endl;
    //     if(y == _y)
    //     {
    //         if(m == _m)
    //         {
    //             if(d == _d)
    //             {
    //                 return(it->second);
    //             }
    //             else
    //             {
    //                 if(_d < d)
    //                     exchange = it->second;
    //                 // std::cout << "exchange == " << exchange << std::endl;
    //             }
    //         }
    //     }
    // }
    return (it->second);
}

int main(int ac, char **av)
{
    BitcoinExchange bitc;
    std::ifstream fd_input;
    std::string get;
    std::string value;
    std::string date;
    std::string _date;
    double val = 0;
    double exchange = 0;
    if(ac == 2)
    {
        bitc = get_files();
        fd_input.open(av[1], std::ifstream::in);
        if (!fd_input) 
        {
            std::cout << "Error: Failed to open input file" << std::endl;
            return 1;
        }
        if(fd_input.peek() == std::ifstream::traits_type::eof())
        {
            std::cout << "Error: empty file" << std::endl;
            return 1;
        }
        while(getline(fd_input, get))
        {
            if(!get.empty())
            {
                value = "";
                date = "";
                std::stringstream ss(get);
                getline(ss, date, '|');
                if(!date.empty())
                {
                    if(check_date(date) == 1)
                    {
                        getline(ss, value, '\n');
                        if (!value.empty())
                        {
                            std::stringstream ssv(value);
                            ssv >> val;
                            if(check_value(val) == 1)
                            {
                                date = trim(date);
                                exchange = get_date(bitc.get_csv(), date);
                                std::cout  << date << " ==> " << value << " = " << (exchange * val) << std::endl;

                            }
                            else if (check_value(val) == -1)
                                std::cout  << "Error: not a positive number." << std::endl;
                            else if (check_value(val) == 0)
                                std::cout  << "Error: too large a number." << std::endl;
                        }
                        else
                            std::cout  << "Error: value not exist" << std::endl;
                    }
                    else
                        std::cout << "Error: bad input => " << date << std::endl;
                }
                else
                    std::cout  << "Error: date not exist" << std::endl;
            }
            else
                std::cout << "Error: fileempty!" << std::endl;
        }
        // std::cout << getline(fd_input, get) << std::endl;
    }
    else
        std::cout << "Error: could not open file." << std::endl;
    return 0;
}