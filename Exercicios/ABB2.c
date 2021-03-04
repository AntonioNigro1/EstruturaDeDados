#include <stdio.h>
#include <stdlib.h>

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

int contNos(Arv* a){
	int cont=0;

	if(a==NULL)
	return 0;

	cont+= contNos(a->esq);
	cont+= contNos(a->dir);

	return ++cont;
}

int calcAltura(Arv* a){
	int contE =0;
	int contD = 0;
	
	if(a == NULL)
		return -1;
	
	contE=calcAltura(a->esq);
	contD=calcAltura(a->dir);
	
	if(contD>contE)
		return ++contD;
	
	else
		return ++contE;
	
}

int arvEq(Arv* a, Arv b){
	
	int x=0,y=0, z=0;
	
	
	if(a == NULL && b == NULL)
		return 0;
	
	if(a->info != b->info)
	y--;
	
	x= contNos(a);
	z= contNos(b);
	
	if(z != x)
	y--;

	x=calcAltura(a);
	z=calcAltura(b);
	
	if(z != x)
	y--;

	if(y<= -2)
		return -1;
	if(y> -2)
		return 0;
	
	
}

int classifArv(Arv* a){
	int x=0, z=0;
	
	if(x == -1)
		return x;
	
	if(a->esq == NULL)
		return 0;
	
	else if(a->dir == NULL)
		return 0;
	
	else if(a->esq->info > a->info || a->dir->info < a->info)
		x=-1;
	
	x = classifArv(a->esq);
	z = classifArv(a->dir);
	
	if(x<z)
		return x;
	else
		return z;
	
}

int arvBin(Arv* a){
	int x=0, z=0;
	
	if(a==NULL)
		return 0;
	
	if(a->dir != NULL && a->esq == NULL || a->dir == NULL && a->esq != NULL)
	return -1;

	x=arvBin(a->esq);
	z=arvBin(a->dir);
	
	if(x<z)
		return x;
	else
		return z;
}

void main(){
	Arv* abb = (Arv*)malloc(sizeof(Arv));
	abb = NULL;
	abb = abb_insere(abb, 15);
	abb = abb_insere(abb, 10);
	abb = abb_insere(abb, 22);
	abb = abb_insere(abb, 17);
	abb = abb_insere(abb, 12);
	abb = abb_insere(abb, 14);
	abb = abb_insere(abb, 23);
	abb_imprime (abb); 
	
	int z = classifArv(abb);
	printf("\nResultado: %i", z);
	
}