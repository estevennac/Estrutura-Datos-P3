#pragma once 
#include "Nodo.h"
#include <iostream>

using namespace std;

enum Color { RED, BLACK, DOUBLE_BLACK };

Nodo :: Nodo(int data){
    this->data = data;
    color = RED;
    left = right = parent = nullptr;
}

Nodo :: ~Nodo(){
    delete left;
    delete right;
}
int Nodo :: getData(){
    return data;
}
int Nodo :: getColor(){
    return color;
}
Nodo *Nodo :: getLeft(){
    return left;
}
Nodo *Nodo :: getRight(){
    return right;
}
Nodo *Nodo :: getParent(){
    return parent;
}
void Nodo :: setData(int data){
    this->data = data;
}
void Nodo :: setColor(int color){
    this->color = color;
}
void Nodo :: setLeft(Nodo* left){
    this->left = left;
}
void Nodo :: setRight(Nodo* right){
    this->right = right;
}
void Nodo :: setParent(Nodo* parent){
    this->parent = parent;
}
void Nodo :: print(){
    cout << "Data: " << data << " Color: " << color << endl;
}






