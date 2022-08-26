#include "Operacion.h"
using namespace std;
#include <string>
#include <cstring>
#include <cstdlib>

std::string Operacion::infix_a_prefix(std::string infix)
{
    Lista<char> lista;
    AuxString str;
    string cad = str.reves(infix);
    string result, prefix;
    string aux;
    char anterior = '.';
    for (char& character : cad) {
        if (character == '(') {
            character = ')';
        }
        else if (character == ')') {
            character = '(';
        }
    }
    infix = cad;
    for (char& character : infix) {
        //if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
        if ((character >= 'a' && character <= 'z' || character >= '0' && character <= '9')) {
            prefix += character;
        }
        else if (character == '(') {
            lista.insertar_por_la_cabeza(character);
        }
        else if (character == ')') {
            while ((lista.get_primero()->get_dato() != '(') && (!lista.empty_stack())) {
                prefix += lista.get_primero()->get_dato();
                lista.borrar_por_la_cabeza();
            }

            if (lista.get_primero()->get_dato() == '(') {
                lista.borrar_por_la_cabeza();
            }
        }
        else if (is_operator(character)) {
            if (lista.empty_stack()) {
                lista.insertar_por_la_cabeza(character);
            }
            else {
                if (precedence(character) > precedence(lista.get_primero()->get_dato())) {
                    lista.insertar_por_la_cabeza(character);
                }
                else if ((precedence(character) == precedence(lista.get_primero()->get_dato()))
                    && (character == '^')) {
                    while ((precedence(character) == precedence(lista.get_primero()->get_dato()))
                        && (character == '^')) {
                        prefix += lista.get_primero()->get_dato();
                        lista.borrar_por_la_cabeza();
                    }
                    lista.insertar_por_la_cabeza(character);
                }
                else if (precedence(character) == precedence(lista.get_primero()->get_dato())) {
                    lista.insertar_por_la_cabeza(character);
                }
                else {
                    while ((!lista.empty_stack()) && (precedence(character) < precedence(lista.get_primero()->get_dato()))) {
                        prefix += lista.get_primero()->get_dato();
                        lista.borrar_por_la_cabeza();
                    }
                    lista.insertar_por_la_cabeza(character);
                }
            }
        }
        else if (is_trig_fun(character) && anterior == ')') {
            prefix += character;
        }
        anterior = character;
    }

    while (!lista.empty_stack()) {
        prefix += lista.get_primero()->get_dato();
        lista.borrar_por_la_cabeza();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}




string Operacion::infix_a_postfix(string infix)
{
    string prefix = infix_a_prefix(infix);
    string postfix = prefix_a_postfix(prefix);
    return postfix;

}

int Operacion::precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 2;
    else if (c == '<' || c == '>' || c == '=')
        return 4;
    else
        return -1;
}

string Operacion::infix_a_funtional(string expression)
{
    string expression1 = infix_a_prefix(expression);
    string expression2 = prefix_a_funtional(expression1);

    return expression2;
}

string Operacion::prefix_a_infix(string prefix)
{
    AuxString str;
    string cad = str.reves(prefix);
    //string result, prefix;
    string aux, aux2;
    string charac = "";
    char anterior = '.';
    Lista<string> stack;


    for (char& character : cad) {
        if (is_operand(character)) {

            charac.push_back(character);
            stack.insertar_por_la_cabeza(charac);
            charac = "";
        }
        else if (character == '+' || character == '-') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + character + aux2);

        }
        else if (character == '*' || character == '/') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.longitud(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.longitud(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux + character + aux2 + ")");
        }
        else if (character == '%') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.longitud(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.longitud(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux + character + aux2 + ")");
        }
        else if (character == '^') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.longitud(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.longitud(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux + character + aux2 + ")");
        }
        else if (character == '<' || character == '>' || character == '=') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.longitud(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.longitud(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux + character + aux2 + ")");
        }
        else if (is_trig_fun(character)) {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();

            if (str.longitud(aux) == 1) {
                charac.push_back(character);
                stack.insertar_por_la_cabeza(charac + "(" + aux + ")");
                charac = "";
            }
            else if (str.extraer(aux, 0, 1) == "(") {
                stack.insertar_por_la_cabeza(character + aux);
            }
            else {
                stack.insertar_por_la_cabeza(character + "(" + aux + ")");
            }
        }

    }
    return stack.get_primero()->get_dato();
}

/*string Operation::prefix_to_postfix(string expression1)
{
    string expression2 = prefix_to_infix(expression1);
    string expression3 = infix_to_postfix(expression2);
    return expression3;
}*/
string Operacion::prefix_a_postfix(string prefix)
{
    AuxString str;
    string cad = str.reves(prefix);
    //string result, prefix;
    string aux, aux2;
    string charac = "";
    char anterior = '.';
    Lista<string> stack;

    for (char& character : cad) {
        if (is_operand(character)) {

            charac.push_back(character);
            stack.insertar_por_la_cabeza(charac);
            charac = "";
        }
        else if (character == '+') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "+");

        }
        else if (character == '-') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "-");

        }
        else if (character == '*') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "*");

        }
        else if (character == '/') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "/");

        }
        else if (character == '%') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "%");

        }
        else if (character == '^') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "^");

        }
        else if (character == '<') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "<");

        }
        else if (character == '>') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + ">");

        }
        else if (character == '=') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "=");

        }
        else if (character == 'T') {
            charac.push_back(character);

            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + "T");
            charac = "";
        }
        else if (character == 'S') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + "S");
        }
        else if (character == 'C') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + "C");
        }

    }
    return stack.get_primero()->get_dato();

}


string Operacion::prefix_a_funtional(string prefix)
{
    AuxString str;
    string cad = str.reves(prefix);
    //string result, prefix;
    string aux, aux2;
    string charac = "";
    char anterior = '.';
    Lista<string> stack;

    for (char& character : cad) {
        if (is_operand(character)) {

            charac.push_back(character);
            stack.insertar_por_la_cabeza(charac);
            charac = "";
        }
        else if (character == '+') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("SUMA(" + aux + "," + aux2 + ")");

        }
        else if (character == '-') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("RESTA(" + aux + "," + aux2 + ")");

        }
        else if (character == '*') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("MULTIPLICACION(" + aux + "," + aux2 + ")");

        }
        else if (character == '/') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("DIVISION(" + aux + "," + aux2 + ")");

        }
        else if (character == '%') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("MODULO(" + aux + "," + aux2 + ")");

        }
        else if (character == '^') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("POTENCIA(" + aux + "," + aux2 + ")");

        }
        else if (character == '<') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("MENOR(" + aux + "," + aux2 + ")");

        }
        else if (character == '>') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("MAYOR(" + aux + "," + aux2 + ")");

        }
        else if (character == '=') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("IGUAL(" + aux + "," + aux2 + ")");

        }
        else if (character == 'T') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("TANGENTE(" + aux + ")");
        }
        else if (character == 'S') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("SENO(" + aux + ")");
        }
        else if (character == 'C') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("COSENO(" + aux + ")");
        }

    }
    return stack.get_primero()->get_dato();
}

string Operacion::postfix_a_infix(string expression)
{
    AuxString str;
    string aux, aux2;
    string charac = "";
    Lista<string> stack;
    for (char& character : expression) {
        if (is_operand(character)) {

            charac.push_back(character);
            stack.insertar_por_la_cabeza(charac);
            charac = "";
        }
        else if (character == '+' || character == '-') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux2 + character + aux);

        }
        else if (character == '*' || character == '/' || character == '%') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.longitud(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.longitud(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux2 + character + aux + ")");
        }
        else if (character == '<' || character == '>' || character == '=') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.longitud(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.longitud(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux2 + character + aux + ")");
        }
        else if (character == '^') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.longitud(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.longitud(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux2 + character + aux + ")");
        }
        else if (is_trig_fun(character)) {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();

            if (str.longitud(aux) == 1) {
                charac.push_back(character);
                stack.insertar_por_la_cabeza(charac + "(" + aux + ")");
                charac = "";
            }
            else if (str.extraer(aux, 0, 1) == "(") {
                stack.insertar_por_la_cabeza(character + aux);
            }
            else {
                stack.insertar_por_la_cabeza(character + "(" + aux + ")");
            }
        }
    }
    return stack.get_primero()->get_dato();
}

string Operacion::postfix_a_prefix(string postfix)
{
    string expression = postfix_a_infix(postfix);
    string expression1 = infix_a_prefix(expression);
    //mystring str;
    //string cad = postfix;
    //string aux, aux2;
    //string charac = "";
    //char anterior = '.';
    //Stack<string> stack;

    //for (char& character : cad) {
    //    //stack.mostrar();
    //    //cout << endl;
    //    if (is_operand(character)) {

    //        charac.push_back(character);
    //        stack.insertar_por_la_cabeza(charac);
    //        charac = "";
    //    }
    //    else if (is_operator(character)) {
    //        //cout << character << endl;
    //        aux = stack.get_primero()->get_dato();
    //        stack.borrar_por_la_cabeza();
    //        aux2 = stack.get_primero()->get_dato();
    //        stack.borrar_por_la_cabeza();
    //        charac.push_back(character);
    //        stack.insertar_por_la_cabeza( aux2 + aux+charac);
    //        charac = "";
    //    }
    //    else if (is_trig_fun(character)) {
    //        aux = stack.get_primero()->get_dato();
    //        stack.borrar_por_la_cabeza();
    //        charac.push_back(character);
    //        stack.insertar_por_la_cabeza(aux+charac);
    //        charac = "";
    //    }

    //}
    //return stack.get_primero()->get_dato();
    return expression1;
}

string Operacion::postfix_a_funtional(string expression)
{
    string expression1 = postfix_a_prefix(expression);
    cout << expression1 << endl;
    string expression2 = prefix_a_funtional(expression1);
    return expression2;
}

bool Operacion::is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '<' || c == '>' || c == '=') {
        return true;
    }
    return false;
}

bool Operacion::is_trig_fun(char c)
{
    if (c == 'S' || c == 'C' || c == 'T') {
        return true;
    }
    return false;
}

bool Operacion::is_operand(char c)
{
    if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

bool Operacion::is_postfix(string expression)
{
    AuxString str;
    int lenth = str.longitud(expression);
    char c = str.poner_en(1, expression);
    char c2 = str.poner_en(lenth, expression);
    if (!has_parenthesis(expression) && is_operand(c) && (is_operator(c2) || is_trig_fun(c2)))
        return true;
    else
        return false;
}

bool Operacion::is_infix(string expression)
{
    AuxString str;
    int lenth = str.longitud(expression);
    char c = str.poner_en(1, expression);
    char c2 = str.poner_en(lenth, expression);
    if (is_operator(c) || is_operator(c2) || is_trig_fun(c2))
        return false;
    else
        return true;
}

bool Operacion::is_prefix(string expression)
{
    AuxString str;
    int lenth = str.longitud(expression);
    char c = str.poner_en(1, expression);
    char c2 = str.poner_en(lenth, expression);
    if (!has_parenthesis(expression) && is_operand(c2) && (is_operator(c) || is_trig_fun(c)))
        return true;
    else
        return false;
}

bool Operacion::has_parenthesis(string expression)
{
    for (char& cad : expression)
    {
        if (cad == '(' || cad == ')')
            return true;
        else
            return false;
    }
}