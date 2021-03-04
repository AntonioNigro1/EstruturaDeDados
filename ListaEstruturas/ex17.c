#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

void imprime(Lista* L){
	Lista* aux = L;
	
	while(aux->prox != NULL){
		printf("%i\t", aux->info);
		aux=aux->prox;
	}
	printf("\n");
}

Lista* insereIni(Lista* L, int valor){

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info  = valor;
	novo->prox = L;
	

return novo;
}

Lista* trocaEle(Lista* L, int m, int n){

	if(m>n){
		int temp;
		temp = m;
		m = n;
		n = temp;
	}
	
	Lista* aux = L;
	Lista* ant = NULL;
	
	while(aux->info != m ){
		ant = aux;
		aux=aux->prox;
	}
	Lista* aux2 = L;	
	Lista* ant2 = NULL;
	
	while(aux2->info != n){
		ant2 = aux2;
		aux2=aux2->prox;
	}
	
	
	if(ant != NULL && aux->prox != NULL && ant2 != NULL && aux2->prox != NULL){ // os dois estão no meio
		printf("AAAA\n");
		ant->prox = aux->prox;
		ant2->prox = aux2->prox;
	
		aux->prox = ant2->prox;
		ant2->prox = aux;
	
		aux2->prox = ant->prox;
		ant->prox = aux2;
		
		return L;
	}else if(ant == NULL && aux->prox != NULL && ant2!= NULL && aux2->prox == NULL){ // primeiro e ultimo
		
		printf("BBBBB\n");
		aux2->prox =aux->prox;
		ant2->prox = aux;
		aux->prox = NULL;
		
		return aux2;
	}else if(ant == NULL && aux->prox != NULL && ant2!= NULL && aux2->prox != NULL){//primeiro e no meio
	printf("CCCC\n");
		ant2->prox = aux;
		aux->prox = aux2->prox;
		aux2->prox = L;		
		return aux2;
	}else if(ant != NULL && aux->prox != NULL && ant2!= NULL && aux2->prox == NULL){//meio e ultimo
	printf("DDDD\n");
		ant->prox = aux2;
		aux2->prox =aux->prox;;
		ant2->prox =aux;
		aux->prox = NULL;
		
		return L;
	}
	
	
}


int main(int argc, char const* argv[]){
	
	Lista* L = (Lista*)malloc(sizeof(Lista));
	L->prox = NULL;

	L=insereIni(L,70);
	L=insereIni(L,60);
	L=insereIni(L,50);
	L=insereIni(L,40);
	L=insereIni(L,30);
	L=insereIni(L,20);
	L=insereIni(L,10);
	
	imprime(L);
	
	L = trocaEle(L, 10, 70);
	
	imprime(L);

	return 0;
}