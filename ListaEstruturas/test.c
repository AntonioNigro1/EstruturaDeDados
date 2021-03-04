//ex6
ListaC* removePar(ListaC* L1){
	ListaC* aux = L1;
	int priVal, count;
	
	priVal=aux->info;
	count=0;
	
	if(aux->info % 2 == 0 && aux->prox == aux){ //Teste se só tem 1 elemento e ele é par//
		free(aux);
		return NULL;
	}
	while(aux->prox->info != priVal){
		if(aux->info % 2 == 0)
			count++;
		
	aux=aux->prox;
	}
	if(aux->info % 2 == 0)
		count++;
		
	aux = L1;
	while(count != 0){
		if(aux->info % 2 == 0 && aux->prox != aux){
			ListaC* auxR = aux;
			auxR->ant->prox = auxR->prox;
			auxR->prox->ant = auxR->ant;
			
			if(aux->prox !=aux)
			aux=aux->prox;
		
			free(auxR);
			count--;
		}else if(aux->info %2 ==0 && aux->prox == aux){
			return NULL;
		}else{
		aux=aux->prox;
		}
	}
	L1=aux;
	return L1;
}