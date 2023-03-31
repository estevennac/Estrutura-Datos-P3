#include "AuxString.h"
#include <iostream>
using namespace std;
double AuxString::potencia(double num, double pot)
{
    double result = 1;
    if (pot == 0) {
        return 1;
    }
    if (pot == 1) {
        return num;
    }
    if (pot == 0.5) {
        double raiz = 0;
        while ((num - raiz * raiz) > 0.00001) {
            raiz = raiz + 0.00001;
        }

        return raiz;
    }
    for (int i = 0; i < pot; i++) {
        result = result * num;
    }
    return result;
}
double AuxString::stod(string cad)
{

    if (is_number(cad)) {
        if (encontrarChar(cad, '.', 0) == -1) {
            long num = 0;
            num = stol(cad);
            double num1 = double(num);
            return num1;
        }
        else if (encontrarChar(cad, '.', 0) == 0) {
            string cad1 = extraer(cad, 1, longitud(cad) - 1);
            long num = 0;
            num = stol(cad1);
            double num1 = double(num) / potencia(10, double(longitud(cad1)));
            return num1;
        }
        else {
            int pos = encontrarChar(cad, '.', 0);
            string cad1 = extraer(cad, 0, pos) + extraer(cad, pos + 1, longitud(cad)- pos + 1);
            long num = 0;
            num = stol(cad1);
            double num1 = double(num) / potencia(10, double(longitud(cad1) - pos));
            return num1;
        }
    }
    return 0.0;
}
/*long AuxString::stol(string cad)
{
    long r = 0;
    int dato = 0;
    int cont = 0;
    if (extraer(cad, 0, 1) == "-") {

        for (char& c : cad) {
            if (cont > 0) {
                dato = atoi(c);
                r = r * 10 + dato;

            }
            cont++;

        }
        r = r * -1;
    }
    else {
        for (char& c : cad) {
            dato = atoi(c);
            r = r * 10 + dato;

        }
    }
    return r;
}*/

bool AuxString::is_number(string cad)
{
    int points = 0;
    int charac = 0;
    int negative = 0;
    for (char& c : cad) {
        if (c == '.') {
            points++;
        }
        else if (c == '-') {
            negative++;
        }
        else if (c > '9' || c < '0') {
            charac++;
        }


    }
    if (points > 1) {
        return false;
    }
    if (negative > 1) {
        return false;
    }
    else if (negative == 1 && extraer(cad, 0, 1) != "-") {
        return false;
    }
    if (negative == 1 && longitud(cad) == 1) {
        return false;
    }
    if (charac > 0) {
        return false;
    }
    return true;
}
char AuxString::inferior(char character)
{
    if (character >= 65 && character <= 90) {
        return character + 32;
    }
    return character;
}

char AuxString::superior(char character)
{
    if (character >= 97 && character <= 122) {
        return character - 32;
    }
    return character;
}

string AuxString::aMayuscula(string cad)
{
    for (char& c : cad) {
        c = superior(c);
    }
    return cad;
}

string AuxString::aMinuscula(string cad)
{
    for (char& c : cad) {
        c = inferior(c);
    }
    return cad;
}

int AuxString::encontrarChar(string cad, char character, int position_initial)
{
    int position_found = -1;
    int cont = 0;
    for (char& c : cad) {
        if (cont >= position_initial && c == character) {
            return cont;
        }
        cont++;
    }

    return position_found;
}

int AuxString::buscar(string cad, string cadEncontrar, int position_initial)
{

    string data;
    for (int i = 0; i < longitud(cad); i++) {
        data = extraer(cad, i, longitud(cadEncontrar));
        if (igual(data, cadEncontrar) && i >= position_initial) {
            return i;
        }
    }
    return -1;
}

int AuxString::longitud(string cad)
{
    int size = 0;
    for (char& c : cad) {
        size++;
    }

    return size;
}

string AuxString::extraer(string cad, int position_initial, int number_character)
{
    string cad_sub;
    int cont = 0;
    int cont_ch = 1;
    for (char& c : cad) {
        if (cont >= position_initial && cont < (position_initial + number_character)) {
            if (c == ' ') {
                cad_sub += " ";
            }
            else {
                cad_sub += c;
            }

        }
        cont++;

    }
    return cad_sub;
}

bool AuxString::igual(string cad1, string cad2)
{
    if (longitud(cad1) != longitud(cad2)) {
        return false;
    }
    bool flag = false;
    int cont = 0;
    for (int i = 0; i < longitud(cad1); i++) {
        if (extraer(cad1, i, 1) == extraer(cad2, i, 1)) {
            cont++;
        }
    }
    if (cont == longitud(cad1)) {
        flag = true;
    }
    return flag;
}

int AuxString::atoi(char character)
{
    if (character >= 48 && character <= 57) {
        return character - 48;
    }
    return 0;
}

int AuxString::stoi(string cad)
{
    int r = 0;
    int dato = 0;
    int cont = 0;
    if (extraer(cad, 0, 1) == "-") {

        for (char& c : cad) {
            if (cont > 0) {
                dato = atoi(c);
                r = r * 10 + dato;

            }
            cont++;

        }
        r = r * -1;
    }
    else {
        for (char& c : cad) {
            dato = atoi(c);
            r = r * 10 + dato;

        }
    }
    return r;
}

/*long AuxString::stol(string cad)
{
    long r = 0;
    int dato = 0;
    int cont = 0;
    if (extraer(cad, 0, 1) == "-") {

        for (char& c : cad) {
            if (cont > 0) {
                dato = atoi(c);
                r = r * 10 + dato;

            }
            cont++;

        }
        r = r * -1;
    }
    else {
        for (char& c : cad) {
            dato = atoi(c);
            r = r * 10 + dato;

        }
    }
    return r;
}*/

string AuxString::reves(string cad)
{
    string cad_inverse;
    string aux;
    for (char& c : cad) {
        aux.push_back(c);
        cad_inverse = aux + cad_inverse;
        aux = "";

    }
    return cad_inverse;
}

char AuxString::poner_en(int posicion, string cad)
{
    const char* p = cad.c_str();
    char c = ' ';
    if (posicion <= longitud(cad)) {
        for (int i = 0; i < posicion; i++)
        {
            c = *p;
            p++;
        }
    }
    else {
        cout << "La posicion ingresada excede el tamaño de la cadena." << endl;
    }
    return c;
}