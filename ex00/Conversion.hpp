#ifndef CONVERSION_HPP
#define CONVERSION_HPP
#include <iostream>
#include <exception>


class ScalarConverter
{
    private:
        std::string str;
        char type;
        int inttype;
        float fltype;
        double doubltype;
    public:
        // void setStr(char *str);
        ScalarConverter();
        ScalarConverter(char *str);
        ScalarConverter(ScalarConverter const &src);
        ~ScalarConverter();
        void storType(std::string str);
        ScalarConverter &operator=(ScalarConverter const &src);
        static void convert(std::string str);
        class ConverterExeption : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif 