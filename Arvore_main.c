#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ABB.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	abb *arvore=NULL;
	int op ,tam,i,ele,chave,nivel;
	while(op!=6){
		printf("\nBem-vindo(a) ao menu ABB!\n\tPor favor, escolha a op��o:\n\t\t1-Inserir elemento(s)\n\t\t2-Liberar �rvore\n\t\t3-Contar n�s\n\t\t4-Maior elemento\n\t\t5-Antecessor\n\t\t6-Sair\n\t\t\t");
		scanf("%d",&op);
			if(op==1){
				do{
					printf("Por favor , informe a quantidade de elementos que pretentende inserir:\t" );
					scanf("%d",&tam);
					system("cls");
				}while(tam<0);
				for(i=0;i<tam;i++){
					printf("\nS%d: ",i+1 );
					scanf("%d",&ele);
					arvore=insere(ele,arvore);
				}
				system("cls");
			} 
			if(op==2){
				libera(arvore);
				arvore=NULL;
				printf("Sucesso!");
				system("pause");
			}
			if(op==3){
				printf("Por favor , informe o n�vel:\t" );
				scanf("%d",&nivel);
				system("cls");
				if(contaNos(arvore, nivel)==0) printf("N�o existe n�s no n�vel %d.\n",nivel);
				else if(contaNos(arvore, nivel)==1) printf("Existe %d n� no n�vel %d.\n",contaNos(arvore, nivel),nivel);
				else printf("Existem %d n�s no n�vel %d.\n",contaNos(arvore, nivel),nivel);
				system("pause");
			} 
			if(op==4){
				if(abbMax(arvore)==NULL) printf("N�o existe n�s nessa �rvore.\n");
				else printf("\nO maior elemento da �rvore � %d.\n",abbMax(arvore)->chave);
				system("pause");
			}
			if(op==5){
				printf("Chave: ");
				scanf("%d",&chave);
				if(antecessor(chave, arvore)==NULL) printf("N�o existe antecessor de %d na �rvore.\n",chave);
				else printf("\nO antecessor de %d na �rvore � %d.\n",chave,antecessor(chave, arvore)->chave);
				system("pause");
			}
			system("cls");
		}	
	return 0;
}
