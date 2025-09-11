#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct NO
{
  int info;
  struct NO *esq;
  struct NO *dir;
};

ArvBin *
cria_ArvBin ()
{
  ArvBin *raiz = (ArvBin *) malloc (sizeof (ArvBin));
  if (raiz != NULL)
	*raiz = NULL;
  return raiz;
}

void
libera_NO (struct NO *no)
{
  if (no == NULL)
	return;
  libera_NO (no->esq);
  libera_NO (no->dir);
  free (no);
  no = NULL;
}

void
libera_ArvBin (ArvBin * raiz)
{
  if (raiz == NULL)
	return;
  libera_NO (*raiz);
  free (raiz);
}

int
insere_ArvBin (ArvBin * raiz, int valor)
{
  if (raiz == NULL)
	return 0;
  struct NO *novo;
  novo = (struct NO *) malloc (sizeof (struct NO));
  if (novo == NULL)
	return 0;
  novo->info = valor;
  novo->dir = NULL;
  novo->esq = NULL;

  if (*raiz == NULL)
	*raiz = novo;
  else
	{
	  struct NO *atual = *raiz;
	  struct NO *ant = NULL;
	  while (atual != NULL)
		{
		  ant = atual;
		  if (valor == atual->info)
			{
			  free (novo);
			  return 0;
			}

		  if (valor > atual->info)
			atual = atual->dir;
		  else
			atual = atual->esq;
		}
	  if (valor > ant->info)
		ant->dir = novo;
	  else
		ant->esq = novo;
	}
  return 1;
}

int
altura_ArvBin (ArvBin * raiz)
{
  if (raiz == NULL || *raiz == NULL)
	return 0;

  int alt_esq = altura_ArvBin (&((*raiz)->esq));
  int alt_dir = altura_ArvBin (&((*raiz)->dir));
  if (alt_esq > alt_dir)
	return (alt_esq + 1);
  else
	return (alt_dir + 1);
}

int
totalNO_ArvBin (ArvBin * raiz)
{
  if (*raiz == NULL)
	return 0;

  int count_left = totalNO_ArvBin (&((*raiz)->esq));

  int count_right = totalNO_ArvBin (&((*raiz)->dir));

  return count_left + count_right + 1;
}
