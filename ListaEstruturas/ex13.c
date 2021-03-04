#include <stdlib.h>
#include <stdio.h>

typedef struct ListaC{
	int info;
	struct ListaC* prox;
}ListaC;

typedef struct pilha{
	ListaC* topo;
}Pilha;

void imprime(Pilha* P){
	
	if(P->topo == NULL)
		printf("\nPilha vazia");
	else{
	ListaC* aux = P->topo;	
		do{
			printf("%i\t", aux->info);
			aux=aux->prox;
		}while(aux != P->topo);

		printf("\n");
	}
}

void push(Pilha* P, int valor){
	
	ListaC* novo = (ListaC*)malloc(sizeof(ListaC));
	novo->info = valor;
	
	if(P->topo == NULL){
	novo->prox = novo;
	P->topo = novo;
	} else {
		novo->prox = P->topo;
		ListaC* aux = P->topo;
		
		while(aux->prox != P->topo)
			aux = aux->prox;
		
		P->topo = novo;
		aux->prox = novo;
	}

}

void pop(Pilha* P){
	ListaC* aux = P->topo;
	
	if(P->topo == NULL){
		printf("Pilha vazia\n");
		
	}else if(P->topo->prox == P->topo){
		P->topo = NULL;
		free(aux);
	}else{
		ListaC* aux2 = P->topo;
		while(aux2->prox != P->topo)
			aux2 = aux2->prox;
			
		P->topo = P->topo->prox;
		aux2->prox = P->topo;
		
		free(aux);
	}
}

int main(int argc, char const* argv[]){
	
	Pilha* P = (Pilha*)malloc(sizeof(Pilha));
	P->topo = NULL;
	
	push(P, 10);
	push(P, 20);
	push(P, 30);
	
	imprime(P);
	
	pop(P);
	pop(P);
	pop(P);
	
	imprime(P);
	
	return 0;
}