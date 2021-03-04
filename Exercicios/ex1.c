#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TAM 50

void inicializar(int *v){
	int i;
	
	srand(time(NULL));
	
	for(i=0;i<TAM;i++){
	v[i]= 1 + rand() % 100;
	}
}

void menor_maior(int *v, int *min, int *max){
	int i;
	*min=100;
	*max=0;
	for(i=0;i<TAM;i++){
	
	if(*max<v[i])
		*max= v[i];
	
	if(*min>v[i])
		*min= v[i];
	
	}
}

int main(int argc, char const* argv[]){
	
	int vetor[TAM], i, menor, maior;
	
	inicializar(vetor);
		
	for(i=0;i<TAM;i++){
		printf("%i ", vetor[i]);
	}
	
	menor_maior(vetor, &menor, &maior);
	
	printf("\n");
	printf("Menor valor: %i \nMaior valor: %i",menor, maior);
	
	return 0;
}