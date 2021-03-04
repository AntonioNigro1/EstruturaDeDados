#include <stdlib.h>
#include <stdio.h>

typedef struct listaD{
	int info;
	struct listaD* prox;
	struct listaD* ant;
}ListaD;

ListaD* insereIni(ListaD* L1, int valor){
	
	ListaD* novo = (ListaD*)malloc(sizeof(ListaD));
	
	novo->info = valor;
	novo->ant = NULL;
	novo->prox = L1;
	
	
	if(L1 != NULL)
	L1->ant= novo;
	
	
	return novo;
}

ListaD* insereFim(ListaD* L1, int valor){
	ListaD* aux = L1;
	ListaD* novo = (ListaD*)malloc(sizeof(ListaD));
	
	novo->info = valor;
	novo->prox = NULL;
	novo->ant = NULL;
	
	if(L1== NULL)
		return novo;
	else{
	while(aux->prox != NULL){
		aux=aux->prox;
	}
	aux->prox = novo;
	novo->ant = aux;
	
	return L1;
	}
}

ListaD* removeIni(ListaD* L1){
	ListaD* aux = L1;
	
	L1=L1->prox;
	L1->ant = NULL;
	free(aux);
	
	return L1;
}

ListaD* removeFim(ListaD* L1){
	ListaD* aux = L1;
	
	while(aux->prox != NULL){
		aux=aux->prox;
	}
	
	aux->ant->prox = NULL;
	free(aux);
	
	return L1;
}

void imprime(ListaD* L1){
	
	while(L1 != NULL){
		printf("%i\t", L1->info);
		L1=L1->prox;
	}
	printf("\n");
}

int main(int argc, char const* argv[]){
	
	ListaD* L = NULL;
	
	L = insereFim(L, 10);
	L = insereIni(L, 20);
	L = removeFim(L);
	imprime(L);
	
	return 0;
}