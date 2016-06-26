///////////////////////////////////////////////////////////////////////////////
// File Name : File.h														 //
// Date : 2015/10/03														 //
// Compiler : g++ 4.6.3														 //
// Os : ubuntu 12.04.3														 //
// Author : Jae Ken Lee														 //
// Student ID : 2012722081													 //
// --------------------------------------------------------------------------//
// ver : 1.0																 //
// Description : File class header has three variable. Two variables is for  //
// input&output and last is for BST Class used as form of object. And this   //
// class has magaement function, this role is that read inputfile for writting/ 
// to outfile, by proper execution follow line by line in inputfile			 // 
//																			 //
// Etc : Data Structure Assignment #1 (BST)									 //
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include<fstream>//for input & output
#include "BST.h"//for declartion of BST object
class File
{
private:
	BST mybst;//File has BST object	
	ofstream outputfile;//outputfile object need to write txt file
	ifstream inputfile;//inputfile object need to read txt file
public:	
	File();
	~File();	
	void Management();//read inputfile to write outfile
		
};

