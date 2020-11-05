#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int receberDificuldade(int tam, int qtdPares[]);
int criarMatriz(int dificuldade, char caracteres[9]);

int main(void)
{
    char caracteres[9] = "!@#$%%&(";
    int qtdPares[3] = {4, 6, 8};
    receberDificuldade(3, qtdPares);
    return 0;
}
/* a funçao recebe um vetor contendo a quantidade de pares em cada dificuldade
e o tamanho do vetor. Ela escreve no console as dificuldades e recebe
a escolhida pelo usuario, dps retorna a quantidade de pares da dificuldade
escolhida. */
int receberDificuldade(int tam, int qtdPares[])
{
    int i, dificuldade;
    for(i=0; i<tam; i++)
    {
        printf("Dificuldade %d: %d pares.\n", i+1, qtdPares[i]);
    }
    while (1)
    {
        printf("Selecione a dificuldade:");
        scanf("%d", &dificuldade);
        if(dificuldade>0 && dificuldade<=tam) break;
        else printf("Dificuldade selecionada invalida.\n");
    }
    return dificuldade;
}
int criarMatriz(int dificuldade, char caracteres[9])
{
    int matriz[4][4], linha, qtdChar, i;
    qtdChar = 4 + (dificuldade-1)*2;
    linha = dificuldade+1;
    srand(time(0));
    for(i=0; i<qtdChar; i++)
    {
        while(1)
        {

        }
    }
}