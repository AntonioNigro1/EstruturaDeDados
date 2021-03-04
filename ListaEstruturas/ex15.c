#include <stdlib.h>
#include <stdio.h>

typedef struct listaD{
	int info;
	struct listaD* prox;
	struct listaD* ant;
}ListaD;

typedef struct listaC{
	int info;
	struct listaC* prox;
}ListaC;

typedef struct fila{
	ListaC* ini;
	ListaC* fim;
}Fila;

void imprimeF(Fila* F1){
	ListaC* aux = F1->ini;
	while(aux !=  F1->fim){
		printf("%i\t", aux->info);
		aux=aux->prox;
	}
	printf("%i\n", aux->info);
}

void imprimeL(ListaD* L1){
	ListaD* aux;
	aux= L1;
	
	while(aux->prox != NULL){
		printf("%i\t",aux->info);
		aux=aux->prox;
		
	};
		printf("\n");
}

void insereFim(Fila* F1, int valor){
	
	ListaC* novo = (ListaC*)malloc(sizeof(ListaC));
	
	novo->info = valor;
	novo->prox = F1->ini;
	
	if(F1->ini != NULL){
	
		F1->fim->prox = novo;
		F1->fim = novo;
	}else{
	
		novo->prox = novo;
		F1->fim = novo;
		F1->ini = novo;
	}
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

ListaD* removeLista(ListaD *L, int info){
    ListaD *aux=L;
    
    while(aux!=NULL && aux->info!=info)           
        aux=aux->prox;
    
    if(aux==NULL)
       return L;
       
   
    if(aux->ant==NULL)
    {
        L=aux->prox;
        if(L!=NULL)
            L->ant=NULL;
        free(aux);
    }
    else
       
        if(aux->prox==NULL)
        {
            aux->ant->prox=NULL;
            free(aux);
        }

        else
        {
            aux->ant->prox=aux->prox;
            aux->prox->ant=aux->ant;
            free(aux);
        }
    return L;
}

ListaD* removeIm(ListaD* L, Fila* F){
	
	ListaD* aux = L;
	
	while(aux->prox != NULL){
		if(aux->info %2 != 0){
			insereFim(F, aux->info);
			aux=aux->prox;
			L = removeLista(L, aux->ant->info);
		}else{
			aux=aux->prox;
		}
		
	}
	
	return L;
}

int main(int argc,char const* argv[]){
	ListaD* L = (ListaD*)malloc(sizeof(ListaD));
	L->ant = NULL;
	L->prox = NULL;
	
	Fila* F= (Fila*)malloc(sizeof(Fila));
	F->ini = NULL;
	F->fim = NULL;
	
	L = insereIni(L, 10);
	L = insereIni(L, 13);
	L = insereIni(L, 16);
	L = insereIni(L, 17);
	L = insereIni(L, 20);
	L = insereIni(L, 21);
	
	imprimeL(L);
	
	L = removeIm(L, F);
	
	imprimeL(L);
	imprimeF(F);
	
	return 0;
}