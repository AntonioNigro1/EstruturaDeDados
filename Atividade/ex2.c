#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

Lista* insereIni(Lista* L1, int valor){

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = L1;

return novo;
}

void imprimeL(Lista* L1){
	Lista* aux = L1;
	
	while(aux->prox != NULL){
		printf("%i\t", aux->info);
		aux=aux->prox;
	}
	printf("\n");
}

Lista* removeLista(Lista* L, int valor){

	Lista* aux=NULL;
	Lista* ant=NULL; 
	
	aux = L;
	if(aux==NULL)
		return NULL;

	while(aux!=NULL && aux->info!=valor){
		ant=aux;
		aux=aux->prox; 
	}

	if(aux==NULL)
	return L;


	if(ant==NULL){
		L=aux->prox;
		free(aux);
		return L; 
	}else{
	ant->prox=aux->prox;
	free(aux); 
	
	return L; 
	}
}


Lista* dif(Lista* L, Lista* M){
	
	Lista* aux1 = L;
	Lista* aux2 = M;
	int n = 1;
	
	while(n != 0){
	
		if(aux1->info == aux2->info){           //testa se os elementos sao iguais, remove caso sejam, passa L pra frente e reseta M pra começar a comparar dnv
			aux1= removeLista(aux1, aux2->info);
			aux1=aux1->prox;
			aux2=M;
		}
		else if(aux2->prox != NULL){  //testa todos os elementos de M em L
			aux2=aux2->prox;
		
		}else if(aux1->prox != NULL && aux2->prox == NULL){ // testamos todos de M em L e L nao chegou ao final, reseta M e passa L pra frente
			aux2 = M;
			aux1=aux1->prox;
		}
		
		else if(aux1->prox == NULL && aux2->prox == NULL) // os dois chegaram ao final, sai do laço
			n=0;
	}
	return L;
}

int main(int argc,char const* argv[]){
	
	Lista* L1 = (Lista*)malloc(sizeof(Lista));
	Lista* L2 = (Lista*)malloc(sizeof(Lista));
	L1->prox = NULL;
	L2->prox = NULL;
	
	L1 = insereIni(L1, 40);
	L1 = insereIni(L1, 30);
	L1 = insereIni(L1, 20);
	L1 = insereIni(L1, 10);
	
	L2 = insereIni(L2, 20);
	L2 = insereIni(L2, 30);
	
	//L1 = removeLista(L1, 30);
	
	//imprimeL(L1);
	//imprimeL(L2);

	L1 = dif(L1, L2);
	
	imprimeL(L1);

	return 0;
}