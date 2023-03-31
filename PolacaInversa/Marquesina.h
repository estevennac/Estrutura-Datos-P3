#pragma once
#include <iostream>
#include <string.h>
#include <windows.h>
#include <thread>
#include <conio.h>
using namespace std;

class Marquesina
{
public:

    Marquesina(string);
    void OcultarCursor();
    void imprimirCoordenadas(int x, int y, string format, ...);
    COORD obtenerPosicionCursorConsol(HANDLE hConsoleOutput);
    void marquesina1();
    void transicion();
private:
    string marquesina;
    int index = 0;
};

Marquesina::Marquesina(string mrq)
{
    this->marquesina = mrq;
}

void Marquesina::OcultarCursor()
{
    HANDLE hwnd;
    hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;

    info.bVisible = 0;
    info.dwSize = 1;

    SetConsoleCursorInfo(hwnd, &info);
}

void Marquesina::imprimirCoordenadas(int x, int y, string format, ...)
{
    const char* c = format.c_str();
    va_list args;
    va_start(args, format);
    printf("\033[%d;%dH", x, y);
    vprintf(c, args);
    va_end(args);
    fflush(stdout);
}

COORD Marquesina::obtenerPosicionCursorConsol(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        COORD invalid = { 0, 0 };
        return invalid;
    }
}

void Marquesina::marquesina1()
{
    string logo = marquesina;
    int velocidad = 600;
    Sleep(600);
    //OcultarCursor();
    int stringSize = logo.length();
    string msg;
    bool ciclo = true;
    for (index; ciclo == true; index++)
    {
        msg = "\t\t\t\t" + logo.substr(index % stringSize) + logo.substr(0, index % stringSize);
        imprimirCoordenadas(0, 0, msg);
        Sleep(velocidad);
        if (GetAsyncKeyState(VK_SPACE)) {
            ciclo = false;
            break;
        }
    }
}

void Marquesina::transicion()
{
    COORD cord;
    cord = obtenerPosicionCursorConsol(GetStdHandle(STD_OUTPUT_HANDLE));
    std::thread t1(&Marquesina::marquesina1, this);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
    //system("pause");
    t1.join();
    cord.Y++;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}
