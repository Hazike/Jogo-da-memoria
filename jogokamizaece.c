#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int receberDificuldade(int tam, int qtdPares[]);
int* criarMatriz(int dificuldade);

int main(void)
{
	printf ("-------------Bem vindo ao Jogo da Memoria---------------------\nEssas sao as dificuldades disponiveis:\n");
    int qtdPares[3] = {4, 10, 16};
    receberDificuldade(3, qtdPares);
    return 0;
}
/* a fun�ao recebe um vetor contendo a quantidade de pares em cada dificuldade
e o tamanho do vetor. Ela escreve no console as dificuldades e recebe
a escolhida pelo usuario, dps retorna a quantidade de pares da dificuldade
escolhida. */
int receberDificuldade(int tam, int qtdPares[])
{
    int i, dificuldade;
    for(i=0; i<tam; i++)
    {
        printf("Dificuldade numero [%d] com (%d) pares.\n", i+1, qtdPares[i]);
    }
    while (1)
    {
        printf("Selecione a dificuldade: ");
        scanf("%d", &dificuldade);
        if(dificuldade>0 && dificuldade<=tam) break;
        else printf("Dificuldade selecionada invalida.\n");
    }
    return dificuldade;
}
/*int criarMatriz(int dificuldade)
{
    srand(time(0));
    if(dificuldade==1)
    {

    }
}*/
