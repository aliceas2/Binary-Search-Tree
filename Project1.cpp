/**
 * @file Tester.cpp
 * @author Alice Stanford
 * @date March 30, 2016
 */
#include "FilmDatabase.h"
#include "Menu.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main (void)
{
	Menu menu;
   FilmDatabase filmDB; // database to store film objects
   filmDB.createDatabase();
	
   menu.displayMain(filmDB);
	 
	cout << " ";

   return EXIT_SUCCESS;
}

