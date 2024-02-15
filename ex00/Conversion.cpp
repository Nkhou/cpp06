#include "Conversion.hpp"

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::ScalarConverter(ScalarConverter const &other)
{

    *this = other;
}
void ScalarConverter::storType(std::string str)
{
    int i = 0;
    if (std::isdigit(str[i]))
    {
        while (str[i] < str.length())
        {
            if (std::isdigit(str[i]) == 0)
            {
                if (str[i] != 'f')
                    throw ConverterExeption();
                else if (str[i] != 'f' && (i + 1) < str.length())
                    throw ConverterExeption();
            }
            i++;
        }
        
    }
    else if (std::isalpha(str[i]))
    {
        if (str.length() != 1)
            throw ConverterExeption();
    }
    else
    {
        throw ConverterExeption();
    }
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    str = other.str;
    type = other.type;
    inttype = other.type;
    doubltype = other.type;
    storType(str);
    return *this;
}
ScalarConverter::ScalarConverter(char *str)
{
    this->str = str;

}
ScalarConverter::~ScalarConverter()
{
}
void ScalarConverter::convert(std::string str)
{
    (void) str;
}

const char *ScalarConverter::ConverterExeption::what() const throw()
{
    return "impossible";
}
// void ScalarConverter::setStr(char *str)
// {
//     this->str(str);
// }

