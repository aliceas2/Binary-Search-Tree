/**
 * @file FilmDatabase.h
 * @author Alice Stanford
 * @date March 28, 2016
 * @class FilmDatabase
 * This class creates a database using a BinarySearchTree to store
 * items of the Film class type. 
 */
 
#ifndef STUDENTDATABASE_H
#include "BinarySearchTree.h"
#include "Film.h"
using namespace std;

class FilmDatabase
{
private:
   /**
    * binary search tree to store Person data
    */
   BinarySearchTree<Film> filmDatabaseBST;
	
public:
   /**
    * Creates a database consisting of Film objects.
    */
   void createDatabase (void);
	
   /**
    * Saves the database to an output file using a preorder
    * traversal.
    */
   void saveDatabase (void);
	
	 /**
    * Displays the data in the database using inorder traversal.
    */
   void displayData (void);
	
	/**
    * Displays the titles in the database using inorder traversal.
    */
	void displayTitle (void);
	
	/**
    * Displays the titles in the database based on rank
	 * using inorder traversal.
    */
	void displayOrder(void);
	
	/**
    * Displays the data matching the keyword in the database 
	 * using inorder traversal.
    */
	void displayKeyword(void);
	
	/**
    * Displays the data in the database that match the user inputed studio 
	 * using inorder traversal.
    */
	void displayStudio(void);
	
	/**
    * Displays the data in the database matching the user inputed month 
	 * using inorder traversal.
    */
	void displayMonth(void);
	
	friend void rankOrder(Film& anItem);
};

#define STUDENTDATABASE_H
#endif