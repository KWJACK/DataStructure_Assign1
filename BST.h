///////////////////////////////////////////////////////////////////////////////
// File Name : BST.h							     
// Date : 2015/10/03							     
// Compiler : g++ 4.6.3													
// Os : ubuntu 12.04.3													
// Author : Jae Ken Lee													
// Student ID : 2012722081										
// --------------------------------------------------------------------------
// ver : 1.0																 //
// Description : BST Class can be executed by file class's call, according to
// demands in inputfile and write the result to outputfile. Additionally, it 
// has three Binary tree and one Queue data structure						 
// Etc : Data Structure Assignment #1 (BST)									 
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Node.h"//BST is formed of each unique nodes
#include "Queue.h"//over 25th nodes, it has added form and these are connected the shape Queue structure
#include <fstream>//for output, BST write the content to outputfile that current state or for other demands by command in inputfile

class BST//Binary Search Tree
{
private:	
	Node* root_phone;//Root Tree's root
	Node* root_name;//Name Tree's root
	Node* root_sequence;//Sequence's root
	Node* head_WaitList;//this Queue's head

	int allNumberNode;//counting the numbere of all nodes in BST even included WaitList 
	int SequenceNumber;//this count sequence in order,without reduction.

	Queue myqueue;//BST has Queue structure for WaitList

	ofstream output;//declartion of ofstream's object 'output' enable to write the content to outputfile

	//Each insert function excute in each tree, each tree deal with matched pointer variable
	//Each Pointer in each tree needs to respective setting for drawing connection of tree.
	//that is why I separated insert as three
	void insertSequence(Node* newLeaf, Node* ptr);
	void insertPhone(Node* newLeaf, Node* ptr);
	void insertName(Node* newLeaf, Node* ptr);

	//printinorder spread by what demanding written by inputfile's command
	//printinorder is print all node's data as ascending order
	void PrintInorderName(Node* ptr);
	void PrintInorderSequence(Node* ptr);
	void PrintInorderPhone(Node* ptr);

	//for demanding, Delete Function perform to subtract to tree 
	void Delete_P(Node* target);
	void Delete_N(Node* target);
	void Delete_S(Node* target);
	
	
public:
	BST();
	~BST();

	int getNumberNode();//return total number of subscribers
	void Delete(Node* target);//call three kind of delete in this function
	void Reserve(char* FirstName, char* LastName, char* phoneNumber);//called by File class. Reserve function create node and let to insert it
	void Update(char* FirstName, char* LastName, char* phoneNumber);//called by File class. Update subscriber's information and re-arrange the Node in each tree
	void Print_phone(char* phoneNumber);//print the Node by reference the phoneNumber
	void Print_Name(char* FirstName, char* LastName);//print the Node by reference the FirstName and LastName
	void Print_WaitList();//print WaitList in Queue class

	//for demanding, Cancel Function called from File class as direct,
	//Cancel function print the node statement 'cancel' and re-arrange
	void Cancel_S(int sequenceNumber);
	void Cancel_N(char* FirstName, char* LastName);
	void Cancel_P(char* phoneNumber);

	
	//all kind of PrintInorder in BST print the node in which statement is Confrim. instead WaitList is printed in Queue class 
	void PrintInorder_N();// print all nodes sorted Name ascending order by using inorder traveling
	void PrintInorder_S();//print all nodes sorted Sequence ascend order by using inorder traveling
	void PrintInorder_P();//print all nodes sorted PhoneNumber ascend order by using inorder traveling

	Node* CreateLeaf(char* FirstName, char* LastName, char* phoneNumber);//Create New Node
	void insert(Node* newLeaf);//this insert function call by once, each three insert function in located private
	
};

