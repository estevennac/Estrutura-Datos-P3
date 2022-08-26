#ifndef INPUT_HPP
#define INPUT_HPP

class Input {

    public:
        static int unsignedIntegerNumber(short minimumDigits, short maximumDigits);
        static double unsignedRealNumber(short minimumDigits, short maximumDigits);
        static int integerNumber(short minimumDigits, short maximumDigits);
        static double realNumber(short minimumDigits, short maximumDigits);
        static char *word(short minimumCharacters, short maximumCharacters);
        static char *digits(short minimumDigits, short maximumDigits);
        static char *alphabetic(short minimumLetters, short maximumLetters);
        static char *alphanumeric(short minimumCharacters, short maximumCharacters);
};

#endif