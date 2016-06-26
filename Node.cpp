#include "Node.h"
#include <iostream>
#include <string>
using namespace std;
Node::Node()//Constructor
{//initialization of all datas and addresses
	int sequenceNumber=0;
	string First_Name;
	string Last_Name;
	string phoneNumber;
	bool Confirm=NULL;

	Node* S_Left=NULL;
	Node* S_Right = NULL;

	Node* N_Left = NULL;
	Node* N_Right = NULL;

	Node* P_Left = NULL;
	Node* P_Right = NULL;
	Node* Next_Queue = NULL;
}


Node::~Node()//Destructor
{
	//here is no role that deletion of data's node.
	//because string variable is automatically cleared
}

void Node::setFirstName(char* FirstName){ First_Name = FirstName; }
void Node::setLastName(char* LastName){	Last_Name = LastName; }
void Node::setPhoneNumber(char* phoneNumber){ PhoneNumber = phoneNumber; }
void Node::setSequenceNumber(int sequenceNumber){ SequenceNumber = sequenceNumber; }
void Node::setConfirm(bool confirm){
	if (confirm == true)//if confirm variable is true(1), Confrim in pravate of Node class will be Confirm statement
		Confirm = true;// Confirm
	else
		Confirm = false;// Wait List
}
//set Valus for each purpose
void Node::setS_Left(Node* left){ S_Left = left; }
void Node::setS_Right(Node* right){ S_Right = right; }
void Node::setN_Left(Node* left){ N_Left = left; }
void Node::setN_Right(Node* right){ N_Right = right; }
void Node::setP_Left(Node* left){ P_Left = left; }
void Node::setP_Right(Node* right){ P_Right = right; }
void Node::setNext(Node* next){ Next_Queue = next; }

//get Value for each purpose
Node* Node::getS_Left(){ return S_Left; }
Node* Node::getS_Right(){ return S_Right; }
Node* Node::getN_Left(){ return N_Left; }
Node* Node::getN_Right(){ return N_Right; }
Node* Node::getP_Left(){ return P_Left; }
Node* Node::getP_Right(){ return P_Right; }
Node* Node::getNext(){ return Next_Queue; }
string Node::getPhoneNumber(){ return PhoneNumber; }
int Node::getSequenceNumber(){ return SequenceNumber; }//sequenceNumber is returned as integer than other data is string or bool
string Node::getFirstName(){ return First_Name; }
string Node::getLastName(){ return Last_Name; }
bool Node::getConfirm(){ return Confirm; }//if Confirm is returned zero, means WaitList, other means Confrim