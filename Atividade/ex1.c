#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct lista{
	int info;
	struct lista *prox;
}Lista;

typedef struct pilha{
	Lista* topo;
}Pilha;

void inseretopo(Pilha* P, int valor){
	
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	
	novo->info = valor;
	novo->prox = NULL;
	
	if(P->topo == NULL){
		P->topo = novo;
		novo->prox = NULL;
	} else {
	novo->prox = P->topo;
	P->topo = novo;
	}
	
}

void imprime(Pilha* P){
	Lista* aux = P->topo;
	
	while(aux->prox != NULL){
		printf("%i\t", aux->info);
		aux=aux->prox;
	}
	printf("\n");
}

void removetopo(Pilha* P){
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

void transBin(Pilha* P, int valor){
	Lista* aux = P->topo;
	
	while(valor != 0){
		
		if(valor % 2 == 0)
			inseretopo(P, 0);
		else
			inseretopo(P, 1);
		
		valor = round (valor/2);
	}
	
}

int main(int argc,char const* argv[]){

	Pilha* P = (Pilha*)malloc(sizeof(Pilha));
	P->topo = NULL;
	int x;
	
	printf("Insira um  valor a ser transformado em binario:\n");
	scanf("%i", &x);
	setbuf(stdin, NULL);
	
	transBin(P, x);
	imprime(P);

	return 0;
}