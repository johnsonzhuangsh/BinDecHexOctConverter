#include <iostream>
#include <string>
#include "Converter/ConverterBase.h"
#include "NumberBaseConverterFactory.h"

using namespace std;
using namespace NumberBaseConverter;

bool argumentCountValid(int argc) {
    if (argc != 2) {
        cout << "Usage:"        << endl;
        cout << "   hdob NUMBER" << endl;
        cout << "Example"       << endl;
        cout << "   hdob 10"     << endl;
        cout << "   hdob 0b10"   << endl;
        cout << "   hdob 0o10"   << endl;
        cout << "   hdob 0x10"   << endl << endl;
        return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    if (!argumentCountValid(argc)) {
        return -1;
    }

    // Get base based on input number
    // Ref: https://stackoverflow.com/questions/8454228/how-can-i-get-the-nth-character-of-a-string
    std::string strBase = "dec";
    std::string strInpt = string(argv[1]);
    if (strInpt.length() > 1) {
        if (strInpt[1] == 'x') {
            strBase = "hex";
        } else if (strInpt[1] == 'o') {
            strBase = "oct";
        } else if (strInpt[1] == 'b') {
            strBase = "bin";
        }
    }

    NumberBaseConverterFactory cConverterFactory;
    ConverterBase* cpConverter = cConverterFactory.GetConverter(strBase);

    if (strBase != "hex") cout << "Hex(0x)\t" << cpConverter->ConvertToHexadecimal(strInpt) << endl;
    if (strBase != "dec") cout << "Dec(0d)\t" << cpConverter->ConvertToDecimal(strInpt)     << endl;
    if (strBase != "oct") cout << "Oct(0o)\t" << cpConverter->ConvertToOctal(strInpt)       << endl;
    if (strBase != "bin") cout << "Bin(0b)\t" << cpConverter->ConvertToBinary(strInpt)      << endl;

    return 0;
}
