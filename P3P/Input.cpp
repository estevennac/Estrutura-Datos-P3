#pragma once
#include "Input.h"
#include <iostream>
#include <conio.h>


int Input::unsignedIntegerNumber(short minimumDigits, short maximumDigits) {
    if (minimumDigits <= 0 || maximumDigits >= 10)
        throw "DigitsOutOfBoundsException";

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (std::isdigit((keyPressed)) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            digitsAmount--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atoi(numbers);
}

double Input::unsignedRealNumber(short minimumDigits, short maximumDigits) {
    if (minimumDigits <= 0 || maximumDigits >= 15)
        throw "DigitsOutOfBoundsException";


    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 2]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};
    bool hasEnteredADot{false};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (keyPressed == '.' && iterator != numbers && !hasEnteredADot) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

            hasEnteredADot = true;

        } else if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            iterator--;

            if (*iterator == '.') {
                hasEnteredADot = false;
            } else {
                digitsAmount--;
            }

            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atof(numbers);
}

int Input::integerNumber(short minimumDigits, short maximumDigits) {
    if (minimumDigits <= 0 || maximumDigits >= 10)
        throw "DigitsOutOfBoundsException";

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 2]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (keyPressed == '-' && iterator == numbers) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            iterator--;
            
            if (*iterator != '-')
                digitsAmount--;

            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atoi(numbers);
}

double Input::realNumber(short minimumDigits, short maximumDigits) {
    if (minimumDigits <= 0 || maximumDigits >= 15)
        throw "DigitsOutOfBoundsException";

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 3]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};
    bool hasEnteredADot{false};

    
    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {

        if (keyPressed == '-' && iterator == numbers) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (keyPressed == '.' && iterator != numbers && !hasEnteredADot) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

            hasEnteredADot = true;

        } else if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            iterator--;
            
            if (*iterator == '.') {
                hasEnteredADot = false;
            } else if (*iterator != '-') {
                digitsAmount--;
            }


            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atof(numbers);
}

char *Input::word(short minimumCharacters, short maximumCharacters) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *string = new char[maximumCharacters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0' || sizeOfString < minimumCharacters) {

        if (std::isalpha(keyPressed) && sizeOfString < maximumCharacters) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != string) {
            printf("\b \b");

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return string;
}

char *Input::digits(short minimumDigits, short maximumDigits) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            digitsAmount--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return numbers;
}

char *Input::alphabetic(short minimumLetters, short maximumLetters) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};
    const char SPACE_KEY{32};

    char *string = new char[maximumLetters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0' || sizeOfString < minimumLetters) {

        if (keyPressed == SPACE_KEY && iterator != string && sizeOfString < maximumLetters) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (std::isalpha(keyPressed) && sizeOfString < maximumLetters) {

            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != string) {
            printf("\b \b");

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    // Limpiando espacios en blanco despues del ultimo caracter alfabetico
    if (*(iterator - 1) == SPACE_KEY) {
        while (*(--iterator) == SPACE_KEY) {
            *iterator = '\0';
        }
    }

    printf("\n");

    return string;
}

char *Input::alphanumeric(short minimumCharacters, short maximumCharacters) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};
    const char SPACE_KEY{32};

    char *string = new char[maximumCharacters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0' || sizeOfString < minimumCharacters) {

        if (keyPressed == SPACE_KEY && iterator != string && sizeOfString < maximumCharacters) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (std::isalnum(keyPressed) && sizeOfString < maximumCharacters) {

            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != string) {
            printf("\b \b");

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    if (*(iterator - 1) == SPACE_KEY) {
        while (*(--iterator) == SPACE_KEY) {
            *iterator = '\0';
        }
    }

    printf("\n");

    return string;
}