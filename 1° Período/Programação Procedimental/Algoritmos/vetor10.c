#include <stdio.h>

int main(){
	int v[10] = { 3, 7, 4, 1, 0, 8, 6, 9, 2, 5},i;
	printf ("Ordem direta: ");
	for (i=0;i<10;i++) printf ("%d%c ",v[i],i==9?' ':',');
	printf ("\nOrdem reversa: ");
	for (i=9;i>=0;i--) printf ("%d%c ",v[i],i==0?' ':',');
}
