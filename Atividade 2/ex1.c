#include <stdlib.h>
#include <stdio.h>

typedef struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
}Arv;

void abb_imprime (Arv* a){
	
	if (a != NULL) {
	printf("%d\n",a->info);
	abb_imprime(a->esq); 
	abb_imprime(a->dir);
	}
	
}

Arv* abb_insere (Arv* a, int v){
	
	if (a==NULL) {
	a = (Arv*)malloc(sizeof(Arv));
	a->info = v;
	a->esq = a->dir = NULL;
	}
	
	else if (v < a->info)
	a->esq = abb_insere(a->esq,v);

	else
	a->dir = abb_insere(a->dir,v);
	
	return a;
}

int verificaBal(Arv *a){
	int contE =0;
	int contD = 0;
	
	if(a == NULL)
		return -1;
	
	contE=verificaBal(a->esq);
	contD=verificaBal(a->dir);
	
	if(contD>contE)
		return ++contD;
	
	else
		return ++contE;
	
}

int main(int argc,char const* argv[]){
	Arv* a = NULL;
	
	a= abb_insere(a, 10 );
	a= abb_insere(a,15);
	a= abb_insere(a,8);
	a= abb_insere(a,17);
	a= abb_insere(a,7);
	a= abb_insere(a,9);
	a= abb_insere(a,14);
//	a= abb_insere(a, 30);
//	a= abb_insere(a, 31);
//	a= abb_insere(a,32);
	
	int bal1 = verificaBal(a->esq);
	int bal2 = verificaBal(a->dir);
	
	if((bal1-bal2)< -1 || (bal1-bal2)>1)
		printf("\nArvore desbalanceada");
	else 
		printf("\nArvore Balanceada");
	
	
	return 0;
}