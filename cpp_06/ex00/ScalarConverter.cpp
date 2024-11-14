#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

float toFloat(std::string value)
{
	float valueFloat = atof(value.c_str());
	return (valueFloat);  

}
char toChar(std::string value)
{
	char charValue = static_cast<char>(toFloat(value));
	return (charValue);
}

int toInt(std::string value)
{
	return (static_cast<int>(toFloat(value)));
}

double toDouble(std::string value)
{
	return (static_cast<double>(toFloat(value)));
}
bool isNan(float value)
{
    return value != value; 
}

bool isValidInt(const std::string value) 
{
    bool hasDecimalPoint = false;
    for (size_t i = 0; i < value.length(); ++i) {
        if (!std::isdigit(value[i])) {
            if (value[i] == '.' && !hasDecimalPoint) {
                hasDecimalPoint = true;
            }
            else if (!(i == 0 && (value[i] == '+' || value[i] == '-'))) {
                return false;  
            }
        }
    }
    return true;
}

void ScalarConverter::convert(std::string value)
{
    if (toFloat(value) < CHAR_MIN || toFloat(value) > CHAR_MAX || isNan(toFloat(value)))
		std::cout << "Char: impossible" << std::endl;
	else if (isprint(toChar(value)))	
		std::cout << "Char: '" << toChar(value) << "'"<< std::endl;
    else if(value.length() == 1  && !std::isdigit(value[0]))
        std::cout << "Char: '" << value[0] << "'" << std::endl;
	else if (!isValidInt(value) && value.length() > 1)
		std::cout << "Char: impossible" << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;

    if (toFloat(value) < INT_MIN || toFloat(value) > INT_MAX || isNan(toFloat(value)))
		std::cout << "Int: impossible" << std::endl;
	else if (value.length() == 1 && !std::isdigit(value[0]))
		 std::cout << "Int: "<< static_cast<int>(value[0]) << std::endl;
	else if (!isValidInt(value) && value.length() > 1) 
        std::cout << "Int: impossible" << std::endl;
	else
		std::cout << "Int: " << toInt(value) << std::endl;
    if(!isValidInt(value))
	{
		if(value.length() == 1)
		{
			std::cout << "float: "<< static_cast<int>(value[0])  << "f" << std::endl;
			std::cout << "double: "<< static_cast<int>(value[0]) << ".0" << std::endl;
		}
		else
		{
			if (value == "-inf" || value == "+inf" || value == "inf" || value == "+inff" || value == "-inff" || value == "inff")
			{
    			if (value[0] == '-') 
				{
        			std::cout << "Float: -inff" << std::endl;
        			std::cout << "Double: -inf" << std::endl;
				}
				else
				{
        			std::cout << "Float: +inff" << std::endl;
        			std::cout << "Double: +inf" << std::endl;
				}
			}
			else
			{
				std::cout << "Float: NaNf" << std::endl;
				std::cout << "Double: NaN" << std::endl;
			}
		}
	}
    else if (toFloat(value) - toInt(value) == 0)
	{
		if(value.length() == 1 && (value[0] == '.' || value[0] == '+' || value[0] == '-'))
		{
			std::cout << "float: "<< static_cast<int>(value[0])  << "f" << std::endl;
			std::cout << "double: "<< static_cast<int>(value[0]) << ".0" << std::endl;
		}
		else
		{
			std::cout << "Float: " << toFloat(value) << ".0" << "f" << std::endl;
			std::cout << "Double: " << toDouble(value) << ".0"<< std::endl;
		}
	}
    else
	{
		std::cout << "Float: " << toFloat(value) << "f" << std::endl;
		std::cout << "Double: " << toDouble(value) << std::endl;
	}
}
