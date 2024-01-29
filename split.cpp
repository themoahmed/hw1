/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"



/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
    // Base case, Node in is an empty list 
    if (in == nullptr) {

        odds = nullptr;

        evens = nullptr;
        //Will return both lists as null
        return;
    }

    // Recursive cases 


    if (in->value % 2 == 0) {
        // Current node has an even value

       
        if (evens == nullptr) {
            //adds node to even
            evens = in;

            //Sets the head to the next node effectively removing the current node.
            in = in->next;

            // Cut off the current node from the input list
            evens->next = nullptr; 

            //call split function again  
            split(in, odds, evens->next);

        } 
        
    } else {
        // Current node has an odd value
        if (odds == nullptr) {

            odds = in;

            in = in->next;
            
            // Cut off the current node from the input list
            odds->next = nullptr; 

            split(in, odds->next, evens);
        } 
        
    }


}