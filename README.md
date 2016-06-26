# DataStructure_Assign1
*Introduction*

 This assignment proceeded in fall semester 2015.
Our purpose is making reservation system for flight.
But obivously in here, we will make only part of database.

*Condition*

 Flight database is composed record including name, reservation serial number, phone number, and state of confirmation.
 
 The number of enable seats only ready til twenty five. But in case of all seated had reserved, it is possible to get more 10 client's reservation as state of waiter. 
If subscriber cancels the reservation, waiter state will be changed confirmation depending on the reservation order.
 
In here, the main operations to be performed should be used to search, insert, delete, and (conditional) traversal about each node what saves the client's information.
 In order to using client's information as to key value, the BST should separately composed by each client's value.
 
In addition, there is a need for a queue to store the standby subscriber information. Therefore, the complex data structure a plurality of data structures that are configured based on the same node must be used. All data structures used must be configured by using the pointer.
 The functions to be implemented essentially as follows, has been designated, the command for performing the respective functions.
 
*Specification*
In here all function's parameter have standard.

1.Name should be written last name + first name. And one more white space or tab exists between last and first name
2.Phone-number is fixed only 7 characters.

RESERVE [name] [phone-number]
  - Create Node included client info(name, serial number, phone number, and state of confirmation) and insert to BST.
  - After then print reservation result
  - Assume to not exist one who the same names and phone numbers
  

UPDATE [name] [phone-number]
  - Find the Node as key of inputed name, and update the phone-number
  - After then print changed subscriber information
  

CANCEL [ reservation number | name | phone-number]
  - Using of record(reservation number, name or phone-number) to find and delete the node containing the record
  - After then print cancel result
  - If subscriber cancel, high priority waiter's state will be changed to confirmation
  - Else waiter was changed to confirmation or cancel the reservation, removed from the waiting list
  

PRINT [name | phone-number]

  -Print client info that match the name or phone number by using a key value(name or phone-number)

PRINT CONF [SEQNO | NAME | PHONE]

  -According to one option among three factors(SEQNO, NAME, PHONE), print all node.
  -All printing result should be sorted by ascending order

PRINT WAIT

  -Print wait list by priority
  
  
*The configuration file*

Input data file

  -This file is written command add, update a record or delete.
  
Output result file

  -Record the result of implement command and error mesg
  
