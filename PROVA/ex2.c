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

void imprime(Fila* F){
	
	Lista* aux = F->ini;
	
	while(aux != NULL){
		printf("%i\t", aux->info);
		aux=aux->prox;
	}
	printf("\n");
}

void imprimeL(Lista* L){
	
	Lista* aux = L;
	
	while(aux!= NULL){
		printf("%i\t", aux->info);
		aux=aux->prox;
	}
	printf("\n");
}


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


Lista* insereFimL(Lista* Ref, int valor){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = valor;

	if(Ref == NULL){
	novo->prox = Ref;
	return novo;
	} 

	Lista* aux = Ref;
	
	while(aux->prox!=NULL)
	aux=aux->prox;

	novo->prox=NULL; 
	aux->prox=novo;
	
	return Ref;
}

Lista* insereIni(Lista* Ref, int valor){

Lista* novo = (Lista*) malloc(sizeof(Lista));
novo->info = valor;
novo->prox = Ref;

return novo;
}

void separaPares(Fila* F){
	Lista* aux= F->ini;
	Lista* newP = (Lista*)malloc(sizeof(Lista));
	Lista* newI = (Lista*)malloc(sizeof(Lista));
	newI->prox = NULL;
	newP->prox = NULL;
	
	while(aux != NULL){
		
		
		if(aux->info % 2 == 0){
			newP=insereFimL(newP,aux->info);//nova lista com pares
			aux=aux->prox;
		
		}
		else{
			newI=insereIni(newI,aux->info);//nova lista com impares 
			aux=aux->prox;
			
		}
	}
	newP=newP->prox; //arrumando começo da lista Par
	aux = newI;
	
	
	while(aux->prox->prox != NULL){
		aux=aux->prox;
	}
	aux->prox = NULL; //arrumando fim da lista Impar
	
	aux=newI;
	
	while(aux != NULL){
		newP=insereFimL(newP, aux->info); // adicionando a lista Impar no final da par
		aux=aux->prox;
	}
	
	F->ini = newP; // retornando a lista
}



int main(int argc,char const* argv[]){

	Fila* F = (Fila*)malloc(sizeof(Fila));
	F->ini = NULL;
	F->fim = NULL;

	insereFim(F,2);
	insereFim(F,3);
	insereFim(F,4);
	insereFim(F,5);
	insereFim(F,6);
	insereFim(F,7);
	insereFim(F,8);
	insereFim(F,9);
	
	imprime(F);
	
	separaPares(F);
	
	imprime(F);
	
	return 0;
}