#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
} ;

class LinkedList {
 protected :
  struct studentNode *start, **now ;
 public :
  LinkedList() ;
  ~LinkedList() ;
  void InsNode( char n[], int a, char s, float g ) ;
  void DelNode() ;
  void GoNext() ;
  void GoFirst() ;
  void GoLast() ;
  void ShowAll() ;
  int FindNode( char n[] ) ;
  struct studentNode *NowNode ;
  void EditNode( char n[], int a, char s, float g ) ;
};//end class

LinkedList :: LinkedList () {
	this -> start = NULL ;
	(this->now) = &(this->start) ;
}

LinkedList :: ~LinkedList () {
	printf("\nreturn memery by 1 list.") ;
}

void LinkedList :: InsNode( char n[], int a, char s, float g ) {
    if ( (*this->now) == NULL ){
		(*this->now) = new struct studentNode ;
		(*this->now)->next = NULL ;
		strcpy((*this->now)->name, n) ;
		(*this->now)->age = a ;
		(*this->now)->sex = s ;
		(*this->now)->gpa = g ;
	}
	else {
		struct studentNode *holder ;
		holder = new struct studentNode  ;
		strcpy((holder)->name, n) ;
		(holder)->age = a ;
		(holder)->sex = s ;
		(holder)->gpa = g ;
		(holder)->next = (*this->now) ;
		(*this->now) = holder ;
	}
	this->NowNode = this->start ;
}

void LinkedList :: DelNode() {
	struct studentNode *holder = new struct studentNode ;
	holder = (*this->now)->next ;
	(*this->now) = holder ;
	this->NowNode = this->start ;
}

void LinkedList :: GoNext() {
	(this->now) = &(*this->now)->next ;
}

void LinkedList :: GoFirst() {
	(this->now) = &(this->start) ;
}

void LinkedList :: GoLast() {
	while( (*this->now)->next != NULL ) {
  		( this->now) = &(*this->now)->next ;
 	}//end while
}

void LinkedList :: ShowAll() {
  	struct studentNode *holder = this->start ;
    while( holder != NULL ) {
  	    printf( "%s ", holder->name ) ;
  	    holder = holder->next ;
    }//end while
 printf( " \n" ) ;
}

int LinkedList :: FindNode( char n[] ) {
	int i = 0 ;
	struct studentNode *holder = this->start ;
	while ( strcmp(holder->name, n) != 0 ){
		if ( holder->next == NULL ) {
			printf("Not Found Data.") ;
			i = -1 ;
			break;
		}//end if
		holder = holder->next ;
		i++;
	}//end while
	if ( i != -1 ) {
		(*this->now) = holder ;
	}//end if
	return i ;
}

void LinkedList :: EditNode( char n[], int a, char s, float g ) {
	strcpy((*this->now)->name, n) ;
	(*this->now)->age = a ;
	(*this->now)->sex = s ;
	(*this->now)->gpa = g ;
	this->NowNode = this->start ;
	
}

void EditData( LinkedList *ll ) ;
void AddData( LinkedList *ll ) ;
void FindData( LinkedList *ll ) ;
void readfile( LinkedList *ll ) ;
void writefile( LinkedList *ll ) ;

int main() {
 LinkedList listA ;
    int menu ;
    printf( "  Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : " ) ;
    scanf( "%d", &menu ) ;
    while( menu != 0 ) {
        switch( menu ) {
            case 1 : AddData( &listA ) ; break ;
            case 2 : EditData( &listA ) ; break ;
            case 3 : listA.DelNode() ; break ;
            case 4 : FindData( &listA ) ; break ;
        }//end switch
        printf( "  Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : " ) ;
        scanf( "%d", &menu ) ;
    }//end while
    return 0 ;
}//end function

void EditData( LinkedList *ll ) {
	char name[ 20 ] ;
 	int age ;
 	char sex ;
 	float gpa ;
	getchar() ;
	gets( name ) ;
 	printf("Edit your data\n\tname :") ;
 	getchar() ;
 	gets( name ) ;
 	printf("\tname age :") ;
 	scanf( "%d", &age ) ;
 	printf("\tname sex :") ;
 	scanf( "%c", &sex ) ;
 	printf("\tname gpa :") ;
 	scanf( "%f", &gpa ) ;
	ll->EditNode( name, age, sex, gpa ) ;
}//end function EditData

void AddData( LinkedList *ll ) {
	char name[ 20 ] ;
 	int age ;
 	char sex ;
 	float gpa ;
 	printf("Add your data\n") ;
 	printf("name : ") ;
 	getchar() ;
 	gets( name ) ;
 	printf( "age : " ) ;
 	scanf( "%d", &age ) ;
 	printf("sex : " ) ;
 	getchar() ;
 	scanf( "%c", &sex );
 	printf("gpa : " );
 	scanf( "%f", &gpa ) ;
	ll->InsNode( name, age, sex, gpa ) ;
}//end function AddData

void FindData( LinkedList *ll ) {
	int i ;
	char name[ 20 ] ;
	printf("Find data :") ;
 	getchar() ;
 	gets( name ) ;
	i = ll->FindNode( name ) ;
}//end function FineData

void readfile( LinkedList *ll ) {
	FILE *fp ;
	fp = fopen("studernt.dat", "r+") ;
	if(fp == NULL) {
		printf("Don't Found your File.") ;	
	}//end if
	struct studentNode children ;
	while( fread(&children, sizeof(struct studentNode), 1, fp ) != 0 ){
		ll->InsNode( children.name, children.age, children.sex, children.gpa ) ;
	}//end while
	fclose( fp ) ;
}//end function readfile

void writefile( LinkedList *ll ) {
	FILE *fp ;
	fp = fopen("studernt.dat", "w+") ;
	if(fp == NULL) {
		printf("Don't Found your File.") ; exit( 0 ) ;	
	}//end if
	fwrite(ll->NowNode, sizeof(struct studentNode), 1, fp) ;
	fclose( fp ) ;
}//end function writefile