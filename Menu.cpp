/**
 * @file Menu.cpp
 * @author Alice Stanford
 * @date March 30, 2016
 */
#include "Menu.h"
#include "Film.h"
#include "FilmDatabase.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void Menu::displayMain(const FilmDatabase& filmDB)
{
	FilmDatabase film = filmDB;
	char select;
	do{
	cout << "MAIN MENU" << endl;
	cout << "D - Describe the Program" << endl;
	cout << "R - Reports" << endl;
	cout << "S - Search the Database" << endl;
	cout << "X - Exit the Program" << endl << endl;
	cout << "Enter Selection : ";
	cin >> select;
	
	select = toupper(select);
	if(select == 'D')
	{
   	cout << "This program allows you to view data pertaining to the highest grossing films of 2105." << endl << endl;
		cout << "Reports submenu displays the movies either by title or rank." << endl;
		cout << "Search the database submenu allows search by Title, Keyword(s), Studio, or month of release." << endl << endl;
	}
   if(select == 'R')
   	displayReports(film);
	if(select == 'S')
   	displaySearch(film);
	if(select == 'X')
   	break;
	}while(select!='R'||'S'||'X');
}

void Menu::displayReports(const FilmDatabase& filmDB)
{
	FilmDatabase film = filmDB;
	char select;
	do{
	cout << "REPORTS MENU" << endl;
	cout << "T - Order by Film Title report" << endl;
	cout << "R - Order by Rank report" << endl;
	cout << "X - Return to main menu" << endl << endl;
	cout << "Enter Selection : ";
	cin >> select;
	
	select = toupper(select);
	
   if(select == 'T')
		film.displayData();		
   if(select == 'R')
		film.displayOrder();
	}while(select !='X');
}

void Menu::displaySearch(const FilmDatabase& filmDB)
{
	FilmDatabase film = filmDB;
	char opt;
	do{
	cout << "SEARCH MENU" << endl;
	cout << "T - Search by Title" << endl;
	cout << "K - Search by Keyword(s)" << endl;
	cout << "S - Search by Studio" << endl;
	cout << "M - Search by month of release" << endl;
	cout << "X - Return to main menu" << endl;
	cout << "Enter Selection : ";
	cin >> opt;
	
	opt = toupper(opt);
	
   if(opt == 'T')
	{
		film.displayTitle();
	}
   if(opt == 'K')
	{
		film.displayKeyword();
	}
	if(opt == 'S')
	{
		film.displayStudio();
	}
	if(opt == 'M')
	{
		film.displayMonth();
	}
	}while(opt!='X');
}