#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

typedef struct pilha{
	Lista* topo;
}Pilha;

void imprime(Pilha* P){
	Lista* aux = P->topo;
	
	while(aux != NULL){
		printf("%i\t", aux->info);
		aux=aux->prox;
	}
	printf("\n");
}

void push(Pilha* P, int valor){
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = P->topo;
	P->topo = novo;
}

void pop(Pilha* P){
	Lista* aux = P->topo;
	
	if(P->topo == NULL){
		printf("Pilha vazia\n");
	}else if(P->topo->prox == NULL){
		P->topo = NULL;
		free(aux);
	}else{
		P->topo = P->topo->prox;
		free(aux);
	}
}

Lista* insereIni(Lista* Ref, int valor){

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info  = valor;
	novo->prox = Ref;

return novo;
}

Lista* inverte(Lista* L1){
	
	Lista* aux = L1;
	Lista* new = (Lista*)malloc(sizeof(Lista));
	new = NULL;
	while(aux != NULL){
		new=insereIni(new,aux->info);
		aux=aux->prox;
	}
	
	return new;
}

int main(int argc, char const* argv[]){
	
	Pilha* P = (Pilha*)malloc(sizeof(Pilha));
	P->topo = NULL;
	
	push(P,50);
	push(P,40);
	push(P,30);
	push(P,20);
	push(P,10);
	
	imprime(P);
	
	P->topo = inverte(P->topo);
	
	imprime(P);
	
	return 0;
}