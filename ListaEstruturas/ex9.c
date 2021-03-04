#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

typedef struct fila{
	Lista* ini;
	Lista* fim;
}Fila;

void insereFim(Fila* F1, int valor){
	
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	
	novo->info = valor;
	novo->prox = NULL;
	
	if(F1->ini != NULL){
		F1->fim->prox = novo;
		F1->fim = novo;
	}else{
		F1->fim = novo;
		F1->ini = novo;
	}
}

void removeIni(Fila* F1){
	Lista* aux = F1->ini;
	if(F1 != NULL){
		
		F1->ini = F1->ini->prox;
		free(aux);
	}
	
	if(F1->ini == NULL)
		F1->fim = NULL;
	
}

void imprime(Fila* F1){
	Lista* aux = F1->ini;
	while(aux != NULL){
		printf("%i\t", aux->info);
		aux=aux->prox;
	}
	printf("\n");
}

void filaIguais(Fila* F1, Fila* F2){
	
	Lista* aux = F1->ini;
	Lista* aux2 = F2->ini;
	int n=0;
	
	while(aux != NULL){	
		if(aux->info != aux2->info)
		n=1;
	
		if(aux->prox == NULL && aux2->prox != NULL)
		n=1;
	
		if(aux->prox != NULL && aux2->prox == NULL)
		n=1;
	
	aux=aux->prox;
	aux2=aux2->prox;
	}
	
	if(n==0)
		printf("As filas sao iguais\n");
	else
		printf("As filas sao diferentes\n");
	
}


int main(int argc, char const* argv[]){
	
	Fila* F1 = (Fila*)malloc(sizeof(Fila));
	F1->ini = NULL;
	F1->fim = NULL;
	
	Fila* F2 = (Fila*)malloc(sizeof(Fila));
	F2->ini = NULL;
	F2->fim = NULL;

	insereFim(F1, 30);
	insereFim(F1, 20);
	insereFim(F1, 10);
	imprime(F1);
	
	insereFim(F2, 30);
	insereFim(F2, 20);
	insereFim(F2, 10);
	insereFim(F2, 1121);
	imprime(F2);
	
	filaIguais(F1, F2);
	
	return 0;
}