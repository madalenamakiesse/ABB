#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"
//Estrutura ABB
typedef struct Abb{
	int chave;
	struct Abb *dir, *esq;
}abb;
//Criar n�
abb *criarno(int chave){
	abb *A=(abb*)malloc(sizeof(abb));
	A->chave=chave;
	A->dir=NULL;
	A->esq=NULL;
	return A;
}
//Fun��o que insere chave na ABB
abb *insere(int chave, abb *a){
	//Se o n� for igual a NULL quer dizer que n�o tem filhos(dir ou esq) e o lugar est� vago para a chave ,os ponteiros(dir e esq)->NULL
	if(a==NULL){
		//Retorna a �rvore com a chave acrescentada
		a=criarno(chave);
	}
	else{
		//Caso seja um pai , avaliarmos se a chave � maior/menor que ele para correctemente posicionarmos na �rvore
		//Menor a esquerda e maior a direita
		if(a->chave > chave) a->esq=insere(chave,a->esq);
		else if(a->chave < chave) a->dir= insere(chave,a->dir);		
	}
		return a;
}
//Fun��o libera ABB
void libera(abb *a){
	if(!a) return;
	libera(a->esq);
	libera(a->dir);
	free(a);
}
//Fun��o recursiva que conta os n�s existentes de uma ABB
int contaNos(abb *a, int nivel){
	if(a == NULL) return 0;
	if(nivel==0) return 1;
	return  contaNos(a->dir,(nivel-1)) + contaNos(a->esq,(nivel-1));
}
//Fun��o que retorna o ponteiro do maior elemento do ABB
abb *abbMax(abb *a){
	while(a->dir != NULL) a=a->dir;		
	return a;
}
//Fun��o que procura e retorna o ponteiro da chave na �rvore
abb *procura(int chave, abb *a){
	abb *ptr=a;
	if((!ptr) || ptr->chave==chave ) return ptr;
	if(ptr->chave > chave) procura(chave,ptr->esq);
	else procura(chave,ptr->dir);
}
//Fun��o que retorna o ponteiro antecessor da chave
abb *antecessor(int chave, abb *a){
	//Procurar a chave na �rvore
	abb *ptr1=NULL;abb *ant;
	abb *ptr=procura(chave,a);
	//Retorna o ponteiro de maior valor menor que chave se a chave tem filhos a esquerda
	if(ptr->esq!=NULL){
		return abbMax(ptr->esq);
	}
	else{
		while(a!=NULL){
			if(a->chave > chave){
				a=a->esq;
			}
			else if(a->chave < chave){
				ant=a;
				a=a->dir;
			}
			else break;
		}return ant;	
	}
}
