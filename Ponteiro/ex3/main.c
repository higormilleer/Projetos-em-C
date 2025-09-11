/*Verifique o programa abaixo. Encontre o seu erro e corrija-o para que
escreva o número 10 na tela.)*/

#include <stdio.h>
int main() {
 int x, *p, **q;
 p = &x;
 q = &p;
 x = 10;
 printf("\n%d\n", **q);
 return(0);
}

//o print estava errado, pois estava tentando printar o endeço do q, e nao o conteudo que estava armazenado, ja com o **q, o conteudo e impresso
