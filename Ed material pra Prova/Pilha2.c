#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

typedef struct pilha{
	Lista* topo;
}Pilha;

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

void imprime(Pilha* P){
	Lista* aux = P->topo;
	
	while(aux != NULL){
		printf("%i\t", aux->info);
		aux=aux->prox;
	}
	printf("\n");
}

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

Lista* insereFim(Lista* L1, int valor){
	Lista* aux = L1;
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	

	novo->info = valor;
	novo->prox = NULL;
	
	if(aux == NULL){
		return novo;
	}else{
		while(aux->prox != NULL){
			aux=aux->prox;
		}
		aux->prox = novo;
	}
	
	return L1;
}

void removePar(Pilha* P){
	Lista* ant= NULL;
	Lista* aux = P->topo;
	
	
	while(aux != NULL){
		if(aux->info % 2 == 0){
			if(ant==NULL){
				P->topo = aux->prox;
				removetopo(P);
			}else if(aux->prox == NULL){
					aux->prox = P->topo;
					ant->prox = NULL;
					P->topo= aux;
					removetopo(P);
				}else{
				ant->prox = aux->prox;
				aux->prox = P->topo;
				P->topo = aux;
				removetopo(P);
			}
		}
		ant=aux;
		aux=aux->prox;
	}
}


void inverte(Pilha* P){
	
	Lista* aux= P->topo;
	Lista* new = NULL;
	
	while(aux != NULL){
		new = insereFim(new, aux->info);
		aux=aux->prox;
		removetopo(P);
	}
	
	
	while(new != NULL){
		inseretopo(P, new->info);
		new = new->prox;
	}
	
}


int main(int argc, char const* argv[]){

	Pilha* P = (Pilha*)malloc(sizeof(Pilha));
	P->topo = NULL;
	
	inseretopo(P, 10);
	inseretopo(P, 20);
	inseretopo(P, 30);
	imprime(P);
	//inverte(P);
	removePar(P);
	imprime(P);	
	
}