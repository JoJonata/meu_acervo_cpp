#include<stdio.h>

int main(){
	int i;
	
	for(i=0; i < 20; i++)
		printf("*");
	printf("\n*");

	for(i=0; i < 18; i++)
		printf(" ");
	printf("*\n*");

	for(i=0; i < 18; i++)
		printf(" ");
	printf("*\n");
	
	for(i=0; i < 20; i++)
		printf("*");
		
	return 0;
}
    
