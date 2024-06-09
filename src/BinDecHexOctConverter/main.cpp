#include <iostream>
#include <string>
#include "Converter/ConverterBase.h"
#include "NumberBaseConverterFactory.h"

using namespace std;
using namespace NumberBaseConverter;

bool argumentCountValid(int argc) {
    if (argc != 2) {
        cout << "Usage:"        << endl;
        cout << "   hdc NUMBER" << endl;
        cout << "Example"       << endl;
        cout << "   hdc 10"     << endl;
        cout << "   hdc 0x10"   << endl << endl;
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
        }
    }

    NumberBaseConverterFactory cConverterFactory;
    ConverterBase* cpConverter = cConverterFactory.GetConverter(strBase);

    if (strBase != "hex") cout << "0x" << cpConverter->ConvertToHexadecimal(strInpt) << endl;
    if (strBase != "dec") cout         << cpConverter->ConvertToDecimal(strInpt)     << endl;

    return 0;
}
