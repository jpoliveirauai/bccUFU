/**************************************************************************
 *                  Programação Procedimental
 **************************************************************************
 *  Programa: tipos.c
 *
 *  Objetivo: Apresentar os Tipos Basicos de Dados e seus Modificadores
 **************************************************************************/

#include <stdio.h>


int main (void)
{
	printf( "Programa Tipos\n\n" );

	printf( "Tipos ANSI C:                Bytes\n" );
	printf( "sizeof(char) ............... %2d\n", sizeof(char) );
	printf( "sizeof(unsigned char) ...... %2d\n", sizeof(unsigned char) );
	printf( "sizeof(signed char) ........ %2d\n", sizeof(signed char) );

	printf( "sizeof(int) ................ %2d\n", sizeof(int) );
	printf( "sizeof(unsigned int)........ %2d\n", sizeof(unsigned int) );
	printf( "sizeof(signed int)...,,..... %2d\n", sizeof(signed int) );
	printf( "sizeof(short int) .......... %2d\n", sizeof(short int) );
	printf( "sizeof(unsigned short int) . %2d\n", sizeof(unsigned short int) );
	printf( "sizeof(signed short int) ... %2d\n", sizeof(signed short int) );
	printf( "sizeof(long int) ........... %2d\n", sizeof(long int) );
	printf( "sizeof(signed long int) .... %2d\n", sizeof(signed long int) );
	printf( "sizeof(unsigned long int) .. %2d\n", sizeof(unsigned long int) );


	printf( "sizeof(float) .............. %2d\n", sizeof(float) );
	printf( "sizeof(double) ............. %2d\n", sizeof(double) );
	printf( "sizeof(long double) ........ %2d\n\n", sizeof(long double) );


	return 0;
}

