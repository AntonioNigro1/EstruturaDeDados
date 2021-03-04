#include<stdlib.h>
#include<stdio.h>
#define F 3

typedef struct Nota {
	float P1;
	float P2;
	float T;
	float APS;
}Nota;

typedef struct aluno{
	char nome[40];
	int RA;
	int falta;
	Nota *nota;
}Aluno;

void cadastro(Aluno *a){
	int i;
	for(i=0;i<F;i++){
	printf("Entre com o nome do Aluno: ");
	fgets(a[i].nome, 40, stdin);
	setbuf(stdin,NULL);
	
	printf("Entre com o RA do aluno: ");
	scanf("%i", &a[i].RA);
	setbuf(stdin,NULL);
	
	printf("Entre com o numero de faltas do aluno: ");
	scanf("%i", &a[i].falta);
	setbuf(stdin, NULL);
	
	printf("Entre com a Nota 1 do Aluno: ");
	scanf("%f", &a[i].nota->P1);
	setbuf(stdin,NULL);
	
	printf("Entre com a Nota 2 do Aluno: ");
	scanf("%f", &a[i].nota->P2);
	setbuf(stdin,NULL);
	
	printf("Entre com a Nota do Trabalho do Aluno: ");
	scanf("%f", &a[i].nota->T);
	setbuf(stdin,NULL);
	
	printf("Entre com a Nota da APS do aluno: ");
	scanf("%f", &a[i].nota->APS);
	setbuf(stdin,NULL);
	
	}
}

void imprimir(Aluno *a){
	int i;
	
	printf("Digite o indice do aluno: \n");
	scanf("%i", &i);
	setbuf(stdin, NULL);
	
	printf("Nome: %s\n",a[i].nome);
	printf("Ra:%i\n",a[i].RA);
	printf("P1: %.2f\n",a[i].nota->P1);
	printf("P2: %.2f\n",a[i].nota->P2);
	printf("Trabalho: %.2f\n",a[i].nota->T);
	printf("APS: %.2f\n",a[i].nota->APS);	
}

void media_p1(Aluno *a, float *x){
	int i;
	
	for(i=0;i<F;i++){
		*x= *x + a[i].nota->P1;
	}
	
	*x= *x/i;
}

void maior_falta(Aluno *a, int *mfalta){
	
	int i;
	float x=0.0;
	
	for(i=0;i<F;i++){
		if(x<a[i].falta)
			x=a[i].falta;
	}
	
	for(i=0;i<F;i++){
		if(x=a[i].falta)
			*mfalta = i;
	}
}

int main(int argc, char const* argv[]){
	Aluno *aluno1;
	int i, falta;
	float mp1;
	
	aluno1 = (Aluno*) malloc(F*sizeof(Aluno));
	
	for(i=0;i<F;i++){
	aluno1[i].nota = (Nota*)malloc(sizeof(Nota));
	}
	
	cadastro(aluno1);
	
	media_p1(aluno1, &mp1);
	
	printf("A media da P1 dos alunos eh: %f\n", mp1);
	
	maior_falta(aluno1, &falta);
	
	printf("O indice do aluno com maior numero de faltas eh: %i\n", falta);
	
	imprimir(aluno1);
	
	free(aluno1->nota);
	free(aluno1);
	return 0;
}