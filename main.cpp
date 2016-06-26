///////////////////////////////////////////////////////////////////////////////
// File Name : Main.cpp														 //
// Date : 2015/10/03														 //
// Compiler : g++ 4.6.3														 //
// Os : ubuntu 12.04.3														 //
// Author : Jae Ken Lee														 //
// Student ID : 2012722081													 //
// --------------------------------------------------------------------------//
// ver : 1.0																 //
// Description :in here, Program enable to declare file object named my file.//
//				and then read the input file using management function,		 //
//				in File class												 //
// Etc : Data Structure Assignment #1 (BST)									 //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>//standard header for C++
#include "File.h"//for declration of File object
using namespace std;
int main(){
	File myfile;// declaration of File object as myfile	
	myfile.Management();//myfile read input file(input.txt)  all of command in input.txt will be executed at File class
	return 0;
}