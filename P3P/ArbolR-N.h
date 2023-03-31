#pragma once 
#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"

using namespace std;

class ArbolRN{
private:
    Nodo* root;
    int getColor(Nodo* );
    void setColor(Nodo*& , int );
    void rotateLeft(Nodo*& );
    void rotateRight(Nodo*& );
    void RebalanceInsert(Nodo*& );
    Nodo* insertValue(Nodo* , Nodo* );
    Nodo* getMinValue(Nodo*& );
    Nodo* getMaxValue(Nodo*& );
    void RebalanceDelete(Nodo*& );
    Nodo* deleteValue(Nodo*& , int );
    Nodo* searchValue(Nodo* , int );
    void informationTree(Nodo*& );
    void printTree(const string& , Nodo* , bool , string , string , string , string );
    void preOrder(Nodo* );
    void inOrder(Nodo* );
    void postOrder(Nodo* );
    void saveTreeTxt(Nodo* );
    void saveTreeBin(Nodo* );
    void saveTreehtml(Nodo* );
public:
    ArbolRN();
    void insert(int );
    void remove(int );
    void search(int );
    void informationTree();
    void preOrder();
    void inOrder();
    void postOrder();
    void print();
    void saveTreeTxt();
    void saveTreeBin();
    void saveTreehtml();
    ~ArbolRN();
};