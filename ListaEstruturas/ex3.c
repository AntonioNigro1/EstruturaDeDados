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

int verifCres(ListaD* L1){
	ListaD* aux = L1;
	
	while(aux->prox->prox != NULL){
		if(aux->info > aux->prox->info)
			return 1;
		
	aux=aux->prox;
	}
	
	return 0;
	
}


int main(int argc, char const* argv[]){
	
	ListaD* L1 = NULL;
	
	L1 = insereIni(L1, 40);
	L1 = insereIni(L1, 30);
	L1 = insereIni(L1, 20);
	L1 = insereIni(L1, 10);
	
	int x = verifCres(L1);
	if(x==0)
		printf("A lista esta em ordem crescente");
	else
		printf("A lista nao esta em ordem crescente");
	


	return 0;
}