#include "stringManip.h"

string twoDigitString(unsigned int n) {
    string twoDigit;
    if (n < 10) {
        twoDigit.append("0");
    }
    twoDigit.append(to_string(n));
    return twoDigit;
}

string nCharString(size_t n, char c) {
    // Reference: https://cplusplus.com/reference/string/string/string/
    string charString(n, c);
    return charString;
}

string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}


string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string suffix = " A M";

    if (h > 11) {
        suffix = " P M";
        h = h - 12;
    }
    (h == 0) ? h = 12 : h;

    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + suffix;
}
