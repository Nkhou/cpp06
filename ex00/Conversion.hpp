#ifndef CONVERSION_HPP
#define CONVERSION_HPP
#include <iostream>
#include <exception>


class ScalarConverter
{
    private:
        ScalarConverter();
    //     std::string str;
    //     char iftd;
    //     char type;
    //     int inttype;
    //     float fltype;
    //     double doubltype;
    public:
        // void setStr(char *str);
        ScalarConverter(char *str);
        ScalarConverter(ScalarConverter const &src);
        ~ScalarConverter();
        void storType(std::string str, char *iftd);
        ScalarConverter &operator=(ScalarConverter const &src);
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