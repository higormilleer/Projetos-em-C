/*Escreva um programa em linguagem C que imprimam na tela a string s na
ordem inversa utilizando ponteiros.
char s[10] = "abcde";
char* cptr;
// Seu código começa aqui*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[10] = "abcde";
    char* cptr=s; //igualando o endereço de s com o ponteiro cptr
    
    while(*cptr!='\0'){  //enquanto o cptr que esta sendo apontado para o s, for diferente de \0 (ultimo caractere), cptr sera incrementado em 1
        cptr++;
    }
    
    while(cptr>=s){
        printf("%c",*cptr);  //enquanto o cptr for mais ou igual que s, printa o valor de um caractere (o ultimo) e decrementa o valor de cptr em 1
        cptr--;
    }
    
    return 0;
}

/*Utilizamos char s tendo o tamanho de 10 vetores e igualando eles a "abcde", depois apontamos o cptr para s. No primeiro while, enquanto o conteudo armazenado em 
cptr for diferente do ulitmo caractere(onde esta como \0), ele e incrementado em 1, assim, no laço, adquirindo o valor de caracteres que ha em s. No segundo while,
enquanto o cptr for maior ou igual ao s, e printado o conteudo de cptr, que no primeiro esta armazenando o ultimo caractere, e apos printar e decrementado em 1,
assim, imprimindo os caracteres invertidos localizados anteriormente em s*/
