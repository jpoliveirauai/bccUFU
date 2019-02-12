// Programa - testa operadores
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

// declaração de variaveis globais, macros e protótipos


int main(int argc, char *argv[]){
     // declaração de variáveis locais e comandos
     int a, b, c, d;
      
     a = 0xd3; // = 11010011
     b = 0xf5; // = 11110101
     c = 0x1e; // = 00011110
      
     d = a | b; // 11010011 | 11110101 = 11110111 -> 0xf7
     d = b & c; // 11110101 & 00011110 = 00010100 -> 0x14
     d = a ^ c; // 11010011 ^ 00011110 = 11001101 -> 0xcd
     d = ~c;    // ~00011110 = 11100001 -> 0xe1
     d = c << 3; // 00011110 << 3 = 11110000 -> 0xf0
     d = a >> 4; // 11010011 >> 4 = 00001101 -> 0x0d

     return 0;
}
