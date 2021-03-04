#include <stdlib.h>
#include <stdio.h>


//Passagem por referencia//

void altera (int *px, int *py){ //px e py recebem o endereço de x e y//
	*px = *px +1;  
	*py = *py +1;
	//Adiciona 1 ao conteudo do endereço de px e py//
}



void main (){
	
	int x = 5;
	int y = 6;
	
	altera(&x, &y); //Passa o endereço de x e y//
	
	printf("%d,  %d \n", x, y);
}

//Vetores e ponteiros//


void main(){
	int V[50];
	int *p;
	*p=&V[4]; //o ponteiro aponta para o endereço da quarta posição do vetor//
	
	*p++;  //o ponteiro ira apontar para o endereço da proxima casa do vetor//
	
	
	p=V; //o ponteiro ira apontar para o inicio do vetor, este comando "linka" o ponteiro e o vetor e é possivel navegar pelo vetor pelo ponteiro com p++ ou p[i]//
	
	
}