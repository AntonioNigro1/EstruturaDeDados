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

ListaD* removeIni(ListaD* L1){
	ListaD* aux = L1;
	
	L1=L1->prox;
	L1->ant = NULL;
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

int qtdPrimos(ListaD* L1){
	ListaD* aux = L1;
	int primos;
	while(aux != NULL){
		
		if(aux->info % 2 == 0)
			aux=aux->prox;
		else if(aux->info % 3 == 0){
			aux=aux->prox;
			printf("xda\n");
		}
		else if(aux->info % 5 == 0)
			aux=aux->prox;
		
		else if(aux->info % 7 == 0)
			aux=aux->prox;
		
		else if(aux->info % 11 == 0)
			aux=aux->prox;
		
		else{
			primos++;
			aux=aux->prox;
		}
		
	}
	
	return primos;
}


int main(int argc, char const* argv[]){
	ListaD* L = NULL;
	int x=0;
	L =insereIni(L, 1);
	L =insereIni(L, 10);
	L =insereIni(L, 17);
	imprime(L);
	
	x= qtdPrimos(L);
	
	printf("%i", x);
	
	return 0;
}