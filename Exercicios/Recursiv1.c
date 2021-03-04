#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

void imprime(Lista* L){ //recursão na função imprime
	if(L != NULL)
		printf("%i\t",L->info);
	
	imprime(L->prox);
}


Lista* insereFim(Lista* L, int valor){
	
	if(L==NULL){
		Lista* novo = (Lista*)malloc(sizeof(Lista));
		novo->info = valor;
		novo->prox = L;
		return novo;
	}else{
		L->prox = insereFim(L->prox, valor);
	}
}

int maiorVal(Lista* L){
	int maior;
	if(L==NULL)
		return -1;
	else{
		maior = maiorVal(L->prox);
		
		if(maior<L->info)
		return L->info;
		
		else
		return maior;
	
	}
}


int main(int argc,char const* argv[]){

	Lista* L1 = NULL;
	
	L1=insereFim(L1, 1);
	L1=insereFim(L1, 2);
	L1=insereFim(L1, 70);
	L1=insereFim(L1, 4);
	L1=insereFim(L1, 5);
	
	int n =maiorVal(L1);
	
	printf("--%i--\n", n);
	
	imprime(L1);
	

	return 0;
}