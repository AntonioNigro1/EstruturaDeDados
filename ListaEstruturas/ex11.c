#include <stdlib.h>
#include <stdio.h>

typedef struct listaD{
	int info;
	struct listaD* ant;
	struct listaD* prox;
}ListaD;

void imprime(ListaD* L1){
	ListaD* aux = L1;
	do{
		printf("%d\t",aux->info);
		aux=aux->prox;
		
	}while(aux->prox != NULL);

	printf("\n");
}

ListaD* insereIni(ListaD* L1, int valor){
	ListaD* novo = (ListaD*)malloc(sizeof(ListaD));

	novo->info = valor;
	novo->ant=NULL;
	novo->prox= L1;	
	
	if(L1 != NULL)
	L1->ant= novo;
	
	return novo;
}

ListaD* insereMeio(ListaD* L1, int valor){
	
	ListaD* aux = L1;
	ListaD* novo = (ListaD*)malloc(sizeof(ListaD));
	
	novo->ant = NULL;
	novo->prox = NULL;
	novo->info = valor;
	
	novo->ant = aux;
	novo->prox = aux->prox;
	aux->prox->ant = novo;
	aux->prox = novo;	
}

ListaD* removeLista(ListaD* L1, int valor){
	ListaD* aux = L1;
	if(L1==NULL)
		return NULL;
	
	while(aux->info != valor && aux != NULL){
		aux->ant= aux;
		aux=aux->prox;
	}
	
	if(aux == NULL)
		return L1;
	
	if(aux->ant= NULL){
		L1=aux->prox;
		free(aux);
		return L1;
	} else {
		aux->prox->ant=aux->ant;
		aux->ant->prox= aux->prox;
		free(aux);
		return L1;
	}
}

ListaD* insereOrd(ListaD* L1, int valor){
	
	ListaD* aux = L1;
	int n = 0;
	while(aux->prox != NULL){
		if(aux->info >= aux->prox->info){
			printf("A lista nao esta em ordem crescente\n");
		n=1;
		}
	aux=aux->prox;
	}
	
	if(n == 0){
		aux = L1;
		
		while(n == 0){
			if(aux->info < valor && aux->prox->info > valor){
				insereMeio(aux, valor);
				n=1;
			}
		aux=aux->prox;
		}
	}

	return L1;
}

int main(int argc, char const* argv[]){

	ListaD* L1 = (ListaD*)malloc(sizeof(ListaD));
	L1->prox = NULL;
	L1->ant = NULL;
	
	L1 = insereIni(L1, 40);
	L1 = insereIni(L1, 30);
	L1 = insereIni(L1, 20);
	L1 = insereIni(L1, 10);
	
	imprime(L1);
	
	L1 = insereOrd(L1, 25);
	
	imprime(L1);

	return 0;
}