/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    
int y, *p, x;
y = 0; //p e igual a 0
p = &y; //p igual ao endereço de memoria de y, p aponta para y
x = *p; //x igualando ao p, que esta apontando para y, ambos igual a 0
x = 4; //x troca o valor e agora e igual a 4, excluindo o valor anterior
(*p)++; //incremente um ao y, fazendo ele virar 1, onde o ponteiro de p esta apontando
x--; //x agora e 3
(*p) += x; //o ponteiro de p esta apontando para y que o valor e 1, somando ao x onde o valor e 3, o resultado sera 4
printf ("y = %d\n", y);
return(0);
} 
