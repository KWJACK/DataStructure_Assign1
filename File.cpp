#include "File.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
File::File()//Constructors
{
	inputfile.open("input.txt");	
	outputfile.open("output.txt", ios::out);//this line enable to write newly the file called 'output.txt', even it had existed that the old file smae with new file name
											//In short, clear the outputfile before start to write new version of outputfile.
	outputfile.close();//and then close the file, this file would be written nothing
	
	outputfile.open("output.txt", ios::app);//Now, all that writes to a file.
}
File::~File()//Destructors
{
	inputfile.close();//close inputfile written commands
	outputfile.close();//close outputfile when program end
}
//////////////////////////////////////////////////////////////////////////////////////////////
// File::Management()																		//
// =========================================================================================//
// Purpose: This function read the file in which is written commands per line, and then		//
//			call the function in the BST class for that command til end of file, repeatedly.//
//////////////////////////////////////////////////////////////////////////////////////////////
void File::Management(){
	char str[256];	
	
	if (inputfile.is_open() == false){//check to the file name. if it doesn't exist, print the msg "fail" on computer screen"
		cout << "Need to check the file name" << endl;
	}
	else{//If the file exist, this program run to record the command in inputfile.
		
		while (!inputfile.eof()){//this Loop will be run til end of file
			inputfile.getline(str, 256, '\n');//It reads one line separated by \n, up to 256 characters
			
			outputfile << str << endl;//Write command read from inputfile to the output file   ex) RESERVE, CANCEL, PRINT etc

			//tokenize one command to distinguish real command and information which is needed to find in tree(BST)
			char *ptoken = NULL, *cNULL = NULL, *storechar[5] = { 0 };//Each storechar variable is filed tokenized command
			//storechar[0]-real command for the execution of the program, and others are information or sub-command needed to run sophisticated
			int i = 1;
			ptoken = strtok_s(str, "\t ", &cNULL);
			storechar[0] = ptoken;
			do{//tokenize
				ptoken = strtok_s(NULL, "\t ", &cNULL);
				storechar[i] = ptoken;//In turn, ptoken is stored storechar
				i++;//go next the array  
			} while (ptoken);//till ptoken is filled 'NULL'

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (!strcmp(storechar[0], "RESERVE")){//The role of RESERVE command is that insert subscriber's informaion as form of Node sturcture
				//(If you're wondering what nodes, refer to explanation in Node class)
				mybst.Reserve(storechar[1], storechar[2], storechar[3]);//Call Reserve function in mybst object. each variable means FirstName, LastName, phoneNumber in order.
			}
			else if (!strcmp(storechar[0], "UPDATE")){//The role of UPDATE command is that renew the phone number about subscriber entered this command
				mybst.Update(storechar[1], storechar[2], storechar[3]);//Call Uptate function in mybst object. each variable means FirstName, LastName, phoneNumber in order.
			}
			else if (!strcmp(storechar[0], "CANCEL")){//The role of CANCEL command is that cancel the subscriber in reservation for airplain ticket system
				if (storechar[1] != NULL && storechar[2] != NULL){//Case0 : entered name
					mybst.Cancel_N(storechar[1], storechar[2]); //each variable means LastName, FirstName in order. Call Cancel_N function in mybst object.
				} // Name is consisted of First name, and Last name. So it can be used to distinguish with others, for example sequence number or phone number.
				else{
					if (strnlen_s(storechar[1], 6) < 5){//Case1 : entered sequence number. phoneNumber is fixed 6-digit number.
						//if sequenceNumber's digit is bigger than phoneNumber, it would be failed to execute. However this program is for a small number of users(up to 35 people)
						//In almost cases, you can not look at the error
						mybst.Cancel_S(atoi(storechar[1]));//sequnce. Call Cancel_S function in mybst object.
					}
					else{//Case2 : entered phone number
						mybst.Cancel_P(storechar[1]);//phone number. Call Cancel_P function in mybst object.
					}
				}				
			}
			else if (!strcmp(storechar[0], "PRINT")){//The role of PRINT command is that print the information about the Node or print all node as the manner of desired sorting
				//
				if (!strcmp(storechar[1], "CONF")){//Only print the confirm statement among all subscribers in mybst.
					//PRINT CONF command has three sub-commands, SEQNO, NAME and PHONE.
					if (!strcmp(storechar[2], "SEQNO")){
						mybst.PrintInorder_S();//sorting all subsribers information in ascending order of sequence. Call PrintInorder_S function in mybst object.
					}
					else if (!strcmp(storechar[2], "NAME")){
						mybst.PrintInorder_N();//sorting all subsribers information in ascending order of name. Call PrintInorder_N function in mybst object.
					}
					else if (!strcmp(storechar[2], "PHONE")){
						mybst.PrintInorder_P();//sorting all subsribers information in ascending order of phone number.  Call PrintInorder_P function in mybst object.
					}
					else{//If the command is typed strange-->send an error msg on outputfile
						outputfile << "Need to check the Command whether corret or not" << endl;
					}				
				}
				//PRINT WAIT command doesn't have sub-command.
				else if (!strcmp(storechar[1], "WAIT")){//Only print the WaitList statement among all subscribers in mybst.
					mybst.Print_WaitList();// Call Print_WaitList function in mybst object.
				}

				//Print only one subscriber's information
				else{
					if (storechar[2] != NULL){
						//if storechar[2] exsist, this means command is want to print one  about finding name 
						mybst.Print_Name(storechar[1], storechar[2]);
					}
					else{//if storechar[2] doesn't exsist, this mean command is want to print one about finding phonenumber
						mybst.Print_phone(storechar[1]);
					}
				}
			}// end case of PRINT command

			else{
				break;//in case of file ended the last character as \n or whitespace, means that not have anything to execute in "input.txt"
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		}//while(end of file)
		//inputfile.close()
	}//here is over reading the "input.txt"
}//end of read function