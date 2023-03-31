#pragma once
#include "AuxString.h"
#include "Lista.h"
class Operacion
{
public:
	std::string infix_a_prefix(std::string);
	string infix_a_postfix(string);
	string infix_a_funtional(string);
	string prefix_a_infix(string);
	string prefix_a_postfix(string);
	string prefix_a_funtional(string);
	string postfix_a_infix(string);
	string postfix_a_prefix(string);
	string postfix_a_funtional(string);
	bool is_operator(char);
	bool is_trig_fun(char);
	bool is_operand(char);
	int precedence(char);
	bool is_postfix(string);
	bool is_prefix(string);
	bool is_infix(string);
	bool has_parenthesis(string);
	double calcular(Lista<string> prefix);

};