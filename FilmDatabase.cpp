	/**
 * @file FilmDatabase.cpp
 * @author Alice Stanford
 * @date  March 28, 2016
 * Implementation of the FilmDatabase class
 */
#include "FilmDatabase.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

string line;
string temp;
string input;
char opt;
int rankTemp;

ifstream inputFile ("Films2015.csv");

/*
 * Saves the contents of a tree node (a film) to the text file
 */
void saveData(Film& anItem)
{
   anItem.saveData(); 
}

/*
 * Displays the contents of a tree node (a film)
 */
void display(Film& anItem)
{
   anItem.printTitle();
}


/*
 * Displays the film by rank
 */
void rankOrder(Film& anItem)
{
	int x;
	x = anItem.getRank();
	if(rankTemp == x)
		anItem.printTitle();	
}

/*
 * Displays the contents of a tree node (a film)
 */
void search(Film& anItem)
{
	transform(input.begin(), input.end(), input.begin(), ::toupper);
	if(opt == 'T')
	{
		temp = anItem.getTitle();
		transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
 		if(temp == input)  
			anItem.printTitle();
	}
	else if(opt== 'K')
	{ 
		vector<string> keywords;
		temp = anItem.getTitle();
		transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
		string tmp;
		bool contains = false;
  		string::iterator i;
  		keywords.clear();
		
  		for(i = input.begin(); i <= input.end(); ++i) 
		{
    		if((const char)*i != ','  && i != input.end()) 
			{
      		tmp += *i;
    		} 
			else 
			{
      		keywords.push_back(tmp);
      		tmp = "";
    		}
 		}
				
		int found;
		for(int l = 0; l<keywords.size();l++)
		{
			found = temp.find(keywords[l]);
			if (found != string::npos)
			{
   			anItem.printTitle();
				contains = true;
			}
		}
	}
	else if(opt== 'S')
	{
		temp = anItem.getStudio();
		transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
 		if(temp == input)  
			anItem.printTitle();
	}
	else if(opt== 'M')
	{
		string n;
		temp = anItem.getMonth();
		transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
		if(temp[1]=='/')
			n = temp[0];
		else
			n = temp.substr (0,2);
 		if(input == n)  
			anItem.printTitle();
	}
}

void FilmDatabase::createDatabase (void)
{
	int temp1, temp5, temp7;
	string temp2, temp3, temp8;
	double temp4, temp6;

	if (inputFile.is_open())
   {
		while (getline( inputFile, line ))
		{
			istringstream is(line);

			getline(is, temp, ',');
			temp1 = atoi(temp.c_str());
			
        	getline(is, temp2,   ',');
			
        	getline(is, temp3, ',');
			
			getline(is, temp, ',');
			temp4 = atof(temp.c_str());
			
			getline(is, temp, ',');
			temp5 = atoi(temp.c_str());
			
			getline(is, temp, ',');
			temp6 = atof(temp.c_str());
			
			getline(is, temp, ',');
			temp7 = atoi(temp.c_str());
			
			getline(is, temp8, ',');
			
			Film film(temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8);
			filmDatabaseBST.add (film);
		}
    }
    inputFile.close();
}

void FilmDatabase::saveDatabase (void)
{
   // output the data to a text file
   cout << endl << "Saving all data in the binary search tree to a file named " 
        << OUTPUT_FILENAME << "." << endl;
   filmDatabaseBST.preorderTraverse(saveData);
   Film::closeOutputFile();
}

void FilmDatabase::displayData (void)
{
   filmDatabaseBST.inorderTraverse(display);
}

void FilmDatabase::displayTitle (void)
{
	cin.ignore();
	opt = 'T';
	cout << "Enter the Title : ";
	getline( cin , input );
	filmDatabaseBST.inorderTraverse(search);
}

void FilmDatabase::displayOrder(void)
{
	rankTemp = 1;
		for(int i = 0; i<100;i++)
		{
   		filmDatabaseBST.inorderTraverse(rankOrder);
			rankTemp++;
		}
}

void FilmDatabase::displayKeyword(void)
{
	cin.ignore();
	opt = 'K';
	cout << "Enter the Keyword(s) (sperate multiple searches by commas) : ";
	getline( cin , input );
	filmDatabaseBST.inorderTraverse(search);
}

void FilmDatabase::displayStudio(void)
{
	cin.ignore();
	opt = 'S';
	cout << "Enter the Studio : ";
	getline( cin , input );
	filmDatabaseBST.inorderTraverse(search);
}

void FilmDatabase::displayMonth(void)
{
	cin.ignore();
	opt = 'M';
	cout << "Enter the month of release (as a number): ";
	cin >> input;
		
	stringstream ss(input);
	int strAsInt = 0;
	ss>>strAsInt;
		
	while(strAsInt>12||strAsInt<1)
	{
		cout << "Invalid Input " << endl << "Enter the month of release (as a number): ";
		cin >> input;
		stringstream ss(input);
		ss>>strAsInt;	
	}
		
	filmDatabaseBST.inorderTraverse(search);
}

