#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	
	i=10;
	
	int *j; //O operador * declara como ponteiro //
	
	// J recebe endereço de i //
	j= &i;      
	//   j=i esta errado pois  J esta recebendo um valor que nao corresponde ao endereço de i  //
	
	
	//Mostra o conteudo (endereço de i) do ponteiro//
	printf("%i\n", j);
	
	//O * mostra o conteudo do endereço que o ponteiro guarda //
	printf("%i\n", *j); 
	
	*j = 30; //O endereço guardado pelo ponteiro tera seu conteudo alterado para 30//
	
	
	return 0;
}