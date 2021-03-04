#include <stdlib.h>
#include <stdio.h>


typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

typedef struct listaD{
	int info;
	struct listaD* prox;
	struct listaD* ant;
}ListaD;

Lista* insereIni(Lista* L1, int valor){
	
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	
	novo->info = valor;
	novo->prox = L1;
	
	
	return novo;
}

ListaD* insereLD(ListaD*  L1, int valor){
	
	ListaD* novo = (ListaD*)malloc(sizeof(ListaD));
	
	novo->info = valor;
	novo->prox = L1;
	novo->ant = NULL;
	
	if(L1 != NULL)
	L1->ant= novo;
	
	return novo;
}

ListaD* transLista(Lista* L1){
	
	Lista* aux = L1;
	ListaD* LD = NULL;
	
	while(aux != NULL){
		if(aux->info % 2 == 0)
		LD = insereLD(LD, aux->info);
	
		aux=aux->prox;
	}
	
	
	return LD;
}

void imprime(ListaD* LD){
	ListaD* aux = LD;
	
	while(aux != NULL){
		printf("%i\t", aux->info);
		aux=aux->prox;
	}
	printf("\n");
}

void imprimeL(Lista* L1){
	Lista* aux = L1;
	
	while(aux != NULL){
		printf("%i\t", aux->info);
		aux=aux->prox;
	}
	printf("\n");
}


int main(int argc, char const* argv[]){
	
	Lista* L1 = NULL;
	ListaD* LD = NULL;
	
	L1 = insereIni(L1, 20);
	L1 = insereIni(L1, 33);
	L1 = insereIni(L1, 40);
	L1 = insereIni(L1, 53);
	
	imprimeL(L1);
	
	LD = transLista(L1);
	
	imprime(LD);
	
	return 0;
}