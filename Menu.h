/**
 * @file Menu.h
 * @author Alice Stanford
 * @date  March 28, 2016
 * @class Menu
 * Node type to be stored in the ADT binary search tree. It consists of
 * CHANGE !!!! the name (the key), id number, phone number, and the output filename. 
 */
#ifndef MENU_H
#define MENU_H

#include "Menu.h"
#include "Film.h"
#include "FilmDatabase.h"
#include <string>
#include <fstream>
using namespace std;

class Menu
{
public:

	/**
    * Displays the main menu.
    */
   void displayMain(const FilmDatabase& filmDB);
	
	/**
    * Displays the reports submenu
    */
	void displayReports(const FilmDatabase& filmDB);
	
	/**
    * Displays the search submenu
    */
	void displaySearch(const FilmDatabase& filmDB);
}; // end Menu
#define MENU_H
#endif
