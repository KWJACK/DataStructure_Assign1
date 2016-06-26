#include "Queue.h"
using namespace std;
Queue::Queue()//Constructor
{
	m_Head = NULL;//at first, Queue doesn't have head, since no one had inserted yet.
	output.open("output.txt", ios::app);//open file as mode of modification(ios::app) for modifying on and on
}
Queue::~Queue()//Destructor
 {
	//all node are deleted in BST class, even one included to Queue
	//because all of node in any tree share same node 
}
void Queue::Push(Node* newNode){//push the Node to Queue 
	if (!m_Head){//when this function will be called first, queue would have no one. So first pushed Node will be head(m_Head)
		m_Head = newNode;
	}
	else{//Others should be entered this loop except first Node
		if (IsFull() == false){//this mean is that queue has enough space
			newNode->setNext(m_Head);//
			m_Head = newNode;//
		}
		else{//in case of noting space in queue
			cout<< "Queue is full, so We can't add New customer" << endl;
		}
	}
}
bool Queue::IsFull(){//check to Queue's empty space whether is full or not
	Node *pCur = m_Head;
	int countNode = 0;
	//counting number of Node in queue 
	while (pCur->getNext() != NULL){
		pCur = pCur->getNext();
		countNode++;
	}
	//Queue enables to have 10 node as max.
	if (countNode < 10){//if Queue is not full statement, return to false(=queue has enough space)
		return false;
	}
	else{//if Queue is full statement, return to true(=queue doesn't have enough space)
		return true;
	}
}
Node* Queue::Pop(){//Pop is role of informing the first node's address.
	Node* pCur = m_Head;//get head's address in queue for searching the first 
	while (pCur->getNext() !=NULL){//this loop will escape when meet the last node that the first came in
		pCur = pCur->getNext();//shift the next node
	}
	return pCur;//return pCur's address	
	//deletion the object "pCur" should be excuted  Delete in BST class
	//if Pop function delete the object, other tree would be lost the way 
	//Because the trees were maken common subscriber's datas.
}


void Queue::Print(){//this call printprivate function in Queue class
	//the reason why separate one print and other printprivate is that in order to distinguish the access from other domain
	//sorting manner is First in, First out. 
	output << "======================================================================" << endl;
	output << "   Name=======Phone-number===Reservation number===Reserve status" << endl;
	output << "======================================================================" << endl;
	Printprivate(m_Head);//call printprivate and this will start to print from Queue's head 
	output << endl;
}
void Queue::Printprivate(Node* ptr){
	if (!m_Head){//if head does not exist yet, no one are printed so programm print error msg
		output << "Wait List does not yet exist." << endl;
	}
	else{//in case of exist head
		if (ptr->getNext() != NULL){
			Printprivate(ptr->getNext());//Continuously calling the print function until arrival in the first place.
										//so used reculsive funciton
		}
		output << ptr->getFirstName() << " " << ptr->getLastName() << "\t" << ptr->getPhoneNumber() << "\t\t" << ptr->getSequenceNumber() << "\t\t";
		output << "Wait List" << endl;//all of node in queue are statment the 'Wait List'
	}
}
void Queue::Delete_Queue(Node* target){//Delete the Node from Queue
	Node* pCur = m_Head;//pCur should be started from head
	Node* pCurbefore = NULL;//pCurbefore is pCur's behind

	while (pCur!= target){//this loop will be ended when target Node and pCur until find the target. 
		pCurbefore = pCur;//pCurbefore should shadow the pCur
		pCur = pCur->getNext();
	}
	if (pCurbefore != NULL){//when pCurbefore exist 
		pCurbefore->setNext(pCur->getNext());
	}
	else{//if pCurbefore does not exist, this means that target is m_head
		//if head is deleted not to consider others, Queue would lost the way to go across next node.
		if (pCur->getNext()){//if pCur's next node exist, the next will be new head.
			m_Head = pCur->getNext();
		}
		else{//this case, No one exist except head in Queue(WaitList) 
			m_Head = NULL;//so then head's address should be NULL again
		}
	}
	//deletion the object "pCur" should be excuted  Delete in BST class
	//if delete the object here, other tree would be taken affect 
	//Because the trees were maken common subscriber's datas.
}