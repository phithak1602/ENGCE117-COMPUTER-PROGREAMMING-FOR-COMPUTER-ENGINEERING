#include <stdio.h>

long SumLoop( int ) ;
long SumRecur( int ) ;

int main() {
 printf( "SumLoop(n) = %d", SumLoop( 10 ) ) ;
 printf( "\nSumRecur(n) = %d", SumRecur( 10 ) ) ;
 return 0 ;
}//end function main

long SumLoop( int x ) {
	int sum = 0 ;
	for(int i = 1 ; i <= x ; i++ ){
		sum = sum + i ;
	}//end for
	return sum ;
}//end SumLoop

long SumRecur( int y ) {
	int sum = 0 ;
	if ( y > 0){
		return y + SumRecur( y - 1 ) ;
	}//end if
	return 0 ;
}//end SumRecur