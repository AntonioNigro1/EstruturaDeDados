#include <stdlib.h>
#include <stdio.h>

typedef struct listaC{
	int info;
	struct listaC* prox;
}ListaC;

typedef struct fila{
	ListaC* ini;
	ListaC* fim;
}Fila;

void insereFila(Fila* F, int valor){
	ListaC* novo;
	novo=(ListaC*) malloc(sizeof(ListaC));
	novo->info=valor;
	novo->prox=NULL;

	if(F->fim==NULL){
		novo->prox = novo;
		F->fim=novo;
		F->ini=novo;
	}else{
		F->fim->prox = novo;
		F->fim=novo;
		novo->prox = F->ini;
	}
}

void removeFila(Fila* F){
		
	ListaC* aux; 
	aux=F->ini;
	
	if(F->ini->prox == F->ini){
		F->ini = NULL;
		F->fim = NULL;
		free(aux);
	}
	else{
	ListaC* aux2=F->ini;
		while(aux2->prox != F->ini)
			aux2=aux2->prox;
				
		if(F->ini!=NULL){
			F->ini = aux->prox;
		
			if(F->ini==NULL)
				F->fim = NULL;
			else{
				aux2->prox = aux->prox;
			}
		
			free(aux); 
		} 
	}
}

void imprime(Fila *F){

	if(F->ini == NULL)
		printf("Lista vazia");
	else{
		
		ListaC* aux=F->ini;	
		do{
		printf("%i\t", aux->info);
		aux=aux->prox;
		}while(aux != F->ini);
	
		printf("\n");
	}
}

int main(int argc, char const* argv[]){
	
	Fila* F = (Fila*)malloc(sizeof(Fila));
	F->ini = NULL;
	F->fim = NULL;

	insereFila(F, 10);
//	insereFila(F, 20);
//	insereFila(F, 30);
	
	imprime(F);
	
	removeFila(F);

	imprime(F);
	
	return 0;
}