#pragma once
#include <iostream>
#include "archivo.h"
#include <string>
#include <string.h>
#include <conio.h>
#include "menu.h"
#include "menu_option.h"

using namespace std;


void registration() {
	int v = 0;
	system("cls");
	fflush(stdin);
	std::cout << "\n\t\t\tRegistrarse" << endl;
	fflush(stdin);
	std::cout << "\n\t\t\tUsuario: ";
	cin >> name;
	fflush(stdin);
	std::cout << "\n\t\t\tClave: ";
	for (int i = 0; i < 60; i++) {
		v = _getch();
		if ((v >= 48 && v <= 57) || (v >= 65 && v <= 90) || (v >= 97 && v <= 122)) {
			aux_pass[i] = v;
			std::cout << "*";
		}
		else if (v == 13) {
			aux_pass[i] = '\0';
			break;
		}
	}
	pass = aux_pass;
	fflush(stdin);
	insert(name, pass);
	
}
void login() {
	do {
		system("cls");
		std::cout << "\n\n\t\t\tLOGIN" << endl;
		fflush(stdin);
		std::cout << "\n\n\t\t\tUsuario: ";
		cin >> nameaux;
		fflush(stdin);
		std::cout << "\n\n\t\t\tClave: ";
		for (int i = 0; i < 60; i++) {
			int v = _getch();
			if ((v >= 48 && v <= 57) || (v >= 65 && v <= 90) || (v >= 97 && v <= 122)) {
				passaux[i] = v;
				std::cout << "*";
			}
			else if (v == 13) {
				passaux[i] = '\0';
				break;
			}
		}
		fflush(stdin);
		if (strcmp(nameaux, name) == 0 && strcmp(passaux, pass) == 0) {
			break;
		}
		else if (readfile(nameaux, passaux)) {
			std::cout << "\n\t\t\t";
			system("pause");
			break;
		}
		else {
			std::cout << "\n\tUsuario o clave incorrectos" << endl;
			system("pause");
		}
	} while (true);
}
void registro() {
	int option;
	char answer;
	Menu m("\n\n\t\tPROGRAMA ARBOL ROJO-NEGRO");
	m.add_option(MenuOption("\n\t\t1. Registrarse", [&](MenuOptionArguments args) {
		system("cls");
		registration();
		std::cout << "\n\t\t Desea iniciar sesion? (s/n): ";
		cin >> answer;
		if (answer == 's' || answer == 'S') {
			login();
		}
		else {
			return;
		}
		m.stop();
	}));
	m.add_option(MenuOption("\n\t\t2. Ingresar", [&](MenuOptionArguments args) {
		system("cls");
		login();
		m.stop();
		return 0;
	}));

	m.add_option(MenuOption("\n\t\t3. Salir", [&](MenuOptionArguments args) {
		system("cls");
		cout << " " << endl;
		std::cout << "Hasta Pronto..." << std::endl;
		exit(1);
	}, false));

	m.display();

}
