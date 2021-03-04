#include<stdlib.h>
#include<stdio.h>

typedef struct lista{
	int info;
	struct lista* prox; //Auto referencia, pelo nome de cima + struct//
}Lista;

Lista * insereInic(Lista *Lb, int elem){
	Lista *L=(Lista*)malloc(sizeof(Lista)); //<- ponteiro auxiliar que ira entrar no começo da lista//
	L->info = elem;
	L->prox = Lb; //Aponta para o começo da lista//

	return L;
}

int main(int argc, char const *argv[]){									
	Lista *L=NULL; //Ponteiro que guarda o endereço do começo da lista//
	L=(Lista*)malloc(sizeof(Lista));//Alocando um "Bloco" de tamanho/tipo Lista que é fragmentado em seguida// 
	L->info = 1; //Inserindo qualquer informação//
	L->prox= NULL;//Aponta para proximo nó, no caso não existe, logo = NULL//
	
	L->prox = (Lista*)malloc(sizeof(Lista));
	L->prox->info = 2;
	L->prox->prox = NULL;
	
	L= insereInic(L, 3);

	printf("%d", L->info);
	
	return 0;
}