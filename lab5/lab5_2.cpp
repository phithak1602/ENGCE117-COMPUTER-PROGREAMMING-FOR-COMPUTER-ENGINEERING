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

void ShowAll( struct studentNode **node) ;
void InsNode( struct studentNode **node, const char *name, int age, char sex, float gpa ) ;
void GoNext( struct studentNode ***node ) ;
void DelNode( struct studentNode **node ) ;

int main() {
    struct studentNode *start, **now;
    start = NULL;
    now = &start;
    InsNode(now, "one", 6, 'M', 3.11);
    ShowAll(&start);
    InsNode(now, "two", 8, 'F', 3.22);
    ShowAll(&start);
    GoNext(&now);
    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(&start);
    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(&start);
    GoNext(&now);
    DelNode(now);
    ShowAll(&start);
    return 0;
}//end function main

void ShowAll(struct studentNode **walk) {
    while (*walk != NULL) {
        printf("%s ", (*walk)->name);
        walk = &(*walk)->next;
    }//end while
    printf("\n");
}//end function ShowAll

void InsNode(struct studentNode **node, const char *name, int age, char sex, float gpa) {
    struct studentNode *newnode = new studentNode ;
    struct studentNode *before = *node ;
    if (*node == NULL) {
        *node = new studentNode ;
        (*node)->next = NULL ;
    }//end if
    strcpy(newnode->name, name) ;
    newnode->age = age ;
    newnode->sex = sex ;
    newnode->gpa = gpa ;
    newnode->next = NULL;
    newnode->next = (*node)->next ;
    *node = newnode ;
    (*node)->next = before ;
}//end function InsNode

void GoNext(struct studentNode ***node) {
    if (**node != NULL) {
        *node = &(**node)->next ;
    }//end if
}//end function GoNext

void DelNode(struct studentNode **node) {
  struct studentNode *delnode = *node;
  *node = (*node)->next;
  free(delnode);
}