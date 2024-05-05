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

void criaFilaGuiche(int NumGuiche)
{
    VGuiches[NumGuiche].Inicio = NULL;
    VGuiches[NumGuiche].Fim = NULL;
    VGuiches[NumGuiche].contador = 0;
}

void imprimeFilaGuiche(int NumGuiche)
{
    NoFila *aux = VGuiches[NumGuiche].Inicio;
    while (aux != NULL)
    {
        printf("%d ", aux->conteudo);
        aux = aux->prox;
    }
}

NoFila *insereFilaGuiche(int NumGuiche, int NrCarro)
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

NoFila *tiraFilaGuiche(int NumGuiche)
{
    if (VGuiches[NumGuiche].Inicio == NULL)
        return NULL;

    NoFila *noRemovido = VGuiches[NumGuiche].Inicio;
    VGuiches[NumGuiche].Inicio = VGuiches[NumGuiche].Inicio->prox;

    if (VGuiches[NumGuiche].Inicio == NULL)
        VGuiches[NumGuiche].Fim = NULL;

    VGuiches[NumGuiche].contador++;
    free(noRemovido);
    return VGuiches[NumGuiche].Inicio;
}

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
