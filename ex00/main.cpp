#include "Conversion.hpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
            throw ScalarConverter::ConverterExeption();
        ScalarConverter ScalarConverter(argv[1]);
        // ScalarConverter
        // check_argument(av[1]);
        // ScalarConverter.ScalarConverter(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // try
    // {
        // if (ac != 2)
        //     throw ConversionExeption();
    // }
}