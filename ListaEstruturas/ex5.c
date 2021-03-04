#include <stdlib.h>
#include <stdio.h>

typedef struct listaC{
	int info;
	struct listaC* prox;
	struct listaC* ant;
}ListaC;

void imprime(ListaC* L1){
	ListaC* aux = L1;
	
	if(aux == NULL)
		printf("Lista circular vazia\n");
	else if(aux->prox != aux){
	
		int priVal = aux->info;
	
		printf("%i\t", aux->info);
		aux=aux->prox;
		while(aux->info != priVal){
			printf("%i\t", aux->info);
			aux=aux->prox;
		
		}
		printf("\n");
	} else{
		printf("%i\n");
	}
}

ListaC* insereIni(ListaC* L1, int valor){
	ListaC* aux = L1;
	
	ListaC* novo = (ListaC*)malloc(sizeof(ListaC));
	novo->info = valor;
	novo->prox = NULL;
	novo->ant = NULL;
	
	int n;
	
	if(aux == NULL){
		novo->prox= novo;
		novo->ant = novo;
	} else if(aux->prox== aux){
		novo->prox = aux;
		novo->ant = aux;
		aux->ant = novo;
		aux->prox = novo;
	} else{
		novo->prox = aux;
		aux->ant = novo;
			
			while(n != 0){
				aux=aux->prox;
				if(aux->prox == L1){
					printf("%i\n", aux->info);
					n=0;
				}
			}
				aux->prox = novo;
				novo->ant = aux;
				
	}
	return novo;
}

ListaC* removeLC(ListaC* L1, int valor){
	ListaC* aux = L1;
	int priVal;
	if(aux == NULL){
		printf("Lista vazia\n");
		return aux;
	}else if(aux->prox == aux && aux->info == valor){
		free(aux);
		return NULL;
	}else{
		priVal = aux->info;
		while(aux->prox->info != priVal && aux->info != valor){
			aux=aux->prox;
		}
			aux->ant->prox = aux->prox;
			aux->prox->ant = aux->ant;
			free(aux);
			return L1;
		}
}

//ex6
ListaC* removePar(ListaC* L1){
	ListaC* aux = L1;
	int priVal, count;
	
	priVal=aux->info;
	count=0;
	
	if(aux->info % 2 == 0 && aux->prox == aux){ //Teste se só tem 1 elemento e ele é par//
		free(aux);
		return NULL;
	}
	while(aux->prox->info != priVal){
		if(aux->info % 2 == 0)
			count++;
		
	aux=aux->prox;
	}
	if(aux->info % 2 == 0)
		count++;
		
	aux = L1;
	while(count != 0){
		if(aux->info % 2 == 0 && aux->prox != aux){
			ListaC* auxR = aux;
			aux->ant->prox = aux->prox;
			aux->prox->ant = aux->ant;
			
			if(aux->prox !=aux)
			aux=aux->prox;
		
			free(auxR);
			count--;
		}else if(aux->info %2 ==0 && aux->prox == aux){
			return NULL;
		}else{
		aux=aux->prox;
		}
	}
	L1=aux;
	return L1;
}



int main(int argc, char const* argv[]){

	ListaC* L1 = NULL;
	
	L1 = insereIni(L1, 51);
	L1 = insereIni(L1, 40);
	L1 = insereIni(L1, 30);
	//L1 = removeLC(L1,40);
	imprime(L1);
	
	return 0;
}