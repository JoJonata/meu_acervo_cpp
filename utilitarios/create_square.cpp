#include<stdio.h>
//#include<ctype.h>

char ch = '*';

void printSquare(int lado){
	for(int i = 0; i < lado; i++){
		for(int j = 0; j <lado; j++){
			printf("%c", ch);
		}
		printf("\n");
	}
}

int main() {
	
	int lado;

	printf("Programa que imprime um quadrado em forma de *\nDe o numero de lados ao quadrado.\n");
	
	do{
		printf("Digite um número maior que zero: ");
		scanf("%i", &lado);
	} while (lado<=0);
	
	printSquare(lado);
}
