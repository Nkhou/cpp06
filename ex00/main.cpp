#include "Conversion.hpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
            throw ScalarConverter::ConverterExeption();
        ScalarConverter ScalarConverter(argv[1]);
        // ScalarConverter.convert();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}