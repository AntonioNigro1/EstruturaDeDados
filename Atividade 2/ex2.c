#include<stdlib.h>
#include<stdio.h>

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

int cheia (Arv* a){
	int x;
	if(a==NULL)
		return 1;
	if(a->dir == NULL && a->esq == NULL)
		return 1;
	else if(a->dir != NULL && a->esq != NULL){
		x= cheia(a->esq);
		x= cheia(a->dir);
	}
	else
		return 0;
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
	
	abb_imprime(a);
	
	int x = cheia(a);
	
	if(x==1)
		printf("\nArvore cheia");
	if(x==0)
		printf("\nArvore nao cheia");
	
	
	return 0;
}