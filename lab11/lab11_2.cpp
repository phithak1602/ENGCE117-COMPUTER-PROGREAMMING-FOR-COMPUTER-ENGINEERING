#include <stdio.h>
#include <math.h>

void mergesort( int t[], int k ) ;
void merge( int *u, int m, int *v, int n, int *t ) ;

int main() {
    int data[ 7 ] = { 4, 6, 1, 2, 5, 1, 8 } ;
    int n = 7 ;
    mergesort( data, n ) ;
    for( int i = 0 ; i < n ; i++ ) printf( "%d ", data[ i ] ) ;
    return 0 ;
}//end function main

void mergesort( int t[], int k ) {
	int *u = new int( k ) , *v = new int( k ) ;
	double holdit = k ;
	int carry1 = floor(holdit/2) ;
	int nu = 0, nv = 0 ;
	if ( k > 1 ){
		for (int i = 0 ; i < floor(holdit/2) ; i++ ){
			u[i] = t[ i ] ;
			nu++;
		}//end for
		for (int j = 0 ; j < ceil(holdit/2) ; j++ ){
			v[j] = t[ carry1 + j  ] ;
			nv++;
		}//end for
		mergesort( u, nu) ;
		mergesort( v, nv) ;
		merge( u, nu , v, nv, t ) ;
	}//end if
}//end function mergesort

void merge( int *u, int m, int *v, int n, int *t ) {
	int i = 0, j = 0 ;
	for ( int k = 0 ; k < m+n ; k++ ){
		if ( i >= m){
			t[k] = v[j] ;
			j++ ;
		}//end if
		else if ( j >= n ) {
			t[k] = u[i] ;
			i++ ;
		}//end else if
		else if ( u[i] < v[j] ){
			t[k] = u[i] ;
			i++ ;
		}//end else if
		else{
			t[k] = v[j] ;
			j = j + 1 ;
		}//end else
	}//end for
}//end function mergesort