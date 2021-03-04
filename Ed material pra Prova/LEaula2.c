#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

Lista* insereIni(Lista* Ref, int valor){

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info  = valor;
	novo->prox = Ref;

return novo;
}

void imprime(Lista* P){
	Lista* aux;
	aux= P;
	do{
		printf("%d\t",aux->info);
		aux=aux->prox;
		
	}while(aux != NULL);

}

Lista* insereFim(Lista* P, int valor){
	Lista* aux = P;
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = valor;
	
	if(P==NULL){
		novo->prox = P;
		return novo;
	}
	
	while(aux->prox != NULL){
		aux=aux->prox;
	}
		novo->prox= NULL;
		aux->prox = novo;
		return P;
}

Lista* inDados(Lista* L1){
	int x, valor;
	printf("\nDigite o valor que deseja inserir na lista: ");
	scanf("%i", &valor);
	setbuf(stdin, NULL);
	
	printf("\nDigite 1 para inserir no começo da lista, 2 para inserir no final: ");
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

Lista* concatena(Lista* L1, Lista* L2){
	Lista* aux1= L1;
	Lista* aux2= L2;
	
	while(aux1->prox != NULL){
		aux1=aux1->prox;
	}

	while(aux2!=NULL){
		aux1->prox= aux2;
		aux1=aux1->prox;
		aux2=aux2->prox;
	}
	
	return L1;
}

Lista* RemoveLista(Lista* L1, int valor){
	Lista* aux = L1;
	Lista* ant = NULL;
	if(L1==NULL)
		return NULL;
	
	while(aux->info != valor && aux!= NULL){
	ant =aux;
	aux=aux->prox;
	}
	
	if(aux == NULL)
		return L1;
	if(ant == NULL){
		L1=aux->prox;
		free(aux);
		return L1;
	} else {
		ant->prox = aux->prox;
		free(aux);
	}
	return L1;
	
}

Lista* RemovePar(Lista* L1){
	Lista* aux = L1;
	int elem;
	if(L1==NULL)
		return NULL;
	
	while(aux != NULL){
		elem= aux->info;
		aux=aux->prox;
		if(elem % 2 == 0)
			aux=RemoveLista(aux, elem);
	}
	return L1;
}

Lista* inverteLista(Lista* L1){
	Lista* aux = L1;
	Lista* inv = NULL;
	if(aux == NULL)
		return L1;
	
	while(aux!=NULL){
		inv = insereIni(inv, aux->info);
		aux=aux->prox;
	}
	free(aux);
	return inv;
}

int maiorValor(Lista* L1){
	Lista* aux = L1;
	int maior;
	while(aux != NULL){
		if(maior<aux->info)
			maior=aux->info;
		
		aux=aux->prox;
	}
	
	return maior;
}

Lista* maiorInicio(Lista* L1){
	int comp= maiorValor(L1);
	Lista* aux = L1;
	Lista* ant;
	
	if(aux==NULL)
		return NULL;
	
	if(aux->prox == NULL)
		return L1;
	
	while(aux->info != comp ){
		ant=aux;
		aux=aux->prox;
	}
	
	ant->prox= aux->prox;
	aux->prox = L1;
	return aux;
}

Lista* maiorIniOti(Lista* L1){
	Lista* aux = L1;
	Lista* max;
	Lista* ant;
	max->info=aux->info;
	
	if(aux==NULL)
		return NULL;
	
	if(aux->prox == NULL)
		return L1;
	
	while(aux != NULL){
		
		if(max->info < aux->info){
			max->info = aux->info;
			aux=aux->prox;
		}
		
		aux=aux->prox;
	}
}

int main(int argc, char const* argv[]){
	Lista* L1 = NULL;
	Lista* L2 = NULL;
	Lista* L = NULL;
	
	L1=inDados(L1);
	imprime(L1);
	//L1=RemoveLista(L1, 15);
	
	
	//printf("\n");
	//L1=RemovePar(L1);
	//L1=inverteLista(L1);
	//L1=maiorIniOti(L1);
	imprime(L1);
	 
	
	return 0;
}