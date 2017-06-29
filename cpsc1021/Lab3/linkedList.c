/*************************
 CPSC 1021 - Computer Science II Laboratory

 File: Linked_List.c
 Purpose: Debugging file for Lab3

 ************************/

#include <stdio.h>
#include <stdlib.h>


// define the node struct
/*This linked list is going to be created using structures.  It has two
 *data members:  an int that holds the an integer value.  It also has a
 *pointer to a struct of the same type this structure is.  This is
 *called self-referrential data type.  We will referred to all structures
 *created of this type as node.*/
typedef struct node_type{
    int val;
    struct node_type * next;
} node;


int main()
{

    //declare variables
    /*The variable head is a pointer to the beginning of the list*/
    node *head;
    int i;

   /*Here we are going to create a list of 10 nodes.  */

    for(i=1;i<=10;i++)
    {
        /*create a node to represent the current node and allocate
         *memory for the node*/
        node* curr;
        curr = (node*)malloc(sizeof(node));

        /*Now that we have a node we need to give val a value and then
         *place it at the front of the list.  We do this 10 times each
         *time placing the new node at the beginning of the list.*/
        curr->val = i;
        curr->next = head;
        head = curr;
    }

    /*This simply iterates through the list and prints the value of the variable val
     *starting at the begining of the list*/

    while(head!=NULL) {
        printf("value = %i\n", head->val);
        head = head->next ;
    }

    printf("\nFinished running program.");

   return 0;
}
