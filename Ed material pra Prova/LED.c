#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
	int info;
	struct lista* prox;
	struct lista* ant;
}ListaD;



void imprime(ListaD* L1){
	ListaD* aux;
	aux= L1;
	do{
		printf("%d\t",aux->info);
		aux=aux->prox;
		
	}while(aux != NULL);

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

ListaD* insereFim(ListaD* L1, int valor){
	ListaD* aux = L1;
	ListaD* novo = (ListaD*)malloc(sizeof(ListaD));
	novo->ant= NULL;
	novo->prox=NULL;
	novo->info = valor;
	
	if(L1==NULL){
		novo->prox= L1;
		return novo;
	}
	
	while(aux->prox != NULL){
		aux=aux->prox;
	}
	novo->ant=aux;
	aux->prox= novo;
	
	return L1;
}

ListaD* inDados(ListaD* L1){
	int x, valor;
	printf("\nDigite o valor que deseja inserir na lista: ");
	scanf("%i", &valor);
	setbuf(stdin, NULL);
	
	printf("\nDigite 1 para inserir no comeco da lista, 2 para inserir no final: ");
	scanf("%i", &x);
	setbuf(stdin, NULL);
	
	if(x==1){
		L1 = insereIni(L1, valor);
		return L1;
	}
	
	if(x==2){
		L1 = insereFim(L1, valor);
		return L1;
	} else {
		printf("\nOperacao invalida");
		return L1;
	}
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
ListaD* moveMaiorFim(ListaD* L1){
	ListaD* aux= L1;
	ListaD* maior;
	int valor=0;
	
	if(aux == NULL)
		return NULL;
	
	if(aux->prox= NULL)
		return L1;


	while(aux!=NULL){
		
		if(valor < aux->info){
			valor = aux->info;
			maior=aux;
			maior->ant=aux->ant;
		}
		aux=aux->prox;
	}
	
	
	if(maior->ant == NULL){
		
		return L1;
	} else if(maior->prox==NULL){
		maior->ant->prox=NULL;
		maior->prox=L1;
		L1->ant=maior;
		maior->ant = NULL;
		return maior;
		
	} else {
		maior->ant->prox = maior->prox;
		maior->prox->ant = maior->ant;
		maior->prox= L1;
		L1->ant=maior;
		maior->ant=NULL;
		return maior;
	}
}

ListaD* separaLista(ListaD* L1, int valor){
	
	ListaD* aux = L1;
	ListaD* L2 = NULL;
	
	while(L1->info != valor){
		aux=aux->prox;
	}
	aux->ant->prox = NULL;
	
	while(aux != NULL){
		L2=insereFim(L2, aux->info);
		aux=aux->prox;
	}
	
	return L2;
}

int main(int argc, char const * argv[]){
	ListaD* L = NULL;
	ListaD* L2 = NULL;
	L=insereIni(L, 50);
	L=insereIni(L, 40);
	L=insereIni(L, 20);
	L=insereIni(L, 10);
	L=insereFim(L, 70);
	//L=removeLista(L, 23);
	//imprime(L);
	L2=separaLista(L, 20);
	//L=moveMaiorFim(L);
	imprime(L);
	imprime(L2);
	
	return 0;
}