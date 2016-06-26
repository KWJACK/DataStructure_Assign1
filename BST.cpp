#include "BST.h"
#include <iostream>
#include <string.h>
using namespace std;
BST::BST(){//initialization root and all number of node and sequence number
	root_phone=NULL;
	root_name = NULL;
	root_sequence = NULL;
	head_WaitList = NULL;
	allNumberNode = 0;
	SequenceNumber = 0;
	output.open("output.txt", ios::app);//open file as mode of modification(ios::app) for modifying on and on
}

BST::~BST(){//Destructor all node
	Node* deleteNode=root_sequence;
	Node* deleteNodeBefore = root_sequence;
	while (deleteNode->getS_Right()){//til Node's Right pointer is NULL
		deleteNode = deleteNode->getS_Right();
		delete deleteNodeBefore;//clear memory
		deleteNodeBefore = deleteNode;
	}
	delete deleteNode;//clear memory
}

int BST::getNumberNode(){//This Function returns the value that numeral total reservator
	return allNumberNode;
}
//CreateLeaf for Tree.
Node* BST::CreateLeaf(char* FirstName, char* LastName, char* phoneNumber){	
	
	SequenceNumber = SequenceNumber + 1;//counting up seqence number, this doesn't descend all time after ascending
	allNumberNode = allNumberNode + 1;//counting up one node from all
	Node* newleaf = new Node;//Memory allocation for Node class
	//setting datas
	newleaf->setFirstName(FirstName);
	newleaf->setLastName(LastName);
	newleaf->setPhoneNumber(phoneNumber);
	newleaf->setSequenceNumber(SequenceNumber);

	if (getNumberNode() <= 25){//Reservators will be added with a confirmed statement until 25th
		newleaf->setConfirm(true);
	}
	else{
		newleaf->setConfirm(false);//Reservators besides will be added through the waitlist
		//And Push the Node to Queue
		myqueue.Push(newleaf);		
	}
	return newleaf;//return made new Node address
}
void BST::insert(Node* newLeaf){//call three insert funcution, each function will be executed about innherent BST
	insertSequence(newLeaf, root_sequence);//insert to sequence tree
	insertPhone(newLeaf, root_phone);//insert to phoneNumber tree
	insertName(newLeaf, root_name);//insert to name tree
}

void BST::insertSequence(Node* newLeaf, Node* ptr){//newLeaf means newNode for inserting into tree, 'ptr' means present node location
	if (root_sequence == NULL){//if first insert, tree doesn't have root yet.
		root_sequence = newLeaf;//so newLeaf becomes root of sequence tree
	}
	else//if root exist, start to inserting newLeaf into tree
	{
		if (newLeaf->getSequenceNumber() < ptr->getSequenceNumber()){//if newLeaf's sequence is smaller than ptr's sequence, we should shift the node to Left
			if (ptr->getS_Left() != NULL){//if left child exists,
				insertSequence(newLeaf, ptr->getS_Left());//The insert function call oneself reculsivly to start left position
			}
			else{//,however left child doesn't exist, we can insert the newLeaf
				ptr->setS_Left(newLeaf);
			}
		}//Likewise if newLeaf's sequence is bigger than ptr's sequence, we should shift the node to Right
		else if (newLeaf->getSequenceNumber() > ptr->getSequenceNumber()){
			if (ptr->getS_Right() != NULL){//if right child exists,
				insertSequence(newLeaf, ptr->getS_Right());//The insert function call oneself reculsivly to start right position
			}
			else{//,however right child doesn't exist, we can insert the newLeaf
				ptr->setS_Right(newLeaf);
			}
		} 
		else{//if the node what has same sequence is entered, should print the error msg not to insert this
			output << "Already same sequence number has written\n";
		}
	}//in loop the case of existence the root
}
void BST::insertPhone(Node* newLeaf, Node* ptr){//newLeaf means newNode for inserting into tree, 'ptr' means present node location
	if (root_phone == NULL){//if first insert, tree doesn't have root yet.
		root_phone = newLeaf;//so newLeaf becomes root of phone tree
	}
	else //if root exist, start to inserting newLeaf into tree
	{
		if (newLeaf->getPhoneNumber() < ptr->getPhoneNumber()){//if newLeaf's phoneNumber is smaller than ptr's phoneNumber, we should shift the node to Left
			if (ptr->getP_Left() != NULL){//if left child exists,
				insertPhone(newLeaf, ptr->getP_Left());//The insert function call oneself reculsivly to start left position
			}
			else{//,however left child doesn't exist, we can insert the newLeaf
				ptr->setP_Left(newLeaf);
			}
		}//Likewise if newLeaf's phoneNumber is bigger than ptr's phoneNumber, we should shift the node to Right
		else if (newLeaf->getPhoneNumber() > ptr->getPhoneNumber()){
			if (ptr->getP_Right() != NULL){//if right child exists,
				insertPhone(newLeaf, ptr->getP_Right());//The insert function call oneself reculsivly to start right position
			}
			else{//,however right child doesn't exist, we can insert the newLeaf
				ptr->setP_Right(newLeaf);
			}
		}
		else{//if the node what has same sequence is entered, should print the error msg not to insert this
			output << "Already same phone number has written\n";
		}
	}//in loop the case of existence the root
}
void BST::insertName(Node* newLeaf, Node* ptr){//newLeaf means newNode for inserting into tree, 'ptr' means present node location
	if (!root_name){//if first insert, tree doesn't have root yet.
		root_name = newLeaf;//so newLeaf becomes root of phone tree
	}
	else{//if root exist, start to inserting newLeaf into tree		
		if (newLeaf->getLastName() < ptr->getLastName()){//if newLeaf's LastName is smaller than ptr's LastName, we should shift the node to Left
			if (ptr->getN_Left() != NULL){//if left child exists,
				insertName(newLeaf, ptr->getN_Left());//The insert function call oneself reculsivly to start left position
			}
			else{//,however left child doesn't exist, we can insert the newLeaf
				ptr->setN_Left(newLeaf);
			}
		}//Likewise if newLeaf's LastName is bigger than ptr's LastName, we should shift the node to Right
		else if (newLeaf->getLastName() > ptr->getLastName()){
			if (ptr->getN_Right() != NULL){//if right child exists,
				insertName(newLeaf, ptr->getN_Right());//The insert function call oneself reculsivly to start right position
			}
			else{//,however right child doesn't exist, we can insert the newLeaf
				ptr->setN_Right(newLeaf);
			}
		}
		//if the node what has same LastName is entered, should match using the FirstName whether one is bigger or smaller than ptr
		else if (newLeaf->getLastName() == ptr->getLastName()){//when both ptr and newleaf has same LastName,
			//next matter need to distinguish whether who has smaller or bigger name. Likewise when compare LastName, FirstName has three case.
			if (newLeaf->getFirstName() < ptr->getFirstName()){//case 1 :if newLeaf's FirstName is smaller than ptr's FirstName, we should shift the node to Left
				if (ptr->getN_Left() != NULL){//if left child exists,
					insertName(newLeaf, ptr->getN_Left());//The insert function call oneself reculsivly to start left position
				}
				else{//,however left child doesn't exist, we can insert the newLeaf
					ptr->setN_Left(newLeaf);
				}
			}//Likewise if newLeaf's FirstName is bigger than ptr's FirstName, we should shift the node to Right
			else if (newLeaf->getFirstName() > ptr->getFirstName()){//case 2 :
				if (ptr->getN_Right() != NULL){//if right child exists,
					insertName(newLeaf, ptr->getN_Right());//The insert function call oneself reculsivly to start right position
				}
				else{//,however right child doesn't exist, we can insert the newLeaf
					ptr->setN_Right(newLeaf);
				}
			}
			else{//case 3 : if the node what has same First and Last Name is entered, should print the error msg "cannot to insert this"		
				output << "Already same name number has written\n";
				//newLeaf = NULL;
			}
		}//in the conditional sentence,when both ptr and newleaf has same LastName
	}//in the conditional sentence, insert node using LastName
}

void BST::Reserve(char* FirstName, char* LastName, char* phoneNumber)
{//Reserve function check to same the subscriber in this programm before create node, and then let to insert it
	Node* checkNode = NULL;
	//if root_sequence doesn't exist, program would omit the check to find the node what have same data with existing
	if (root_sequence){//in order to check the same subscriber whether exist or not, used sequence tree
		//because the tree spread only one direction. After counting up seqence number, this doesn't descend all time
		//so all nodes in sequence tree are sorted right. Because of continuously to come large numbers.
		checkNode = root_sequence;
		while (checkNode){//till checkNode traveling all node
			if (checkNode->getLastName() == LastName){//case 1: this case is that meen one has same LastName
				if (checkNode->getFirstName() == FirstName){//if find same the name one with existing, escape from this loop
					break;//then, escape from this loop
				}
				else{//there may be someone has LastName  .
					checkNode = checkNode->getS_Right();//because sequence tree spread only right direction
				}
			}//case 1
			else{//other case is that not the same name
				checkNode = checkNode->getS_Right();//because sequence tree spread only right direction
				}//case 2
			}//while
		}//if condition that root_sequence is exist
	
	if (checkNode == NULL){//checkNode equal NULL means that no exist root or after traveling all node
		//Create the NewNode for securing to object's space in memory
		Node* newLeaf = new Node;
		if (allNumberNode < 35){//this can manage till creation before 35th node, if it let to try to insert 35th node, then allNumberNode is 34.
			//make newLeaf by flowed from inputfile command. Name and phonenumber data.
			//sequence data would be allocated in CreateLeaf function
			newLeaf = CreateLeaf(FirstName, LastName, phoneNumber);
			//then insert the Node to Each tree, by calling insert function that has all manner of inserting each tree
			insert(newLeaf);
			//print result to outputfile by using output fstream object.
			output << "======================================================================" << endl;
			output << "   Name=======Phone-number===Reservation number===Reserve status" << endl;
			output << "======================================================================" << endl;
			output << newLeaf->getFirstName() << " " << newLeaf->getLastName() << "\t" << newLeaf->getPhoneNumber() << "\t\t" << newLeaf->getSequenceNumber() << "\t\t";
			if (newLeaf->getConfirm() == true){//check the node what statement, if getConfirm inform true, then means Confirm. other is WaitList 
				output << "Confirm" << endl;
			}
			else{
				output << "Wait List" << endl;
			}
			output << endl;//
		}//this programm can have 35 node of maximum. if that is over, send the error msg   
		else{
			output << "It is impossible to insert, since all number of one who want to book airplan are 35 in our maximum." << endl;
		}
	}//if condition that checkNode is NULL
	else{//else condition, case of checkNode is not NULL means that it try to insert same name
		output << "RESERVE error - Same Name\n" << endl;//send error msg
	}
}
//The all kind of PrintInoder have same frame. but only difference that the function call within
void BST::PrintInorder_N(){
	output << "======================================================================" << endl;
	output << "   Name=======Phone-number===Reservation number===Reserve status" << endl;
	output << "======================================================================" << endl;
	PrintInorderName(root_name);//this inoder funcion is for Name tree
	output << endl;
}
void BST::PrintInorder_S(){
	output << "======================================================================" << endl;
	output << "   Name=======Phone-number===Reservation number===Reserve status" << endl;
	output << "======================================================================" << endl;
	PrintInorderSequence(root_sequence);//this inoder funcion is for sequence tree
	output << endl;
}
void BST::PrintInorder_P(){
	output << "======================================================================" << endl;
	output << "   Name=======Phone-number===Reservation number===Reserve status" << endl;
	output << "======================================================================" << endl;
	PrintInorderPhone(root_phone);//this inoder funcion is for phone tree
	output << endl;
}

void BST::PrintInorderName(Node* ptr){//traveling all node as manner of inorder for ascending order and write only Confirm subscriber on outputfile.
	if (root_name != NULL){//this function called by command if it had previous 'CONF'.  
		if (ptr->getN_Left() != NULL && ptr->getConfirm() == 1){//so check the node's statement whether Confirm or not.
			PrintInorderName(ptr->getN_Left());//shift the left keeping on for inorder traveling
		}
		//write on outputfile
		if (ptr->getConfirm() == true){//when the node's statement is Confirm
			output << ptr->getFirstName() << " " << ptr->getLastName() << "\t" << ptr->getPhoneNumber() << "\t\t" << ptr->getSequenceNumber() << "\t\t";
			if (ptr->getConfirm() == true){//maybe the node in here will be Confrim, but one more time pull the data from node 
				output << "Confirm" << endl;
			}
			else{//anyone doesn't come in here in this loop, however this can show to pull data in real
				output << "Wait List" << endl;
			}
		}
		else{
			//this empty space enable to omit WaitList in BST
		}		
		
		if (ptr->getN_Right() != NULL && ptr->getConfirm() == 1){
			PrintInorderName(ptr->getN_Right());//go to right Node when parent node has right child.
			//and then start to check left by reculsive function
		}
	}
	else{//when root doesn't exist, send error msg
		output << "There are no targets yet to be printed." << endl;
	}
}
void BST::PrintInorderSequence(Node* ptr){
	if (root_sequence != NULL){//this function called by command if it had previous 'CONF'. 
		if (ptr->getS_Left() != NULL && ptr->getConfirm() == 1){//so check the node's statement whether Confirm or not.
			PrintInorderSequence(ptr->getS_Left());//shift the left keeping on for inorder traveling
		}
		//write on outputfile
		if (ptr->getConfirm() == true){//when the node's statement is Confirm
			output << ptr->getFirstName() << " " << ptr->getLastName() << "\t" << ptr->getPhoneNumber() << "\t\t" << ptr->getSequenceNumber() << "\t\t";
			if (ptr->getConfirm() == true){//maybe the node in here will be Confrim, but one more time pull the data from node 
				output << "Confirm" << endl;
			}
			else{//anyone doesn't come in here in this loop, however this can show to pull data in real
				output << "Wait List" << endl;
			}
		}
		else{
			//this empty space enable to omit WaitList in BST
		}
		//til here wirte statement

		if (ptr->getS_Right() != NULL && ptr->getConfirm() == 1){
			PrintInorderSequence(ptr->getS_Right());//go to right Node when parent node has right child.
			//and then start to check left by reculsive function
		}
	}
	else{//when root doesn't exist, send error msg
		output << "There are no targets yet to be printed." << endl;
	}
}
void BST::PrintInorderPhone(Node* ptr){
	if (root_phone != NULL){//this function called by command if it had previous 'CONF'. 
		if (ptr->getP_Left() != NULL && ptr->getConfirm() == 1){//so check the node's statement whether Confirm or not.
			PrintInorderPhone(ptr->getP_Left());//shift the left keeping on for inorder traveling
		}
		//write on outputfile
		if (ptr->getConfirm() == true){//when the node's statement is Confirm
			output << ptr->getFirstName() << " " << ptr->getLastName() << "\t" << ptr->getPhoneNumber() << "\t\t" << ptr->getSequenceNumber() << "\t\t";
			if (ptr->getConfirm() == true){//maybe the node in here will be Confrim, but one more time pull the data from node 
				output << "Confirm" << endl;
			}
			else{//anyone doesn't come in here in this loop, however this can show to pull data in real
				output << "Wait List" << endl;
			}
		}
		else{
			//this empty space enable to omit WaitList in BST
		}
		//til here wirte statement

		if (ptr->getP_Right() != NULL && ptr->getConfirm() == 1){
			PrintInorderPhone(ptr->getP_Right());//go to right Node when parent node has right child.
			//and then start to check left by reculsive function
		}
	}
	else{//when root doesn't exist, send error msg
		output << "There are no targets yet to be printed." << endl;
	}
}

void BST::Delete(Node* target){//Delete function included Cancel
	Node* reference = root_sequence;
	//find the target node to delete
	//so using the way sequence tree that spread one direction
	while(reference){//til end of tree
		if (reference == target){
			break;//if it find the target, escape the loop for finding target
		}
		else{//go to next node
			reference = reference->getS_Right();//sequence tree spread only right direction
		}
	}//while	
	if (reference == NULL){//if target doesn't exist in tree, send error msg and end this function
		output << "There is no corresponding subscriber.\n" << endl;
	}
	else{//start the delete, if it is found
		allNumberNode = allNumberNode - 1;//this subtract one from the number of all node
		//delete target in each tree and then would be re-arranged tree each bottom function inner
		//should leave the node not to delete, it is necessity other trees.
		Delete_S(target);//delete target from sequence tree
		Delete_N(target);//delete target from name tree
		Delete_P(target);//delete target from phone tree
		
		if (target->getConfirm() == false){//if target is WaitList, should delete it from Queue
			myqueue.Delete_Queue(target);//BST class has myqueue object so call the this
		}
		delete target;//and Last free memory target
	}//when target exist
}
void BST::Delete_S(Node* target){//deletion from sequence tree is very simple than others, As you know this spread only right	
	Node* ptr = root_sequence;//ptr can be role of shifting for searching target
	Node* targetbefore = NULL;//targetbefore shadow behind ptr address
	//the reason why distinguish target is root or not is that if target is root, need to declation that root is NULL.
	if (target == root_sequence){//if target is root,
		root_sequence = ptr->getS_Right();//root is NULL
		ptr->setS_Right(NULL);//ptr's Right for Sequence tree will be NULL
	}
	else{//in case, target is not root, then Let's find the target
		while (ptr->getSequenceNumber() != target->getSequenceNumber()){//find target
			targetbefore = ptr;
			ptr = ptr->getS_Right();//shift the Right
		}//escape from this loop, ptr will be statement to reach on the target.
		
		//case0 - parent has no child
		if (ptr->getS_Right() == NULL){
			targetbefore->setS_Right(NULL);//targetbefore's next(right) is NULL, means way to go target is cut
		}
		//case1 - parent has only right node(because of trait that sequence spread only right
		else{//targetbefore's next(right) is target's right
			targetbefore->setS_Right(ptr->getS_Right());
		}
		//all case are over
		//and then initialization ptr's right is null
		ptr->setS_Right(NULL);
	}
}
void BST::Delete_N(Node* target){
	
	Node* ptr = root_name;//ptr can be role of shifting for searching target
	Node* targetbefore=NULL;//targetbefore shadow behind ptr address
	
	while (ptr->getSequenceNumber() != target->getSequenceNumber()){//the reason why use sequence, in name tree is that all node in any tree share the same data
		targetbefore = ptr;//targetBefore shadow ptr's behind
		//however find the node original method not the way using sequence rather than more simple
		//find target Node
		if (ptr->getLastName() > target->getLastName()){//if ptr bigger than target 
			ptr = ptr->getN_Left();
		}
		else if (ptr->getLastName() < target->getLastName()){
			ptr = ptr->getN_Right();
		}
		else{//this case is one has same Last name,
			//and then compare the Firstname,instead
			if (ptr->getFirstName() >target->getFirstName()){
				ptr = ptr->getN_Left();
			}
			else if (ptr->getFirstName() < target->getFirstName()){
				ptr = ptr->getN_Right();
			}
		}
	}
	//Process of re-arrange the empty position where had created by deletion
	//this have three cases. parent have no one, have either, and last have both
	if (ptr->getN_Left() == NULL && ptr->getN_Right() == NULL){//case0 - target has no one
		targetbefore->getN_Right() == target ?//find target position from the perspective of parent Node 
			targetbefore->setN_Right(NULL) ://case 1 : child node(target) is right
			targetbefore->setN_Left(NULL);//case 2: child node is left
		if (target == root_name){//should check target is root, if it is correct, then root's address should initialize as NULL
			root_name = NULL;
		}
	}
	//case 1 is divided right case and left case like 1-1, 1-2
	else if (ptr->getN_Left() == NULL && ptr->getN_Right() != NULL){//case1-1 - target has only right node
		if (targetbefore != NULL){//targetbefore is NULL means that target is root.
			//in this case programm couldn't access targetbefore, since it is NULL
			targetbefore->getN_Right() == target ?//find target position from the perspective of parent Node  
				targetbefore->setN_Right(target->getN_Right()) : //case 1 : child node(target) is right
				targetbefore->setN_Left(target->getN_Right()); //case 2: child node is left
		}
		else{//if targetbefore is null, no need to find target position from the perspective of targetbefore 
			//just need to rearrange root address
			root_name = target->getN_Right();			
		}
		target->setN_Right(NULL);//target's Name Pointer set NULL.		
	}
	else if (ptr->getN_Left() != NULL && ptr->getN_Right() == NULL){//case1-2 - target has only left node
		if (targetbefore != NULL){//Likewise when deal case 1-1, let's rearrange nodes
			targetbefore->getN_Right() == target ? 
				targetbefore->setN_Right(target->getN_Left()) :
				targetbefore->setN_Left(target->getN_Left());
		}
		else{
			root_name = target->getN_Left();
		}
		target->setN_Left(NULL);		
	}

	else{//case2 - parent has both node
		//in this case, find the smallest from parent's right subtree. smallest will be located leftmost
		//after find smallest, smallest node take possession of target position
		Node* smallest = target->getN_Right();//the smallest node is in parent's right subtree
		Node* smallestbefore = NULL;//smallestbefore used to connect with smallest's right, if smallest has right node.
		while (smallest->getN_Left()){//find to smallest
			smallestbefore = smallest;//smallestbefore shadow behind smallest
			smallest = smallest->getN_Left();//keep going til find smallest
		}

		if (smallestbefore == NULL){//smallestbefore is null means that target's right child is smallest. no other exist in tree.
			if (targetbefore != NULL){
				targetbefore->getN_Right() == target ?//find target position from the perspective of parent Node
					targetbefore->setN_Right(target->getN_Right()) ://smallest is connected with targetbefore. target->getN_Right is smallest
					targetbefore->setN_Left(target->getN_Right());
			}
			else{//targetbefore is NULL means that target is root, but now root will be smallest cause of deletion target
				root_name = smallest;
			}
			//parent(target) has both child. so now smallest should has left child instead of target
			smallest->setN_Left(target->getN_Left());
			//initialize target's both name pointer is NULL
			target->setN_Left(NULL);
			target->setN_Right(NULL);			
		}// in case of smallestbefore is null
		else{//in case of smallestbefore exist
			//check to smallest has right child or not
			if (smallest->getN_Right() == NULL){//if smallest doesn't have right child, 
				smallestbefore->setN_Left(NULL);//smallestbefore's left(smallest position) is NULL
			}
			else{//However, if smallest have right child,
				smallestbefore->setN_Left(smallest->getN_Right());//smallestbefore's left(smallest position)should be connected wiht it's right
			}
			//and then connect targetbefore with smallest
			if (targetbefore == NULL){//targetbefore is NULL means that target is root
				root_name = smallest;//so smallest should become root
				//because targe have both child, smallest also will take these, left and right child.
				smallest->setN_Left(target->getN_Left());
				smallest->setN_Right(target->getN_Right());
				//initialize target's both name pointer is NULL
				target->setN_Left(NULL);
				target->setN_Right(NULL);
			}
			else{//in case of targetbefore exist
				targetbefore->getN_Right() == target ? // find target position from the perspective of parent Node, 
					targetbefore->setN_Right(smallest) ://and then connection with targetbefore and smallest
					targetbefore->setN_Left(smallest);
				//smallest take target's pointer what it is the way to go it's child
				smallest->setN_Left(target->getN_Left());
				smallest->setN_Right(target->getN_Right());
				//initialize target's both name pointer is NULL
				target->setN_Left(NULL);
				target->setN_Right(NULL);
			}
		}//case of smallest exist
	}//case2 - parent has both node
}
void BST::Delete_P(Node* target){
	
	Node* ptr = root_phone;//ptr can be role of shifting for searching target
	Node* targetbefore=NULL;//targetbefore shadow behind ptr address
	
	while (ptr->getPhoneNumber() != target->getPhoneNumber()){//this loop will run til equal ptr with target
		targetbefore = ptr;//targetBefore shadow ptr's behind
		//find target Node
		ptr->getPhoneNumber() > target->getPhoneNumber() ?//if ptr's phonenumber is bigger than target's it,
			ptr = ptr->getP_Left() ://go to Left for finding target
			ptr = ptr->getP_Right();//else go to Right
	}
	//in here, ptr=target's position,  targetbefore=behind target.
	if (ptr->getP_Left() == NULL && ptr->getP_Right() == NULL){//case0 - target has no one
		targetbefore->getP_Right() == target ?//find target position from the perspective of parent Node 
			targetbefore->setP_Right(NULL) ://case 1 : child node(target) is right
			targetbefore->setP_Left(NULL);//case 2: child node is left
		if (target == root_phone){//should check target is root, if it is correct, then root's address should initialize as NULL
			root_phone = NULL;
		}
	}
	//case 1 is divided right case and left case like 1-1, 1-2
	else if (ptr->getP_Left() == NULL && ptr->getP_Right() != NULL){//case1-1 - target has only right node
		if (targetbefore != NULL){//targetbefore is NULL means that target is root.
			//in this case programm couldn't access targetbefore, since it is NULL
			targetbefore->getP_Right() == target ?//find target position from the perspective of parent Node  
				targetbefore->setP_Right(target->getP_Right()) : //case 1 : child node(target) is right
				targetbefore->setP_Left(target->getP_Right()); //case 2: child node is left
		}
		else{//if targetbefore is null, no need to find target position from the perspective of targetbefore 
			//just need to rearrange root address
			root_phone = target->getP_Right();
		}
		target->setP_Right(NULL);//target's Phonee Pointer set NULL.		
	}
	else if (ptr->getP_Left() != NULL && ptr->getP_Right() == NULL){//case1-2 - target has only left node
		if (targetbefore != NULL){//Likewise when deal case 1-1, let's rearrange nodes
			targetbefore->getP_Right() == target ?
				targetbefore->setP_Right(target->getP_Left()) :
				targetbefore->setP_Left(target->getP_Left());
		}
		else{
			root_phone = target->getP_Left();
		}
		target->setP_Left(NULL);
	}

	else{//case2 - parent has both node
		//in this case, find the smallest from parent's right subtree. smallest will be located leftmost
		//after find smallest, smallest node take possession of target position
		Node* smallest = target->getP_Right();//the smallest node is in parent's right subtree
		Node* smallestbefore = NULL;//smallestbefore used to connect with smallest's right, if smallest has right node.
		while (smallest->getP_Left()){//find to smallest
			smallestbefore = smallest;//smallestbefore shadow behind smallest
			smallest = smallest->getP_Left();//keep going til find smallest
		}

		if (smallestbefore == NULL){//smallestbefore is null means that target's right child is smallest. no other exist in tree.
			if (targetbefore != NULL){
				targetbefore->getP_Right() == target ?//find target position from the perspective of parent Node
					targetbefore->setP_Right(target->getP_Right()) ://smallest is connected with targetbefore. target->getN_Right is smallest
					targetbefore->setP_Left(target->getP_Right());
			}
			else{//targetbefore is NULL means that target is root, but now root will be smallest cause of deletion target
				root_phone = smallest;
			}
			//parent(target) has both child. so now smallest should has left child instead of target
			smallest->setP_Left(target->getP_Left());
			//initialize target's both phone pointer is NULL
			target->setP_Left(NULL);
			target->setP_Right(NULL);
		}// in case of smallestbefore is null
		else{//in case of smallestbefore exist
			//check to smallest has right child or not
			if (smallest->getP_Right() == NULL){//if smallest doesn't have right child, 
				smallestbefore->setP_Left(NULL);//smallestbefore's left(smallest position) is NULL
			}
			else{//However, if smallest have right child,
				smallestbefore->setP_Left(smallest->getP_Right());//smallestbefore's left(smallest position)should be connected wiht it's right
			}
			//and then connect targetbefore with smallest
			if (targetbefore == NULL){//targetbefore is NULL means that target is root
				root_phone = smallest;//so smallest should become root
				//because targe have both child, smallest also will take these, left and right child.
				smallest->setP_Left(target->getP_Left());
				smallest->setP_Right(target->getP_Right());
				//initialize target's both name pointer is NULL
				target->setP_Left(NULL);
				target->setP_Right(NULL);
			}
			else{//in case of targetbefore exist
				targetbefore->getP_Right() == target ? // find target position from the perspective of parent Node, 
					targetbefore->setP_Right(smallest) ://and then connection with targetbefore and smallest
					targetbefore->setP_Left(smallest);
				//smallest take target's pointer what it is the way to go it's child
				smallest->setP_Left(target->getP_Left());
				smallest->setP_Right(target->getP_Right());
				//initialize target's both name pointer is NULL
				target->setP_Left(NULL);
				target->setP_Right(NULL);
			}
		}//case of smallest exist
	}//case2 - parent has both node
}
void BST::Update(char* FirstName, char* LastName, char* phoneNumber){//Update function should find the target by using subscriber's nmae as key
	Node* findNode = root_name;//so, start at root name
	//til match the informed from File class 

	while (findNode->getFirstName() != FirstName && findNode->getLastName() != LastName){
		//if both condition is satisfied, findNode is matching with the function's parameter
		//so then, escape this
		//omit comparation, because I still explain what is that values is more bigger or smaller, before.
		if (findNode->getLastName() > LastName){
			findNode = findNode->getN_Left();
		}
		else if (findNode->getLastName() < LastName){
			findNode = findNode->getN_Right();
		}
		else{//if the node has same Last name, next cosider First name is same or not
			if (findNode->getFirstName() > FirstName){
				findNode = findNode->getN_Left();
			}
			else if (findNode->getFirstName() < FirstName){
				findNode = findNode->getN_Right();
			}
		}
		if (findNode != NULL){//this condition help to decide whether find the node or not
		}
		else{//if it couldn't find the node, escape here, and findeNode state is NULL.
			break;
		}
	}//while
	//from here, FindNode has same data with function's parameter
	if (findNode != NULL){//in case, find the findeNode
		Delete_P(findNode);//call the function to delete in BST, since phone number will be update only in phone tree
		findNode->setPhoneNumber(phoneNumber);//convert to paramter from old number
		insertPhone(findNode, root_phone);//for re-arrange the node in Name tree
		//print result
		output << "======================================================================" << endl;
		output << "   Name=======Phone-number===Reservation number===Reserve status" << endl;
		output << "======================================================================" << endl;
		output << findNode->getFirstName() << " " << findNode->getLastName() << "\t" << findNode->getPhoneNumber() << "\t\t" << findNode->getSequenceNumber() << "\t\t";
		if (findNode->getConfirm() == true){
			output << "Confirm" << endl;
		}
		else{
			output << "Wait List" << endl;
		}
		output << endl;
	}//til here in case find the findNode
	else{//else if it doesn't find the node what have same name with parameter, update function cann't be excute.
		//so send error msg
		output << "Update error - Incorrect Name" << endl;
	}
}
void BST::Print_phone(char* phoneNumber){//write only one's data who is demanded to print by using phoneNumber as key
	Node* findNode = root_phone;//start from root phone
	while (findNode->getPhoneNumber() != phoneNumber && findNode != NULL){//this loop check the findNode's phoneNumber same with parameter
		if (findNode->getPhoneNumber() > phoneNumber){//if findNode's phoneNumber is bigger than parameter, findNode would be shifted left
			findNode = findNode->getP_Left();
			if (findNode == NULL){
				break;
			}
		}
		else if (findNode->getPhoneNumber() < phoneNumber){//else if findNode's phoneNumber is smaller than parameter shift right
			findNode = findNode->getP_Right();
		}
		
	}//while, after escape this, result is that find node what is demand to print or not, then findNode will be NULL
	if (findNode == NULL){//if findNode is  NULL, that mean couldn't find one have same phone number
		//send error msg
		output << "fail to search one have this phonenumber" << endl;
	}
	else{//in case, findNode is same with parameter, then write current node's information
		output << "======================================================================" << endl;
		output << "   Name=======Phone-number===Reservation number===Reserve status" << endl;
		output << "======================================================================" << endl;
		output << findNode->getFirstName() << " " << findNode->getLastName() << "\t" << findNode->getPhoneNumber() << "\t\t" << findNode->getSequenceNumber() << "\t\t";
		if (findNode->getConfirm() == true){
			output << "Confirm" << endl;
		}
		else{
			output << "Wait List" << endl;
		}
		output << endl;
	}//else
}
void BST::Print_Name(char* FirstName, char* LastName){//write only one's data who is demanded to print by using name as key
	Node* findNode = root_name;//start from root name	
	while (findNode->getFirstName() != FirstName && findNode->getLastName() != LastName){
		//this loop check the findNode's name same with parameter
		if (findNode->getLastName() >LastName){//if findNode's LastName is bigger than parameter, findNode would be shifted left
			findNode = findNode->getN_Left();
		}
		else if (findNode->getLastName() < LastName){//else if findNode's LastName is smaller than parameter, findNode would be shifted right
			findNode = findNode->getN_Right();
		}
		else if (findNode->getLastName() == LastName){//else, same LastName exist, check the FirstName to know where findNode will go
			if (findNode->getFirstName() >FirstName){//if findNode's FirstName is bigger than parameter, findNode would be shifted left
				findNode = findNode->getN_Left();
			}
			else if (findNode->getFirstName() < FirstName){//else if findNode's FirstName is smaller than parameter, findNode would be shifted right
				findNode = findNode->getN_Right();
			}			
		}
		//check findNode is NULL or not
		if (findNode != NULL){
		}
		else{
			break;//if findeNode is null, this function wouldn't execute.
		}
	}//while,  after escape this, result is that find node what is demand to print or not, then findNode will be NULL
	
	if (findNode == NULL){//if findNode is  NULL, that mean couldn't find one have same name
		//send error msg
		output << "fail to search one have this Name" << endl;
	}
	else{//in case, findNode is same with parameter, then write current node's information
		output << "======================================================================" << endl;
		output << "   Name=======Phone-number===Reservation number===Reserve status" << endl;
		output << "======================================================================" << endl;
		output << findNode->getFirstName() << " " << findNode->getLastName() << "\t" << findNode->getPhoneNumber() << "\t\t" << findNode->getSequenceNumber() << "\t\t";
		if (findNode->getConfirm() == true){
			output << "Confirm" << endl;
		}
		else{
			output << "Wait List" << endl;
		}
		output << endl;
	}//else
}
void BST::Print_WaitList(){//print WaitList will be executed in Queue class
	
	myqueue.Print();//call Print function in Queue class

}
void BST::Cancel_N(char* FirstName, char* LastName){//cancel the one in all BST. but this command give Name parameter to search the subscriber
	Node* findNode = root_name;//start to search at root_name
	//Search the target via name tree.
	while (findNode->getFirstName() != FirstName && findNode->getLastName() != LastName){
		//this loop check the findNode's name same with parameter
		if (findNode->getLastName() >LastName){//if findNode's LastName is bigger than parameter, findNode would be shifted left
			findNode = findNode->getN_Left();
		}
		else if (findNode->getLastName() < LastName){//else if findNode's LastName is smaller than parameter, findNode would be shifted right
			findNode = findNode->getN_Right();
		}
		else{//else, same LastName exist, check the FirstName to know where findNode will go
			if (findNode->getFirstName() >FirstName){//if findNode's FirstName is bigger than parameter, findNode would be shifted left
				findNode = findNode->getN_Left();
			}
			else if (findNode->getFirstName() < FirstName){//else if findNode's FirstName is smaller than parameter, findNode would be shifted right
				findNode = findNode->getN_Right();
			}
		}
		//check findNode is Null or not
		if (findNode != NULL){
		}
		else{
			break;//if findeNode is null, this function wouldn't execute.
		}
	}//while,  after escape this, result is that find node what is demand to print or not, then findNode will be NULL

	if (findNode != NULL){//case 0 : findeNode is not NULL --> then ready to start deletion
		if (findNode->getConfirm() == true){//check that the target's state is Confirm or WaitList
			if (allNumberNode > 25){//if all number of node is bigger than 25, it should be deleted additionally in Queue 
				Node* convert = myqueue.Pop();//take address about First subscriber's node
				convert->setConfirm(true);//then turn to Confirm state from WaitList
				myqueue.Delete_Queue(convert);//last, delete the node in queue
			}
			else{
				//if all number of node is smaller than 25, no need to delte the node in queue.
				//it willn't exsist there 
			}
		}
		//wirte output file via ofstream's output variable
		output << "======================================================================" << endl;
		output << "   Name=======Phone-number===Reservation number===Reserve status" << endl;
		output << "======================================================================" << endl;
		output << findNode->getFirstName() << " " << findNode->getLastName() << "\t" << findNode->getPhoneNumber() << "\t\t" << findNode->getSequenceNumber() << "\t\t" << "Cancel\n";
		output << endl;
		//call Delete function in BST class
		Delete(findNode);
	}
	else{//case 1 : findNode is NULL
		output << "CANCEL -error" << endl;
	}
}
void BST::Cancel_S(int sequenceNumber){//cancel the one in all BST. but this command give sequenceNumber parameter to search the subscriber
	Node* findNode = root_sequence;//start to search at root_sequence
	//Search the target via sequence tree.
	while (findNode->getSequenceNumber() != sequenceNumber){
		//this loop check the findNode's name same with parameter
		if (findNode->getSequenceNumber() > sequenceNumber){//if findNode's sequenceNumber is bigger than parameter, findNode would be shifted left
			findNode = findNode->getS_Left();
		}
		else if (findNode->getSequenceNumber() < sequenceNumber){
			findNode = findNode->getS_Right();
		}
		//however this loop will be execute only right direction. sequence tree spead only right side
		//check findNode is Null or not
		if (findNode != NULL){
		}
		else{
			break;//if findeNode is null, this function wouldn't execute.
		}
	}//while,  after escape this, result is that find node what is demand to print or not, then findNode will be NULL
	if (findNode != NULL){//case 0 : findeNode is not NULL --> then ready to start deletion
		if (findNode->getConfirm() == true){//check that the target's state is Confirm or WaitList
			if (allNumberNode > 25){//if all number of node is bigger than 25, it should be deleted additionally in Queue 
				Node* convert = myqueue.Pop();//take address about First subscriber's node
				convert->setConfirm(true);//then turn to Confirm state from WaitList
				myqueue.Delete_Queue(convert);//last, delete the node in queue
			}
			else{
				//if all number of node is smaller than 25, no need to delte the node in queue.
				//it willn't exsist there 
			}
		}
		//wirte output file via ofstream's output variable
		output << "======================================================================" << endl;
		output << "   Name=======Phone-number===Reservation number===Reserve status" << endl;
		output << "======================================================================" << endl;
		output << findNode->getFirstName() << " " << findNode->getLastName() << "\t" << findNode->getPhoneNumber() << "\t\t" << findNode->getSequenceNumber() << "\t\t" << "Cancel\n";
		output << endl;
		//call Delete function in BST class
		Delete(findNode);
	}
	else{//case 1 : findNode is NULL
		output << "CANCEL -error" << endl;
	}
}
void BST::Cancel_P(char* phoneNumber){//cancel the one in all BST. but this command give phoneNumber parameter to search the subscriber
	Node* findNode = root_phone;//start to search at root_phone
	//Search the target via phone tree.
	while (findNode->getPhoneNumber() != phoneNumber){
		//this loop check the findNode's name same with parameter
		if (findNode->getPhoneNumber() > phoneNumber){//if findNode's phoneNumber is bigger than parameter
			findNode = findNode->getP_Left();//findNode would be shifted left
		}
		else if (findNode->getPhoneNumber() < phoneNumber){//else if findNode's phoneNumber is smaller than parameter, 
			findNode = findNode->getP_Right();//findNode would be shifted right
		}
		//however this loop will be execute only right direction. sequence tree spead only right side
		//check findNode is Null or not
		if (findNode != NULL){
		}
		else{
			break;//if findeNode is null, this function wouldn't execute.
		}
	}//while,  after escape this, result is that find node what is demand to print or not, then findNode will be NULL
	if (findNode != NULL){//case 0 : findeNode is not NULL --> then ready to start deletion
		if (findNode->getConfirm() == true){// check that the target's state is Confirm or WaitList
			if (allNumberNode > 25){//if all number of node is bigger than 25, it should be deleted additionally in Queue 
				Node* convert = myqueue.Pop();//take address about First subscriber's node
				convert->setConfirm(true);//then turn to Confirm state from WaitList
				myqueue.Delete_Queue(convert);//last, delete the node in queue
			}
			else{
				//if all number of node is smaller than 25, no need to delte the node in queue.
				//it willn't exsist there 
			}
		}
		//wirte output file via ofstream's output variable
		output << "======================================================================" << endl;
		output << "   Name=======Phone-number===Reservation number===Reserve status" << endl;
		output << "======================================================================" << endl;
		output << findNode->getFirstName() << " " << findNode->getLastName() << "\t" << findNode->getPhoneNumber() << "\t\t" << findNode->getSequenceNumber() << "\t\t" << "Cancel\n";
		output << endl;
		//call Delete function in BST class
		Delete(findNode);
	}
	else{//case 1 : findNode is NULL
		output << "CANCEL -error" << endl;
	}
}