#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 10

typedef struct registroNo 
{
 int conteudo; 
 struct registroNo *prox;
 
} NoFila;

typedef struct registroGuiche 
{
 int contador;
 int IdCarro;
 NoFila *Inicio;
 NoFila *Fim;
} Guiche;

Guiche VGuiches[N];

//Fun��o cria a fila atribuindo NULL aos ponteiros 
//de controle de in�cio e fim da fila e
// e zero no contador de n�s atendidos
void criaFilaGuiche (int NumGuiche){
    VGuiches[NumGuiche].Inicio = NULL;
    VGuiches[NumGuiche].Fim = NULL;
    VGuiches[NumGuiche].contador = 0;
}


//Fun��o recebe o endere�o do guiche 
//percorre e imprime os elementos da fila 
void imprimeFilaGuiche (int NumGuiche){
    //printf("Fila do Guich� %d: ", NumGuiche);

    NoFila *celulaAtual = VGuiches[NumGuiche].Inicio;
    while (celulaAtual != NULL) {
        printf("%.2d -> ", celulaAtual->conteudo);
        celulaAtual = celulaAtual->prox;
    }
}
//Fun��o recebe n�mero do guiche e o identificador do carro 
//insere no fim da fila do guiche e retorna o endere�o do n� inserido
NoFila * insereFilaGuiche (int NumGuiche, int NrCarro)
{
  NoFila *novoNo = (NoFila *)malloc(sizeof(NoFila));
    novoNo->conteudo = NrCarro;
    novoNo->prox = NULL;

    if (VGuiches[NumGuiche].Inicio == NULL)
    {
        VGuiches[NumGuiche].Inicio = novoNo;
        VGuiches[NumGuiche].Fim = novoNo;
    }
    else
    {
        VGuiches[NumGuiche].Fim->prox = novoNo;
        VGuiches[NumGuiche].Fim = novoNo;
    }

    return novoNo;  
}

//Fun��o recebe o n�mero do guiche e remove o n� do in�cio da fila do guiche
//retorna o endere�o do inicio da fila
NoFila * tiraFilaGuiche (int NumGuiche){
    
    if (VGuiches[NumGuiche].Inicio == NULL)
        return NULL;

    NoFila *noRemovido = VGuiches[NumGuiche].Inicio;
    VGuiches[NumGuiche].Inicio = VGuiches[NumGuiche].Inicio->prox;

    if (VGuiches[NumGuiche].Inicio == NULL)
        VGuiches[NumGuiche].Fim = NULL;

    VGuiches[NumGuiche].contador++;
    return VGuiches[NumGuiche].Inicio;}
 
//Fun��o recebe o endere�o da primeiro n� da fila
//e retorna o n�mero de elementos na fila 
int tamanhoFilaGuiche(NoFila *le)
{
    int tamanho = 0;
    NoFila *aux = le;

    while (aux != NULL)
    {
        tamanho++;
        aux = aux->prox;
    }

    return tamanho;
}

int main() {
 setlocale(LC_ALL,"Portuguese");
 int i, j;
 
 //Cria as filas dos guiches
 for(i = 0; i < N; i++)
    criaFilaGuiche(i);
 
 //Insere 10 carros nas filas dos guiches
 for(i = 0; i < N; i++)
    for (j = 1; j <= 10; j++)
       insereFilaGuiche (i, i*10+j);
 
 //Imprime as filas dos guiches
 for(i = 0; i < N; i++)
 {
   printf("\nGuiche: %i\nNr. Carros fila:%i\nNr. Carros atendidos:%i\n", i, tamanhoFilaGuiche(VGuiches[i].Inicio), VGuiches[i].contador);
   imprimeFilaGuiche (i);
   printf("\n");
 } 
 //Atende 5 carros nas filas dos guiches
 for(i = 0; i < N; i++)
    for (j = 1; j <= 5; j++)
       tiraFilaGuiche (i);
 
 //Imprime as filas dos guiches
 for(i = 0; i < N; i++)
 {
 printf("\nGuiche: %i\nNr. Carros fila:%i\nNr. Carros atendidos:%i\n", i, tamanhoFilaGuiche(VGuiches[i].Inicio), VGuiches[i].contador);
    imprimeFilaGuiche (i);
    printf("\n");
 } 
 //Atende 5 carros nas filas dos guiches
 for(i = 0; i < N; i++)
    for (j = 1; j <= 5; j++)
       tiraFilaGuiche (i);
 
 //Imprime as filas dos guiches
 for(i = 0; i < N; i++)
 {
    printf("\nGuiche: %i\nNr. Carros fila:%i\nNr. Carros atendidos:%i\n", i, tamanhoFilaGuiche(VGuiches[i].Inicio), VGuiches[i].contador);
    imprimeFilaGuiche (i);
    printf("\n");
 } 
 return 0;
}
