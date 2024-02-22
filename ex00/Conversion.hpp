#ifndef CONVERSION_HPP
#define CONVERSION_HPP
#include <iostream>
#include <exception>


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter &operator=(ScalarConverter const &other);
    public:
        ScalarConverter(char *str);
        ~ScalarConverter();
        void storType(std::string str, char *iftd);
        static void convert(std::string str);
        void doubleOrfloat(std::string str, char *iftd);
        void printInt(std::string str);
        void printfFloat(std::string str);
        void printfChar(std::string str);
        void printDouble(std::string str);
        class ConverterExeption : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif 