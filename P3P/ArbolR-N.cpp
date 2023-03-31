#pragma once 
#include "Nodo.h"
#include "Nodo.cpp"
#include "ArbolR-N.h"
#include <Windows.h>
#include <fstream>


using namespace std;


ArbolRN ::ArbolRN(){
root = nullptr;
}

ArbolRN :: ~ArbolRN(){
           
}

int ArbolRN :: getColor(Nodo* p){
        if (p == nullptr)
            return BLACK;

        return p->color;
}

void ArbolRN :: setColor(Nodo*& p, int color){
        if (p == nullptr)
            return;

        p->color = color;
}

void ArbolRN :: rotateLeft(Nodo*& p){
        Nodo* child = p->right;
        p->right = child->left;

        if (p->right != nullptr)
            p->right->parent = p;

        child->parent = p->parent;

        if (p->parent == nullptr)
            root = child;
        else if (p == p->parent->left)
            p->parent->left = child;
        else
            p->parent->right = child;

        child->left = p;
        p->parent = child;
}

void ArbolRN ::rotateRight(Nodo*& p){
        Nodo* child = p->left;
        p->left = child->right;

        if (p->left != nullptr)
            p->left->parent = p;

        child->parent = p->parent;

        if (p->parent == nullptr)
            root = child;
        else if (p == p->parent->left)
            p->parent->left = child;
        else
            p->parent->right = child;

        child->right = p;
        p->parent = child;
}

void ArbolRN :: RebalanceInsert(Nodo*& p){
        Nodo* parent = nullptr;
        Nodo* grandparent = nullptr;
        while (p != root && getColor(p) == RED && getColor(p->parent) == RED)
        {
            parent = p->parent;
            grandparent = parent->parent;
            if (parent == grandparent->left)
            {
                Nodo* uncle = grandparent->right;
                if (getColor(uncle) == RED)
                {
                    setColor(uncle, BLACK);
                    setColor(parent, BLACK);
                    setColor(grandparent, RED);
                    p = grandparent;
                }
                else
                {
                    if (p == parent->right)
                    {
                        rotateLeft(parent);
                        p = parent;
                        parent = p->parent;
                    }
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    p = parent;
                }
            }
            else
            {
                Nodo* uncle = grandparent->left;
                if (getColor(uncle) == RED)
                {
                    setColor(uncle, BLACK);
                    setColor(parent, BLACK);
                    setColor(grandparent, RED);
                    p = grandparent;
                }
                else {
                    if (p == parent->left)
                    {
                        rotateRight(parent);
                        p = parent;
                        parent = p->parent;
                    }
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    p = parent;
                }
            }
        }
        setColor(root, BLACK);
}

Nodo* ArbolRN :: insertValue(Nodo* root, Nodo* p){
        if (root == nullptr)
            return p;

        if (root->data > p->data)
        {
            root->left = insertValue(root->left, p);
            root->left->parent = root;
        }
        else if (root->data <= p->data)
        {
            root->right = insertValue(root->right, p);
            root->right->parent = root;
        }

        return root;
        
}

Nodo* ArbolRN :: getMinValue(Nodo*& p){
        Nodo* min = p;

        while (min->left != nullptr)
            min = min->left;

        return min;
}

Nodo* ArbolRN :: getMaxValue(Nodo*& p){
        Nodo* max = p;

        while (max->right != nullptr)
            max = max->right;

        return max;
}

void ArbolRN :: RebalanceDelete(Nodo*& p){
        if (p == nullptr)
            return;

        if (p == root) {
            root = nullptr;
            return;
        }

        if (getColor(p) == RED || getColor(p->left) == RED || getColor(p->right) == RED) {
            Nodo* child = p->left != nullptr ? p->left : p->right;

            if (p == p->parent->left) {
                p->parent->left = child;
                if (child != nullptr)
                    child->parent = p->parent;
                setColor(child, BLACK);
                delete (p);
            }
            else {
                p->parent->right = child;
                if (child != nullptr)
                    child->parent = p->parent;
                setColor(child, BLACK);
                delete (p);
            }
        }
        else {
            Nodo* sibling = nullptr;
            Nodo* parent = nullptr;
            Nodo* temp = p;
            setColor(temp, DOUBLE_BLACK);
            while (temp != root && getColor(temp) == DOUBLE_BLACK) {
                parent = temp->parent;
                if (temp == parent->left) {
                    sibling = parent->right;
                    if (getColor(sibling) == RED) {
                        setColor(sibling, BLACK);
                        setColor(parent, RED);
                        rotateLeft(parent);
                    }
                    else {
                        if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {
                            setColor(sibling, RED);
                            if (getColor(parent) == RED)
                                setColor(parent, BLACK);
                            else
                                setColor(parent, DOUBLE_BLACK);
                            temp = parent;
                        }
                        else {
                            if (getColor(sibling->right) == BLACK) {
                                setColor(sibling->left, BLACK);
                                setColor(sibling, RED);
                                rotateRight(sibling);
                                sibling = parent->right;
                            }
                            setColor(sibling, parent->color);
                            setColor(parent, BLACK);
                            setColor(sibling->right, BLACK);
                            rotateLeft(parent);
                            break;
                        }
                    }
                }
                else {
                    sibling = parent->left;
                    if (getColor(sibling) == RED) {
                        setColor(sibling, BLACK);
                        setColor(parent, RED);
                        rotateRight(parent);
                    }
                    else {
                        if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {
                            setColor(sibling, RED);
                            if (getColor(parent) == RED)
                                setColor(parent, BLACK);
                            else
                                setColor(parent, DOUBLE_BLACK);
                            temp = parent;
                        }
                        else {
                            if (getColor(sibling->left) == BLACK) {
                                setColor(sibling->right, BLACK);
                                setColor(sibling, RED);
                                rotateLeft(sibling);
                                sibling = parent->left;
                            }
                            setColor(sibling, parent->color);
                            setColor(parent, BLACK);
                            setColor(sibling->left, BLACK);
                            rotateRight(parent);
                            break;
                        }
                    }
                }
            }
            if (p == p->parent->left)
                p->parent->left = nullptr;
            else
                p->parent->right = nullptr;
            delete(p);
            setColor(root, BLACK);
        }
}

Nodo* ArbolRN :: deleteValue(Nodo*& p, int val){
        if (p == nullptr)
            return p;

        if (val < p->data)
            return deleteValue(p->left, val);

        if (val > p->data)
            return deleteValue(p->right, val);

        if (p->left == nullptr || p->right == nullptr)
            return p;

        Nodo* temp = getMaxValue(p->left);
        p->data = temp->data;
        return deleteValue(p->left, temp->data);
}

Nodo* ArbolRN :: searchValue(Nodo* p, int val){
        if (p == nullptr || p->data == val)
            return p;
        else
            if (val >= p->data)
                return searchValue(p->right, val);
            else
                return searchValue(p->left, val);
}

void ArbolRN :: informationTree(Nodo*& p){
        if (p == nullptr)
            return;

        if (p->parent == nullptr)
            cout << p->data << (p->color ? "(NEGRO)" : "(ROJO)") << " es raiz principal" << endl;
        else if (p->parent->left == p)
            cout << p->data << (p->color ? "(NEGRO)" : "(ROJO)") << " es Hijo izquierdo de " << p->parent->data << (p->parent->color ? "(NEGRO)" : "(ROJO)")<<endl;
        else
            cout << p->data <<(p->color ? "(NEGRO)" : "(ROJO)") << " es Hijo derecho de " << p->parent->data  << (p->parent->color ? "(NEGRO)" : "(ROJO)")<<endl;
        informationTree(p->left);
        informationTree(p->right);
}

void ArbolRN :: printTree(const string& prefix, Nodo* p, bool isLeft, string outer, string inner, string mid, string end){
       int a=0;
        if (p != nullptr)
        {
            std::cout << prefix;

            if (!isLeft && p->parent == nullptr)
                std::cout <<mid;
            else if (isLeft && !p->parent->right)
                std::cout <<inner;
            else if (isLeft && p->parent->right)
                std::cout << outer;
            else if (!isLeft)
                std::cout << inner;

           if (p->color == RED){
            std::cout << "\033[1;31m" <<"("<< p->data<<")"<< "\033[0m"<<(p->color ? "-> NEGRO" :"-> ROJO") << endl;
            Beep(800,700);
           }else{
            cout << "("<<p->data<<")"<< (p->color ? "-> NEGRO" :"-> ROJO") << endl;
            Beep(700,700);
           }
            
            printTree(prefix + (isLeft ? end : "    "), p->left, true, outer, inner, mid, end);
            
            printTree(prefix + (isLeft ? end : "    "), p->right, false, outer, inner, mid, end);
            

        }
}

void ArbolRN :: insert(int val){
        Nodo* p = new Nodo(val);
        root = insertValue(root, p);
        RebalanceInsert(p);
}

void ArbolRN :: remove(int val){
        if (root == nullptr)
        {
            cout << "\tArbol Rojo - Negro esta vacio!\n";
            return;
        }

        Nodo* p = deleteValue(root, val);

        if (p != nullptr)
        {
            RebalanceDelete(p);
            cout << "\tValor " << val << " ha sido eliminado!\n";
        }
        else
            cout << "\tValor " << val << " no existe!\n";
}

void ArbolRN ::search(int val){
        if (root == nullptr)
        {
            cout << "\tRed Black Tree esta vacio!\n";
            return;
        }

        Nodo* p = searchValue(root, val);

        if (p == nullptr || p->data != val)
            cout << "\tValor " << val << " no existe!\n";
        else
            cout << "\tValor " << p->data << (p->color ? "(NEGRO)" : "(ROJO)") << " ha sido encontrado!\n";
}

void ArbolRN :: informationTree(){
        informationTree(root);
        cout << endl;
}

void ArbolRN :: preOrder(){
    preOrder(root);
    cout << endl;
}

void ArbolRN :: inOrder(){
    inOrder(root);
    cout << endl;
}

void ArbolRN :: postOrder(){
    postOrder(root);
    cout << endl;
}
void ArbolRN :: saveTreeTxt(){
    saveTreeTxt(root);
}

void ArbolRN :: saveTreeBin(){
    saveTreeBin(root);
}

void ArbolRN :: saveTreehtml(){
    saveTreehtml(root);
}



void ArbolRN ::print(){
    int a=0;
        if (root == nullptr)
        {
            cout << "\tArbol Rojo-Negro esta vacio!\n";
            return;
        }
        string inner(1, char(192));
        string outer(1, char(195));
        string mid(1, char(196));
        string end(1, char(179));

        string outer1 = outer + mid + mid + mid;
        string inner1 = inner + mid + mid + mid;
        string mid1 = mid + mid + mid + mid;
        string end1 = end + "   ";

        cout << endl;
        printTree("", root, false, outer1, inner1, mid1, end1);
        cout << endl;
}

void ArbolRN :: preOrder (Nodo* p){
        if (p == nullptr){
            return;
            cout << "No se encuentran datos en el arbol, \narbol vacio...\n";
        }else{
            cout << p->data << ",";
            preOrder(p->left);
            preOrder(p->right);
        }
}

void ArbolRN :: inOrder (Nodo* p){
        if (p == nullptr){
            return;
            cout << "No se encuentran datos en el arbol, \narbol vacio...\n";
        }else{
            inOrder(p->left);
            cout << p->data << ",";
            inOrder(p->right);
        }
}

void ArbolRN :: postOrder (Nodo* p){
        if (p == nullptr){
            return;
            cout << "No se encuentran datos en el arbol, \narbol vacio...\n";
        }else{
            postOrder(p->left);
            postOrder(p->right);
            cout << p->data << ",";
        }
}

void ArbolRN :: saveTreeTxt(Nodo* p){
    if (p == nullptr){
        return;
        cout << "No se encuentran datos en el arbol, \narbol vacio...\n";
    }else{
        ofstream archivo;
        archivo.open("ArbolRN.txt", ios::app | ios::out);
        if (archivo.fail()){
            cout << "No se pudo abrir el archivo";
            exit(1);
        }else{
            if (p->parent == nullptr)
            archivo << p->data << (p->color ? "(NEGRO)" : "(ROJO)") << " es raiz principal" << endl;
        else if (p->parent->left == p)
            archivo << p->data << (p->color ? "(NEGRO)" : "(ROJO)") << " es Hijo izquierdo de " << p->parent->data << (p->parent->color ? "(NEGRO)" : "(ROJO)")<<endl;
        else
            archivo << p->data <<(p->color ? "(NEGRO)" : "(ROJO)") << " es Hijo derecho de " << p->parent->data  << (p->parent->color ? "(NEGRO)" : "(ROJO)")<<endl;
            saveTreeTxt(p->left);
            saveTreeTxt(p->right);
        }
        archivo.close();
    }

}

void ArbolRN :: saveTreeBin(Nodo* p){
    if (p == nullptr){
        return;
        cout << "No se encuentran datos en el arbol, \narbol vacio...\n";
    }else{
        ofstream archivodat;
        archivodat.open("ArbolRN.dat", ios::out);
        if (archivodat.fail()){
            cout << "No se pudo abrir el archivo";
            exit(1);
        }else{
            if (p->parent == nullptr)
            archivodat.write((char*)&p->data, sizeof(int));
        else if (p->parent->left == p)
            archivodat.write((char*)&p->data, sizeof(int)); 
        else
            archivodat.write((char*)&p->data, sizeof(int));
            saveTreeBin(p->left);
            saveTreeBin(p->right);
        }
        archivodat.close();
    }
}
void ArbolRN :: saveTreehtml(Nodo* p){
    ofstream archivo;
    archivo.open("Datos_del_arbol.html");
    archivo<<"<!DOCTYPE html>"<<endl;
    archivo<<"<html>"<<endl;
    archivo<<"<head>"<<endl;
    archivo<<"<title>Datos del Arbol Rojo-Negro</title>"<<endl;
    archivo<<"</head>"<<endl;
    archivo<<"<body>"<<endl;
    archivo<<"<h1>Datos del Arbol Rojo-Negro</h1>"<<endl;
    archivo<<"</tr>"<<endl;
    archivo<<"<table>"<<endl;
    archivo<<"<tr>"<<endl;
    archivo<<"<th>Valor ingresado</th>"<<endl;
    archivo<<"<th>Color</th>"<<endl;
    archivo<<"<th>Informacion</th>"<<endl;
    archivo<<"</tr>"<<endl;
    if (p == nullptr){
        cout << "No se encuentran datos en el arbol, \narbol vacio...\n";
    }else{
        if (p->parent == nullptr){
                archivo<<"<tr>"<<endl;
                archivo<<"<td>"<<p->data<<"</td>"<<endl;
                archivo<<"<td>"<<(p->color ? "(NEGRO)" : "(ROJO)")<<"</td>"<<endl;
                archivo<<"<td>"<<"Raiz Principal"<<"</td>"<<endl;
                archivo<<"<tr>"<<endl;
                archivo<<"<td>"<<p->data<<"</td>"<<endl;
                archivo<<"<td>"<<(p->color ? "(NEGRO)" : "(ROJO)") <<"</td>"<<endl;
                archivo<<"<td>"<<"Hijo izquierdo de " << p->parent->data << (p->parent->color ? "(NEGRO)" : "(ROJO)")<<"</td>"<<endl;
                archivo<<"<tr>"<<endl;
                archivo<<"<td>"<< p->data<<"</td>"<<endl;
                archivo<<"<td>"<<(p->color ? "(NEGRO)" : "(ROJO)") <<"</td>"<<endl;
                archivo<<"<td>"<<"Hijo derecho de " << p->parent->data  << (p->parent->color ? "(NEGRO)" : "(ROJO)")<<"</td>"<<endl; 
            saveTreehtml(p->left);
            saveTreehtml(p->right);
        }
    }
    archivo<<"</tr>"<<endl; 
    archivo<<"</table>"<<endl;
    archivo<<"</body>"<<endl;
    archivo<<"</html>"<<endl;
    archivo.close();
    
}
