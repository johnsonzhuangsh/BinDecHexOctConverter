
#include <cstdio>
#include <sstream>
#include "DecimalConverter.h"
using namespace std;

namespace NumberBaseConverter
{
    /* Region Public Methods */

    string DecimalConverter::ConvertToBinary(string decStr)
    {
        int number = parseIntFromString(decStr);
        return convertNumber(number, 2);
    }

    string DecimalConverter::ConvertToHexadecimal(string decStr)
    {
        int number = parseIntFromString(decStr);
        return convertNumber(number, 16);
    }

    string DecimalConverter::ConvertToOctal(string decStr)
    {
        int number = parseIntFromString(decStr);
        return convertNumber(number, 8);
    }

    /* End Region Public Methods */

    /* Region Private Methods */

    // Recursively convert the number per the base from MSB to LSB digit by digit
    string DecimalConverter::convertNumber(int number, int base) {

        // If > 1 base, then do the MSB side first
        string numRep("");
        if (number / base != 0) {
            numRep.append(convertNumber(number / base, base));
        }

        // Current recursive step digit
        char chCurrDigit[1];
        int iCurrDigitVal = number % base;
        if (base == 16 && iCurrDigitVal >= 10) {   // Case where the digit could be 2 chars, look up table to convert to 1 digit
            switch (iCurrDigitVal) {
            case 10:
                chCurrDigit[0] = 'A';
                break;
            case 11:
                chCurrDigit[0] = 'B';
                break;
            case 12:
                chCurrDigit[0] = 'C';
                break;
            case 13:
                chCurrDigit[0] = 'D';
                break;
            case 14:
                chCurrDigit[0] = 'E';
                break;
            default:
                chCurrDigit[0] = 'F';
                break;
            }
        } else {
            sprintf(chCurrDigit, "%d", number % base);
        }
        numRep.append(chCurrDigit);

        return numRep;
    }

    int DecimalConverter::parseIntFromString(string number)
    {
        int decNumber;
        stringstream ss;
        ss << std::dec << number;
        ss >> decNumber;

        return decNumber;
    }

    /* End Region Private Methods */
} // end namespace
