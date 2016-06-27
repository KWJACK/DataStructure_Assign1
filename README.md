# DataStructure_Assign1
*Introduction*

 This assignment was proceeded in fall semester of 2015.
Our purpose was to make reservation system for flight.
But obivously in here, we will make only particular part of database.

*Condition*

 Flight database is composed by records including name, reservation serial number, phone number, and state of confirmation.
 
  Only twenty five or less of seats possible to use are ready. But if all seats are reserved, it is possible to get 10 or less clients' reservation in state of waiting. If subscriber cancels the reservation, waiting state will be changed to confirmation depending on the reservation order.
 
  In here, the main operations being performed should be used to search, insert, delete, and (conditional) traverse on the tree(DS) about each node that saves the client's information. 
  
  In order to use client's information as key value, the BST should be separately composed by each client's value.
  
  In addition, there is a need for a queue to store the standby subscriber's information. Therefore, the complex data structure is a plurality of data structures that configure basing on the same node must be used. All data structures used must be configured by using the pointer.
 The functions essentially implemented as follows and also informed about the command for performing the respective functions.
 
*Specification*

In here all function's parameters have standard.

1.Name should be written as follows: last name + first name.
  Also, there must be one or more white space or tab between last and first name.
  
2.Phone-number is fixed and can consist of 7 characters only.

RESERVE [name] [phone-number]
  - Create Node included client info(name, serial number, phone number, and state of confirmation) and insert to BST.
  - After then print reservation result
  - Assume to not exist one who the same names and phone numbers
  

UPDATE [name] [phone-number]
  - Find the Node as key of inputed name, and update the phone-number
  - After then print changed the subscriber's information
  

CANCEL [ reservation number | name | phone-number]
  - Using the record(reservation number, or name, or phone-number) to find and delete the node containing the record
  - After then print cancelled result
  - If subscriber cancels, high priority waiter's state will be changed to confirmation
  - Else waiter will be changed to confirmation or cancel the reservation, and will be removed from the waiting list
  

PRINT [name | phone-number]
  - Print client info that matches with the name or phone number by using a key value(name or phone-number)

PRINT CONF [SEQNO | NAME | PHONE]
  - According to one option among three factors(SEQNO, NAME, PHONE), print all nodes.
  - All printing results should be sorted by ascending order

PRINT WAIT
  - Print waiting list by priority
  
*The configuration file*

Input data file

  - In this file the command to add and/or update a record or delete is written.
  
Output result file

  - Record the result of implement command and/or error mesg
  
