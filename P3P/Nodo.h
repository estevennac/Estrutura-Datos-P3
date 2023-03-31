#pragma once 
#include <iostream>


using namespace std;

class Nodo{

    public:
    int data;
    int color;
    Nodo* left;
    Nodo* right;
    Nodo* parent;

    public:
    Nodo(int data);
    ~Nodo();
    int getData();
    int getColor();
    Nodo* getLeft();
    Nodo* getRight();
    Nodo* getParent();
    void setData(int data);
    void setColor(int color);
    void setLeft(Nodo* left);
    void setRight(Nodo* right);
    void setParent(Nodo* parent);
    void print();
};