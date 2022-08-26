#pragma once
/*
* @flie menu.h
* @author Estructura de Datos
* @date 21/7/2022
* @brief Archivo de cabecera para la clase menu
* @version 1.0
* 
*@copyright Copyright (c) 2022
*@license MIT License
*/
#include "menu_option.h"
#include <iostream>
#include <vector>
#include <windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 77
#define KEY_RIGHT 75
#define KEY_ENTER 13
#define KEY_ESCAPE 27

class Menu {
public:
	/**
	 * @brief Metodo constructor
	 *
	 */
	Menu();
	/**
	 * @brief Metodo constructor
	 *
	 * @param string
	 */
	Menu(std::string title);
	/**
	 * @brief Metodo add_option()
	 *
	 * @param string
	 * @param string
	 */
	void add_option(MenuOption option);
	/**
	 * @brief Metodo add_option()
	 *
	 * @param string
	 * @param string
	 * @param string
	 */
	void remove_option(int index);
	/**
	 * @brief Metodo display()
	 *
	 */
	void display();
	/**
	 * @brief Metodo stop()
	 *
	 */
	void stop();
	/**
	 * @brief metodo is running
	 *
	 * @return true
	 * @return false
	 */
	bool is_running();

private:
	std::string title;
	std::vector<MenuOption> options;
	HANDLE console;
	bool running = false;
};
