/*Escreva um programa solicite ao usuário uma sequência de caracteres
sem limite de tamanho máximo e realize as seguintes operações usando
uma pilha:
a) Imprimir o texto na ordem inversa;
b) Verificar se o texto é um palíndromo, ou seja, se o texto é escrito da
mesma maneira de frente para trás e de trás para frente. Ignore espaços
e pontos.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char letra;
    struct node *proximo;
} Node, *Pilha;

Pilha* criarPilha()
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if(p!=NULL)
        *p = NULL;
        
    return p;
}
//cria umapilha vazia  

int lenghtS(char *s)
{
    int tamanho = 0;
    while((*s) != '\0'){
        tamanho++;
        s++;
    }
    return tamanho;
}
//descobrir o tamanho da string

void liberarPilha(Pilha *lista){
    if(lista==NULL)return;
    Node *no;
    while((*lista)!=NULL){
        no=*lista;
        *lista=(*lista)->proximo;
        free(no);
    }
    free(lista);
}
//liberar espaco alocada na pilha

void push(Pilha *p, int tam, char* str){
    if(p==NULL) return;
    
    for(int i=0;i<tam;i++){
        
        Node *temp = (Node*)malloc(sizeof(Node));
        if(temp==NULL) return;
        
        temp->letra=str[i];
        temp->proximo=(*p);
        *p=temp;
    }
}
//empilhar um elemento a Pilha

int Palindromo(char *str){
    
    Pilha *pilha = criarPilha();
    int tamanhoStr = lenghtS(str);
    push(pilha, tamanhoStr, str);
    
    printf("%s\n",str);
    for(int i = 0;i<tamanhoStr;i++){
        printf("%c",(*pilha)->letra);
        (*pilha)= (*pilha)->proximo;
    }
    
    int primeiraLetra = 0, ultimaLetra=tamanhoStr-1;
    
    while(primeiraLetra<ultimaLetra){
        if(str[primeiraLetra] != ' ' && str[primeiraLetra] != '.' && str[ultimaLetra] != ' ' && str[ultimaLetra] != '.'){
            if(str[primeiraLetra]!=str[ultimaLetra]){
                printf("\n");
                printf("Nao e Palindromo\n");
                liberarPilha(pilha);
                return 0;
            }
            primeiraLetra++;
            ultimaLetra--;
        } else {
            if(str[primeiraLetra] == ' ' || str[primeiraLetra] == '.'){
                primeiraLetra++;
            }
            if(str[ultimaLetra] == ' ' || str[ultimaLetra] == '.'){
                ultimaLetra--;
            }
        }
    }
    printf("\n");
    printf("E Palindromo\n");
    liberarPilha(pilha);
    return 0;
}
//e criado uma pilha, desobrimos o tamanho da string digitada e empilhamos esses elementos na pilha. E impresso a string na ordem inversa e depois descobrimos se e Palindromo ou nao

int main()
{
    char str[30];
    
    printf("Digite a string para ser analisada: ");
    scanf(" %[^\n]", str);
    Palindromo(str);
    
    return 0;
}

/*Na funcao Palindromo(), criamos uma pilha, igualamos o tamanho da string descoberto na funcao lenghtS() a uma variavel para podermos utilizar e alocamos os valores na pilha.
No primeiro laco de repeticao (for), imprimimos a string na ordem inversa, depois inicializamos a variavel primeiraLetra a primeira letra da string e a ultimaLetra a ultima letra da string,
no segundo laco (while), enquanto a primeira letra for menor que a ultimo, e utilizado um padro de tratamento para ignorar espacos e ponto no meio da palavra, e quando a primeira letra for
diferente da ultima, logo elas nao sao Palindromos, porem se se mantiverem iguais ate o meio da palavra(quando a ultima letra passar a ser menor que a primeira, o looping acaba), quer dizer
que sao palindromos*/

