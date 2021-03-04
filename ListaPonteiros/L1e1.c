#include<stdlib.h>
#include<stdio.h>
#define n 5


int* uniao(int *x1, int *x2, int n1, int n2, int *qtd){
	int vtemp[10], i, j, count=0;
	
	for(i=0;i<n1;i++){
	vtemp[count] = x1[i];
		count++;
	}
	
	for(i=0;i<n2;i++){
		for(j=0;j<n1;j++){
			if(vtemp[j]==x2[i]){
				i++;
				j=0;	
			}
		}
		if(j==n1){
				vtemp[count] = x2[i];
				count++;
			}	
	}
	
	*qtd=count;
	
	for(i=0;i<n1+n2;i++){
		if(vtemp[i] == vtemp[j]){
			vtemp[j] = 0;
			}
		j++;
	}
	
	int *V3 = (int*)malloc((*qtd)*sizeof(int));
	
	for(i=0;i<*qtd;i++){
		V3[i] = vtemp[i];
		
	}
	
	return V3;
}

int main(int argc, char const *argv[]){
	
	int *qtd =(int*)malloc(sizeof(int));
	int *V1 = (int*)malloc(n*sizeof(int));
	int *V2 = (int*)malloc(n*sizeof(int));
	int i;
	
	V1[0]= 1;
	V1[1]= 3;
	V1[2]= 5;
	V1[3]= 6;
	V1[4]= 7;
	
	V2[0]= 1;
	V2[1]= 3;
	V2[2]= 4;
	V2[3]= 6;
	V2[4]= 8;
	
	int *V3 = uniao(V1, V2, n, n, qtd);
	
	for(i=0;i<*qtd;i++){
		printf("%i\t", V3[i]);	
	}
	
	free(V1);
	free(V2);
	free(V3);
	
	return 0;
}