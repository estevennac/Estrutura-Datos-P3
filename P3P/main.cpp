/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
ESTRUCTURA DE DATOS

Integrantes: Grupo 10 & Grupo 18

NRC: 4698

Tema: Arboles Rojo-Negro

*/

#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <thread>
#include <string>
#include "ArbolR-N.h"
#include "ArbolR-N.cpp"
#include <windows.h>
#include <conio.h>
#include <fstream>
#include "menu.h"
#include "menu.cpp"
#include "menu_option.h"
#include "menu_option.cpp"
#include "registro.h"
#include "Input.h"
#include "Input.cpp"


using namespace std;

void menu(ArbolRN RBTree);
void subMenu(ArbolRN RBTree);
void extrasMenu(ArbolRN RBTree);
void askForMenu(ArbolRN RBTree);
void insert(ArbolRN RBTree);
void remove(ArbolRN RBTree);
void search(ArbolRN RBTree);
void print(ArbolRN RBTree);
void preOrder(ArbolRN RBTree);
void inOrder(ArbolRN RBTree);
void postOrder(ArbolRN RBTree);
void converTxtToPdf();

void marquee(std::string text) {
    HANDLE conhandler = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ancho, alto;
    GetConsoleScreenBufferInfo(conhandler, &csbi);
    ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    SetConsoleCursorPosition(conhandler, { 0, 4 });

    while (true) {
        std::string temp = text;
        text.erase(0, 1);
        text += temp[0];
        CHAR_INFO* buff = (CHAR_INFO*)calloc(ancho, sizeof(CHAR_INFO));

        for (int i = 0; i < text.length(); i++) {
            buff[i].Char.AsciiChar = text.at(i);
            buff[i].Attributes = 15;
        }

        SMALL_RECT pos = { 0, 0, ancho, 1 };
        WriteConsoleOutputA(conhandler, buff, { (SHORT)ancho, 1 }, { 0, 0 }, &pos);
        free(buff);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

}

int main()
{
	std::string test = "--------ESTRUCTURA DE DATOS:  GRUPO 10 Y 18------------------   ";
    std::thread t2(marquee, test);
    t2.detach();
	ArbolRN RBTree;
	registro();
	menu(RBTree);
	return 0;
}













void askForMenu(ArbolRN RBTree)
{
	char ch = '\0';
	cin.ignore();
	cout << "\nVolver al menu? Y - N: ";
	cin.get(ch);
	while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
	{
		cout << "\nOpcion incorrecta, volver a intentar: ";
		cout << "\nVolver al menu? Y - N: ";
		cin.get(ch);
	}
	if (ch == 'Y' || ch == 'Y')
		menu(RBTree);
	else if (ch == 'n' || ch == 'N')
		exit(0);
	cin.ignore();
}

void insert(ArbolRN RBTree)
{
	unsigned int size = 0;
	int val = 0;

	system("CLS");
	cout <<endl;
	cout << "\t\tINSERTAR\n\n";
	cout << "Ingresar un valor:\n";
	val = Input::integerNumber(1,9);
	RBTree.insert(val);

	system("CLS");
	cout <<endl;
	cout << "==========================================\n";
	cout << "\tLos valores han sido insertados!\n";
	cout << "==========================================\n\n";
	cout << "\033[1;31m" << "("<<val<<")"<< "\033[0m"<<endl;
	RBTree.print();
	cout<<"==========================================\n";
	cout<< "\tInformacion del arbol:\n";
	cout<<"==========================================\n";
	RBTree.informationTree();
	
	askForMenu(RBTree);
	fflush(stdin);
}

void remove(ArbolRN RBTree)
{
	int val = 0;

	system("CLS");
	cout <<endl;
	cout << "\t\tELIMINAR\n";
	cout << "Ingrese el valor a eliminar: ";
	cin >> val;
	system("CLS");
	cout << "=========================================\n";
	RBTree.remove(val);
	cout << "=========================================\n";
	RBTree.print();
}

void search(ArbolRN RBTree)
{
	int val = 0;

	system("CLS");
	cout <<endl;
	cout << "\t\tBUSCAR\n";
	cout << "Ingrese el valor a buscar: ";
	cin >> val;
	system("CLS");
	cout << "=============================================\n";
	RBTree.search(val);
	cout << "=============================================\n";
	RBTree.print();
	cout << "=============================================\n";
}

void print(ArbolRN RBTree)
{
	system("CLS");
	cout <<endl;
	cout << "===========================================================\n";
	RBTree.print();
	cout << "===========================================================\n\n";
}

void preOrder(ArbolRN RBTree)
{
	system("CLS");
	cout <<endl;
	cout << "\t Recorrido en PreOrden\n";
	RBTree.preOrder();
}
void inOrder(ArbolRN RBTree)
{
	system("CLS");
	cout <<endl;
	cout << "\t Recorrido en inOrden\n";
	RBTree.inOrder();
	cout << "===========================================================\n\n";
}
void postOrder(ArbolRN RBTree)
{
	system("CLS");
	cout <<endl;
	cout << "\t Recorrido en postOrden\n";
	RBTree.postOrder();
	cout << "===========================================================\n\n";
}

void menu(ArbolRN RBTree)
{
	system("CLS");
	cout <<endl;
    cout<<endl;
    cout <<" "<<endl;
    Menu m("\n\n\t MENU PRINCIPAL");
    m.add_option(MenuOption("  \t1. Ingresar un valor			    ", [&](MenuOptionArguments args) {
        system("cls");
		insert(RBTree);
        return 0;
	}));
    m.add_option(MenuOption("  \t2. Eliminar un valor			    ", [&](MenuOptionArguments args) {
		system("cls");
		remove(RBTree);
		return 0;
	}));
    m.add_option(MenuOption("  \t3. Buscar un valor			    ", [&](MenuOptionArguments args) {
		system("cls");
		search(RBTree);
		return 0;
	}));
    m.add_option(MenuOption("  \t4. Imprimir Arbol    			    ", [&](MenuOptionArguments args) {
		system("cls");
		print(RBTree);
		return 0;
	}));
    m.add_option(MenuOption("  \t5. Recorrido         			    ", [&](MenuOptionArguments args) {
        system("cls");
        subMenu(RBTree);
        return 0;
    }));
    m.add_option(MenuOption("  \t6. Extras         			    ", [&](MenuOptionArguments args) {
        system("cls");
        extrasMenu(RBTree);
        return 0;
    }));
    m.add_option(MenuOption("  \t7. Salir        			    ", [&](MenuOptionArguments args) {
		system("cls");
		std::cout << "\n\nADIOS..." << std::endl;
		m.stop();
	}, false));
    m.display();
}
void subMenu(ArbolRN RBTree){
    cout<<endl;
    Menu m("\n\n\t\tRECORRIDOS\n");
    m.add_option(MenuOption("  \t1. Recorrido en PreOrden			    ", [&](MenuOptionArguments args) {
        system("cls");
        preOrder(RBTree);
        return 0;
    }));
    m.add_option(MenuOption("  \t2. Recorrido en InOrden			    ", [&](MenuOptionArguments args) {
        system("cls");
        inOrder(RBTree);
        return 0;
    }));
    m.add_option(MenuOption("  \t3. Recorrido en PostOrden			    ", [&](MenuOptionArguments args) {
        system("cls");
        postOrder(RBTree);
        return 0;
    }));
    m.add_option(MenuOption("  \t4. Recorrido en Regresar			    ", [&](MenuOptionArguments args) {
        system("cls");
        system("pause");
        menu(RBTree);
        return 0;
    }));
    m.display();
}

void extrasMenu(ArbolRN RBTree){
    cout<<endl;
    Menu m("\n\n\t\tExtras\n");
    m.add_option(MenuOption("  \t1. Guardar en archivo (.txt/.dat)	            ", [&](MenuOptionArguments args) {
        system("cls");
        RBTree.saveTreeTxt();
		RBTree.saveTreeBin();
        cout << "\n\nGuardado con exito" << endl;
		system("ArbolRN.txt");
		system("ArbolRN.dat");
        system ("pause");
        return 0;
    }));
    m.add_option(MenuOption("  \t2. Guardar en Pdf		    ", [&](MenuOptionArguments args) {
        system("cls");  
        cout << "\n\nGuardado con exito" << endl;
        system ("pause");
        return 0;
    }));
    m.add_option(MenuOption("  \t3. Imagen Pixelada		    ", [&](MenuOptionArguments args) {
        system("cls");
        system("Imagen.exe");
        return 0;
    }));
    m.add_option(MenuOption("  \t4. Ayuda de usuario       			    ", [&](MenuOptionArguments args) {
        system("cls");
         
        return 0;
    }));
    m.add_option(MenuOption("  \t5. C++ docs    			    ", [&](MenuOptionArguments args) {
        system("cls");
        
        return 0;
    }));
    m.add_option(MenuOption("  \t6. Backup     			    ", [&](MenuOptionArguments args) {
        system("cls");
        cout << "\n\nBienvenido a Backup\n" << endl;
        system("Backup.exe");
        return 0;
    }));
    m.add_option(MenuOption("  \t7. Volver al menu	     		    ", [&](MenuOptionArguments args) {
        system("cls");
        system("pause");
        menu(RBTree);
        return 0;
    }));
    m.display();
}

