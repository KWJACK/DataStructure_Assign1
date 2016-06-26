///////////////////////////////////////////////////////////////////////////////
// File Name : Node.h													
// Date : 2015/10/03													
// Compiler : g++ 4.6.3													
// Os : ubuntu 12.04.3													
// Author : Jae Ken Lee														 
// Student ID : 2012722081													
// --------------------------------------------------------------------------
// ver : 1.0										
// Description : This Node class is composed to data part and pointer part in
// private and functions in public. The functions deal with data according to 
// use per many case.																							 //
// Etc : Data Structure Assignment #1 (BST)				
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
using namespace std;
class Node//this object is element for BST structure
{
private:
	int SequenceNumber;//this number is automatically determined more one adder before when created new node.
	
	//data
	string First_Name;
	string Last_Name;
	string PhoneNumber;
	bool Confirm;//check statement, wheter one or zero. it is regarded to confirm or wait

	//address
	Node* S_Left;//SequenceNumber left child pointer
	Node* S_Right;//SequenceNumber right child pointer

	Node* N_Left; //Name left child pointer
	Node* N_Right;//Name right child pointer

	Node* P_Left; //PhoneNumber left child pointer
	Node* P_Right;//PhoneNumber right child pointer

	Node* Next_Queue; // It is link pointer for consistance of Linked Queue
public:
	Node();
	~Node();
	//setting information for Node using by data in inputfile.
	void setFirstName(char* First_Name);
	void setLastName(char* Last_Name);
	void setPhoneNumber(char* phoneNumber);
	void setSequenceNumber(int sequenceNumber);
	void setConfirm(bool confirm);
	void setS_Left(Node* left);
	void setS_Right(Node* right);
	void setN_Left(Node* left);
	void setN_Right(Node* right);
	void setP_Left(Node* left);
	void setP_Right(Node* right);
	void setNext(Node* next);
	
	//get private valuse of Node even Node address
	Node* getS_Left();
	Node* getS_Right();
	Node* getN_Left();
	Node* getN_Right();
	Node* getP_Left();
	Node* getP_Right();
	Node* getNext();
	string getPhoneNumber();
	int getSequenceNumber();
	bool getConfirm();
	string getFirstName();
	string getLastName();
};

