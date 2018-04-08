/**
 * @file Film.cpp
 * @author Alice Stanford
 * @date  March 28, 2016
 * Implementation of the Film class
 */
#include "Film.h"
#include <iostream>
#include <iomanip>

using namespace std;

ofstream Film::outFile(OUTPUT_FILENAME.c_str());  // open output file

Film::Film()
{
}

Film::Film(string newFilmTitle):filmTitle(newFilmTitle)
{
}

// Define and initialize the static class members shared by all instances 
Film::Film(int newRank, string newFilmTitle, string newStudio, double newGrossTotal, int newTheatersTotal, 
	double newGrossOpening, int newTheatersOpening, string newDateOpening)
	: rank(newRank), filmTitle(newFilmTitle), studio(newStudio), grossTotal(newGrossTotal), theatersTotal(newTheatersTotal),
		grossOpening(newGrossOpening), theatersOpening(newTheatersOpening), dateOpening(newDateOpening)
{
}


string Film::getTitle(void)
{
   return filmTitle;
}

int Film::getRank(void)
{
	return rank;
}

string Film::getMonth(void)
{
   return dateOpening;
}

string Film::getStudio(void)
{
   return studio;
}

void Film::printTitle(void)
{
     cout << fixed << setprecision(2) << filmTitle << endl <<
	  		 "   Opening date: " << dateOpening << "  Rank: " << rank << 
			 "  Studio: " << studio << endl
			 << "   Gross Total: " << grossTotal << " Gross Opening: " << grossOpening << endl
			 << "   Theaters Total: " << theatersTotal << " Theaters Opening: " << theatersOpening <<endl <<endl;
}

void Film::saveData()
{
   if (outFile)
      outFile << rank << "," << filmTitle << "," << studio << "," << grossTotal << "," << theatersTotal << "," << 
		grossOpening << "," << theatersOpening << "," << dateOpening << endl;
   else
       cout << "Error: Output file " << OUTPUT_FILENAME 
            << " is not ready for output." << endl << endl;
}

bool Film::operator> (const Film &right)
{
   return (filmTitle > right.filmTitle);
}



bool Film::operator< (const Film &right)
{
   return (filmTitle < right.filmTitle);
}


bool Film::operator== (const Film &right)
{
   return (filmTitle == right.filmTitle);
}

void Film::closeOutputFile()
{
   outFile.close();
}