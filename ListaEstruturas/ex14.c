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

void imprimeL(Lista* L){
	Lista* aux = L;
	
	if(L==NULL)
		printf("Lista vazia");
	else{
		printf("%i\t", aux->info);
		aux=aux->prox;
		while(aux != L){
			printf("%i\t", aux->info);
			aux=aux->prox;
			
		}
	printf("\n");
	}
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

Lista* insereIni(Lista* L, int valor){
	Lista* novo =(Lista*)malloc(sizeof(Lista));
	novo->prox = NULL;
	novo->info = valor;
	
	if(L == NULL){
		novo->prox=novo;
		return novo;
		
	}else if(L->prox == L){
		novo->prox = L;
		L->prox = novo;
		return novo;
		
	}else{
		Lista* aux = L;
		while(aux->prox != L)
			aux=aux->prox;
		
		novo->prox = aux->prox;
		aux->prox = novo;
		return novo;
	}
}

Lista* removeIm(Pilha* P){
	Lista* aux = P->topo;
	Lista* new = NULL;
	
	while(aux != NULL){
		if(aux->info % 2 != 0){
			new=insereIni(new, aux->info);
			aux=aux->prox;
			pop(P);
		} else {
			aux=aux->prox;
			pop(P);
		}
	}
	
	return new;
}
int main(int argc,char const* argv[]){
	Lista* imp = (Lista*)malloc(sizeof(Lista));
	imp->prox = NULL;
	Pilha* P = (Pilha*)malloc(sizeof(Pilha));
	P->topo = NULL;
	
	push(P, 15);
	push(P, 10);
	push(P, 20);
	push(P, 23);
	push(P, 12);
	push(P, 39);
	
	imprime(P);

	imp = removeIm(P);
	
	imprimeL(imp);
	
	return 0;
}