#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const* argv[]){
	int i=34, j;
	int *p;
	p= &i;
	*p++;
	j= *p+ 33;
	
	printf("%i, %i, %i, %i,", i, j, *p, &p);
	
	return 0;
}