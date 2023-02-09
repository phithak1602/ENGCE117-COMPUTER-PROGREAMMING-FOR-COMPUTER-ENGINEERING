#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
} ;

void ShowAll( struct studentNode *walk );
struct studentNode *AddNode(struct studentNode **head, const char *name, int age, char sex, float gpa );
void InsNode( struct studentNode *walk, const char *name, int age, char sex, float gpa );
void DelNode( struct studentNode *walk );

int main() {
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);
    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(start);
    DelNode(now);
    ShowAll(start);
    return 0;
}

void ShowAll( struct studentNode *walk ) {
  while ( walk != NULL ) {
    printf ("%s ", walk->name );
    walk = walk->next ;
  } // end while
  printf( "\n" );
}//end function ShowAll

struct studentNode *AddNode( struct studentNode **head, const char *name, int age, char sex, float gpa ) {
    struct studentNode *current = NULL;
    struct studentNode *newnode = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy_s(newnode->name, name);
    newnode->age = age ;
    newnode->sex = sex ;
    newnode->gpa = gpa ;
    newnode->next = NULL ;
    if (*head == NULL) {
        *head = newnode ;
    } else {
        current = *head ;
        while (current->next != NULL) {
            current = current->next ;
        }//end whlie
        current->next = newnode ;
    }//end if else
    return newnode ;
}//end function DelNode

void InsNode( struct studentNode *head, const char *name, int age, char sex, float gpa ) {
    struct studentNode *newnode = (struct studentNode *)malloc(sizeof(struct studentNode)) ;
    strcpy_s( newnode->name, name ) ;
    newnode->age = age ;
    newnode->sex = sex ;
    newnode->gpa = gpa ;
    newnode->next = head->next ;
    head->next = newnode ;
}//end function InsNode

void DelNode( struct studentNode *node ) {
    struct studentNode *temp = node->next->next ;
    struct studentNode *delnode = node->next ;
    node->next = temp ;
    free(delnode) ;
}//end function DelNode