///////////////////////////////////////////////////////////////////////////////
// File Name : Queue.h										
// Date : 2015/10/03										
// Compiler : g++ 4.6.3										
// Os : ubuntu 12.04.3										
// Author : Jae Ken Lee										
// Student ID : 2012722081									
// --------------------------------------------------------------------------
// ver : 1.0								
// Description : Queue class is decribed the data structure about FIFO		
// (first in, first oout). but in here, the thing of out is possible anywhere
// and deletion will execute in BST class, not here				
// Etc : Data Structure Assignment #1 (BST)					
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "Node.h"
#include <fstream>
#include <iostream>
//Queue can have 10 node as maximum.
class Queue
{
private:
	Node* m_Head;//head of Queue structure
	ofstream output;//declartion of ofstream's object 'output' enable to write the content to outputfile
	void Printprivate(Node* ptr);//real function excution print. refer Print in declartion public domain

public:
	Queue();//constructor
	~Queue();//destructor
	
	bool IsFull();//check to Queue's empty space whether is full or not
	void Push(Node* newNode);//push the Node to Queue
	Node* Pop();//return address of Node which had entered first
	void Delete_Queue(Node* target);//the role of this function is delete the Node in Queue. But you should know this doesn't delete the Node in BST
	void Print();//Print the Node which is included in Queue,in order --> same as PRINT WAIT function
};

