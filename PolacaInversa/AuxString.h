#pragma once
#include <string>
using namespace std;
class AuxString
{
public:
	char inferior(char);
	char superior(char);
	string aMayuscula(string);
	string aMinuscula(string);
	int encontrarChar(string, char, int);
	int buscar(string, string, int);
	int longitud(string);
	string extraer(string, int, int);
	bool igual(string, string);
	int atoi(char);
	int stoi(string);
	string reves(string);
	char poner_en(int, string);
	//long stol(string cad);
	double stod(string cad);
	double potencia(double num, double pot);
	bool is_number(string cad);
};