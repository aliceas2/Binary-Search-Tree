/**
 * @file Film.h
 * @author Alice Stanford
 * @date  March 28, 2016
 * @class Film
 * Node type to be stored in the ADT binary search tree. It consists of
 * CHANGE !!!! the name (the key), id number, phone number, and the output filename. 
 */
#ifndef FILM_H

#include <string>
#include <fstream>
using namespace std;

// Name of file in which to save all output data
const string OUTPUT_FILENAME = "studentOutFile.txt";

class Film
{
private:
	//Film Rank
	int rank;
	
	//Film Title, the key
	string filmTitle;
	
	//film studio
	string studio;
	
	//Total gross of film
	double grossTotal;
	
	//total theaters
	int theatersTotal;
	
	//opening gross of the film
	double grossOpening;
	
	//opening theaters 
	int theatersOpening;
	
	//opening date of the movie
	string dateOpening;
	
	//output file
	static ofstream outFile;
	
public:
   /**
    * Default constructor
    */
	Film();
	
	Film(string FilmName);

	Film(int rank, string FilmName, string studio, double grossTotal, int theatersTotal, double grossOpening, 
	int theatersOpening, string dateOpening);


   /**
    * Accessor for the film title.
    * @return film title, the key
    */
   string getTitle(void);
	
	 /**
    * Accessor for the film rank.
    * @return film rank
    */
   int getRank(void);
	
	/**
    * Accessor for the film opening date.
    * @return film opening date
    */
   string getMonth(void);
	
	/**
    * Accessor for the film studio.
    * @return film studio
    */
   string getStudio(void);

   /**
    * Displays all the data stored for a film.
    */
   void printTitle(void);
	
	 /**
    * Outputs the data to the output file. 
    */
   void saveData();
	
   /**
    * Defines the > operator for a Film object. 
    * @param right - right hand Film object for comparison 
    *                to the this Film object using >
    */
   bool operator> (const Film &right);

   /**
    * Defines the < operator for a Film object. 
    * @param right - right hand Film object for comparison 
    *                to the this Film object using <
    */
   bool operator< (const Film &right);

   /**
    * Defines the == operator for a Film object. 
    * @param right - right hand Film object for comparison 
    *                to the this Film object using ==
    */
   bool operator== (const Film &right);
	
	static void closeOutputFile();
}; // end Film
#define FILM_H
#endif
