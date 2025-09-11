/*1) Utilizando o código de listas que está disponível junto com a aula no
arquivo “ProjListaDinEncad”, faça o que se pede:
a. Crie uma nova função que consulta a lista e retorna um aluno
pela sua matricula
b. Crie uma nova função que consulta a lista e retorna um aluno
pela sua posição na lista*/

#include "matriz.h" 

int main()
{
    Aluno al[5] = {{69, "Sara"},{23, "Otavio"},{18, "Kika"},{10, "Neymar"},{89, "Rosangela"}};

    Lista *li = criarLista();

    for(int i=0;i<5;i++)
        insereLista(li, al[i]); /*faz uma insercao com o looping dos alunos com as duas matriculas*/
        
    Aluno matri = consultaAl(li,69);
    
    Aluno posi = posicaoAL(li,1);
    
    printf("%d - %s \n",matri.matricula,matri.nome);
    printf("%d - %s",posi.matricula,posi.nome);
    
    libera_lista(li);
}

/*Na funcao consultaAl eu declaro a varial ant para servir como anterior do no, no while, enquanto o proximo do no for difente de null e
o numero da matricula definida da main for diferente da matricula passada como parametro para ser encontrada, enquanto o looping
nao chega ao fim, a variavel ant e declarada igual ao no e o no avanca para o seu proximo, assim podendo varrer por completo ate encontrar
qual matricula de aluno coincide com a procurada.
Na funcao posicaoAL eu declaro uma varial poze igual a 0, depois, no while, enquanto o proximo do no for diferente de null e 
o poze for diferente da posicao passada da main, ele passa para o proximo do no e concatena um na varial poze, ate as duas se coincidirem
, assim retornando qual aluno esta em determinada posicao*/