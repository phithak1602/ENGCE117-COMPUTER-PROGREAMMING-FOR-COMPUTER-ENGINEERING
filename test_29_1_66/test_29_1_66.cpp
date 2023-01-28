/* นายพิทักษ์ บุญน้อย 65543206027-6 Section 1 */
/* Link Youtube =  https://youtu.be/wqogKMr6-GY */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int data ;
    struct Node *next ;
} ;

void ShowAll( struct Node *walk ) ;
struct Node *AddNode ( struct Node **walk, int data ) ;
void Update( Node **start , int data , int data2) ;
void ShowBack( Node *start ) ;
void Swap( Node **start , int data , int data2) ;

int main() {
    struct Node *start, *now ;
    start = NULL ;
    now = AddNode( &start,10) ; 
    now = AddNode( &start,20) ;
    now = AddNode( &start,30) ; 
    now = AddNode( &start,40) ;
    printf( "--- function Update ---\n") ;
    ShowAll( start ) ;
    Update( &start,10,99) ;
    ShowAll( start ) ;
    Update( &start,11,98) ;
    ShowAll( start ) ;
    printf( "--- function Showback ---\n") ;
    Update( &start,99,10 ) ;
    ShowAll( start ) ;
    ShowBack( start ) ;
    printf( "--- function SwapNode ---\n") ;
    now = AddNode( &start,20) ;
    now = AddNode( &start,30) ; 
    now = AddNode( &start,40) ;
    ShowAll( start ) ;
    Swap( &start, 40, 10 ) ;
    ShowAll( start ) ;
    return 0 ;
}//end function main

void ShowAll( struct Node *walk ) {
    while( walk != NULL ) {
    printf( "%d ", walk->data ) ;
    walk = walk->next ;
    }//end while
    printf( "\n" ) ;
}//end function ShowAll

struct Node *AddNode ( struct Node **walk, int data) {
	while ( (*walk) != NULL ) {
		walk = &(*walk)->next ;
	}//end while 
	*walk = new struct Node ;
	(*walk)->data = data ;
	(*walk)->next = NULL ;
	return *walk ;
}//end struct Node *AddNode

void Update( Node **start , int data , int data2) {
    Node  *newnode = *start ;
    while ( newnode != NULL && newnode->data != data ) {
        newnode = newnode->next ;
    }//end if
    if ( newnode != NULL ) {
        newnode->data = data2 ;
    }else {
        printf( "Not Data %d\n",data ) ;
    }//end else
}//end function Update

void ShowBack( Node *start ) {
    Node *newnode , *nextnode ;
    if ( start != NULL ) {
        newnode = start ;
        nextnode = start->next ;
        start = start->next ;
        newnode->next = NULL ;
        while ( start != NULL ) {
            start = start->next ;
            nextnode->next = newnode ;
            newnode = nextnode ;
            nextnode = start ;
        }//end while
        start = newnode ;
    }//end if
    ShowAll( start ) ;
}//end function ShowBack

void Swap( Node **start , int data , int data2 ) {
    if ( data == data2 )
        return ;
    Node *dataA1 ,*dataB1 ;
    dataA1 = NULL ;
    dataB1 = *start ;
    while ( dataB1 && dataB1->data != data ) {
        dataA1 = dataB1;
        dataB1 = dataB1->next;
    }//end while
    Node *dataA2 ,*dataB2 ;
    dataA2 = NULL ;
    dataB2 = *start ;
    while ( dataB2 && dataB2->data != data2 ) {
        dataA2 = dataB2 ;
        dataB2 = dataB2->next ;
    }//end while
    if ( dataB1 == NULL || dataB2 == NULL )
        return ;
    if ( dataA1 != NULL ) {
        dataA1->next = dataB2 ;
    }else {
        *start = dataB2 ;
    }//end if else
    if ( dataA2 != NULL ) {
        dataA2->next = dataB1 ;
    }else {
        *start = dataB1 ;
    }//end if else
    Node *temp = dataB2->next ;
    dataB2->next = dataB1->next ;
    dataB1->next = temp ;
}//end function Swap
