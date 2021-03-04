#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

Lista* insereIni(Lista* Ref, int valor){

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = Ref;

return novo;
}

void imprimeL(Lista* L){
	
	Lista* aux = L;
	
	while(aux!= NULL){
		printf("%i\t", aux->info);
		aux=aux->prox;
	}
	printf("\n");
}

int sublista(Lista* L1, Lista* L2){
	Lista* aux = L1;
	Lista* aux2 = L2;
	Lista* aux3= L1;
	int n=0;
	
	if(L1 == NULL && L2 == NULL) // testa se as duas são vazias
		return 1;
	
	
	while(aux->prox->prox != NULL){ //como as 2 listas estavam perdendo a referencia no final(de NULL), eu arrumei aq
		aux=aux->prox;
	}
	aux->prox=NULL;
	
	while(aux2->prox->prox != NULL){
		aux2=aux2->prox;
	}
	aux2->prox=NULL;
	
	aux= L1;
	aux2=L2;
	
	while(aux != NULL && n != 1){ // procurando se existe um elemento em comum nas 2 listas, sai dos laços se achar
		while(aux2 != NULL && n != 1){
			if(aux->info == aux2->info){
				aux3=aux;
				n=1;
			}
			aux2=aux2->prox;
		}
		aux=aux->prox;
		aux2= L2;
	}
	
	if(n == 1){
		aux2=L2;
		while(n == 1 && aux2 != NULL){ //comparando se existe um elemento diferente do outro na sequencia das listas
			if(aux3->info != aux2->info)
				n=0;
			
			aux3=aux3->prox;
			aux2=aux2->prox;
		}
	}
	
	return n;
}

int main(int argc,char const* argv[]){
	
	int sub;
	
	Lista* L1 = (Lista*)malloc(sizeof(Lista));
	Lista* L2 = (Lista*)malloc(sizeof(Lista));
	L1->prox = NULL;
	L2->prox = NULL;
	
	L1=insereIni(L1, 7);
	L1=insereIni(L1, 6);
	L1=insereIni(L1, 5);
	L1=insereIni(L1, 4);
	L1=insereIni(L1, 3);
	L1=insereIni(L1, 2);
	L1=insereIni(L1, 1);
	
	L2=insereIni(L2,4);
	L2=insereIni(L2,5);
	L2=insereIni(L2,2);
	
	printf("L1: ");
	imprimeL(L1);
	printf("L2: ");
	imprimeL(L2);

	sub= sublista(L1, L2);
	
	if(sub== 0)
		printf("L2 nao eh sublista de L1\n");
	else if(sub == 1)
		printf("L2 eh sublista de L1\n");
	else
		printf("Error\n");
	
	
	return 0;
}