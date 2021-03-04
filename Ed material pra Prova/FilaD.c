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

Lista* insereIni(Lista* L1, int valor){
	
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	
	novo->info = valor;
	novo->prox = L1;
	L1 = novo;
	
	return L1;
}

void moveIniRemove(Fila* F1, int valor){
	Lista* aux = F1->ini;
	Lista* ant;
	
	while(aux->info != valor && aux->prox != NULL){
	ant=aux;
	aux=aux->prox;
	}
	
	//valor esta no fim
	if(aux->info == valor && aux->prox == NULL){
		aux->prox = F1->ini;
		ant->prox = NULL;
		F1->ini = aux;
		F1->fim = ant;
	}
	//valor esta no meio
	if(aux->info == valor && aux->prox != NULL){
		ant->prox = aux->prox;
		aux->prox = F1->ini;
		F1->ini = aux;
	}
	
	//valor esta no começo
	if(aux->info == valor){
		F1->ini = aux->prox;
		free(aux);
	} else 
		printf("O valor nao esta na lista");
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

int removeM(Fila* F1){
	Lista* aux = F1->ini;
	int valor;
	if(F1 != NULL){
		
		F1->ini = F1->ini->prox;
		valor= aux->info;
		free(aux);
	}
	
	if(F1->ini == NULL)
		F1->fim = NULL;
	
	return valor;
}

void imprime(Lista* L1){
	
	while(L1 != NULL){
		printf("%i\t", L1->info);
		L1=L1->prox;
	}
	printf("\n");
}

void inverteFila(Fila* F1){
	Lista* aux= F1->ini;
	Lista* new = NULL;


	while(aux != NULL){
		new= insereIni(new,aux->info);
		aux=aux->prox;
		removeIni(F1);
	}
	
	while(new != NULL){
		insereFim(F1, new->info);
		new=new->prox;
	}
	

}



int main(int argc, char const* argv[]){
	
	//Inicializando a fila e ini/fim
	Fila* F = (Fila*)malloc(sizeof(Fila));
	F->ini = NULL;
	F->fim = NULL;
	
	
	insereFim(F, 40);
	insereFim(F, 30);
	insereFim(F, 20);
	insereFim(F, 10);
	insereFim(F, 1);
	
	imprime(F->ini);
	inverteFila(F);
	imprime(F->ini);
	
	
	return 0;
}