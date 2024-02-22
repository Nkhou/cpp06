#include "Conversion.hpp"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    *this = other;
}
void ScalarConverter::doubleOrfloat(std::string str, char *iftd)
{
    size_t i;
    int cmp;

    i = 0;
    cmp = 0;
    if (str.length() == 0)
        throw ConverterExeption();
    while (i < str.length())
    {
        if (str[i] != 'f' && std::isdigit(str[i]) == 0 && str[i] != '.')
            throw ConverterExeption();
        else if (str[i] == 'f' && (i + 1) < str.length())
            throw ConverterExeption();
        else if (str[i] == '.')
            cmp++;
        i++;
    }
    if (str[i - 1] == 'f')
    {
        *iftd = 'f';
    }
    else
        *iftd = 'd';
}
void ScalarConverter::storType(std::string str, char *iftd)
{
    size_t i = 0;

    if (std::isdigit(str[i]))
    {
        while (i <= str.length())
        {
            if (std::isdigit(str[i]) == 0)
            {
                if (str[i] == '.')
                {
                    doubleOrfloat(str, iftd);
                    return ;
                }
                if (std::isdigit(str[i]))
                    throw ConverterExeption();
            }
            i++;
        }
        *iftd = 'i';
    }
    else
    {
        if (str.length() != 1 && str != "-inf" && str != "+inf" && str != "nanf" && str != "nan")
            throw ConverterExeption();
        *iftd = 'c';
    }
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    (void)other;
    return *this;
}
ScalarConverter::ScalarConverter(char *str)
{
    std::string str1 = static_cast<std::string>(str);
    convert(str1);
}
ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::printfChar(std::string str)
{
    int i = 0;

    if (str.length() != 1)
    {
        std::cout << "char: impossible"<<std::endl;
        std::cout << "int: impossible"<<std::endl;
        if (str == "nan" || str == "nanf")
        {
            std::cout << "float: "<<"nanf"<<std::endl;
            std::cout << "double: "<<"nan"<<std::endl;
        }
        else if (str == "-inf" || str == "+inf")
        {
            std::cout << "float: "<<str<<std::endl;
            std::cout << "double: "<<str<<std::endl;
        }
        return ;
    }
    else if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
        std::cout << "char: Non displayable"<< std::endl;
    else if (str[i] >31 && str[i] < 127)
        std::cout << "char: '" <<str << "'"<<std::endl;
    else 
        std::cout << "char: impossible"<<std::endl;
    std::cout << "int: "<<static_cast<int>(str[i])<<std::endl;
    std::cout << "float: "<<static_cast<float>(str[i])<<".0f"<<std::endl;
    std::cout << "double: "<<static_cast<double>(str[i])<<".0"<<std::endl;
}
void ScalarConverter::printInt(std::string str)
{
    int integer = std::atoi(str.c_str());
    if ((integer >= 0 && integer <= 31) || integer == 127)
        std::cout << "char: Non displayable"<< std::endl;
    else if (integer >31 && integer < 127)
        std::cout << "char: '" <<static_cast<char>(integer)<< "'"<<std::endl;
    else
        std::cout << "char: impossible"<<std::endl;
    std::cout << "int: "<<integer<<std::endl;
    std::cout << "float: "<<integer<<".0f"<<std::endl;
    std::cout << "double: "<<integer<<".0"<<std::endl;
}
void ScalarConverter::printfFloat(std::string str)
{
    float integer = std::stof(str);
    int d = round(integer );

    if ((static_cast<int>(integer) >= 0 && static_cast<int>(integer) <= 31) || static_cast<int>(integer) == 127)
        std::cout << "char: Non displayable"<< std::endl;
    else if (static_cast<int>(integer) > 31 && static_cast<int>(integer) < 127)
        std::cout << "char: '" <<(char)integer<< "'"<<std::endl;
    else
        std::cout << "char: impossible"<<std::endl;
    if (integer <= 2147483647 && integer >= -2147483648)
        std::cout << "int: "<<static_cast<int>(integer)<<std::endl;
    else
        std::cout << "int: impossible"<<std::endl;
    if (d != integer)
    {
        std::cout << "float: "<<integer<<"f"<<std::endl;
        std::cout << "double: "<<integer<<std::endl;
    }
    else
    {
        std::cout << "float: "<<integer<<".0f"<<std::endl;
        std::cout << "double: "<<integer<<".0"<<std::endl;
    }
}

void ScalarConverter::printDouble(std::string str)
{
    double integer = std::stof(str);
    int d = round(integer);
    if ((static_cast<int>(integer) >= 0 && static_cast<int>(integer) <= 31) || static_cast<int>(integer) == 127)
        std::cout << "char: Non displayable"<< std::endl;
    else if (static_cast<int>(integer) > 31 && static_cast<int>(integer) < 127)
        std::cout << "char: '" <<static_cast<char>(integer)<< "'"<<std::endl;
    else
        std::cout << "char: impossible"<<std::endl;
    if (integer <= 2147483647 && integer >= -2147483648)
        std::cout << "int: "<<static_cast<int>(integer)<<std::endl;
    else
        std::cout << "int: impossible"<<std::endl;
    if (d != integer)
    {
        std::cout << "float: "<<integer<<"f"<<std::endl;
        std::cout << "double: "<<integer<<std::endl;
    }
    else
    {
        std::cout << "float: "<<integer<<".0f"<<std::endl;
        std::cout << "double: "<<integer<<".0"<<std::endl;
    }
}
void ScalarConverter::convert(std::string str)
{
    char iftd;
    ScalarConverter conv;
    conv.storType(str, &iftd);
    switch (iftd)
    {
        case 'i':
        {
            conv.printInt(str);
            break;
        }
        case 'f':
        {
            conv.printfFloat(str);
            break;
        }
        case 'c':
        {
            conv.printfChar(str);
            break;
        }
        case 'd':
            conv.printDouble(str);
        default:
            break;
    }
}

const char *ScalarConverter::ConverterExeption::what() const throw()
{
    return "impossible";
}
