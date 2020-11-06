#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int receberDificuldade(int tam, int qtdPares[]);
<<<<<<< HEAD
int criarMatriz(int dificuldade, char caracteres[9]);

int main(void)
{
    char caracteres[9] = "!@#$%%&(";
    int qtdPares[3] = {4, 6, 8};
    receberDificuldade(3, qtdPares);
=======
void criarMatriz(int dificuldade, char caracteres[9]);
void mostrarMatriz();
void lerCasas();

int matriz[4][4];
int linha;

int main(void)
{
    char caracteres[9] = "!@#$%&*(";
    int qtdPares[3] = {4, 6, 8}, dificuldade;
    dificuldade = receberDificuldade(3, qtdPares);
    criarMatriz(dificuldade, caracteres);
    mostrarMatriz();
    lerCasas();
>>>>>>> 2553b88afc90d208ad89cfff8470ad13119adef7
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
<<<<<<< HEAD
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
=======
void criarMatriz(int dificuldade, char caracteres[9])
{
    int qtdChar, i, j, linAleatoria, colAleatoria, count;
    qtdChar = 4 + (dificuldade-1)*2;
    linha = dificuldade+1;
    srand(time(0));
    for(i=0; i<linha; i++)
        for(j=0; j<4; j++) matriz[i][j] = 0;
    for(i=0; i<qtdChar; i++)
    {
        count = 0;
        while(1)
        {
            linAleatoria = rand()%linha;
            colAleatoria = rand()%4;
            if(matriz[linAleatoria][colAleatoria] == 0)
            {
                matriz[linAleatoria][colAleatoria] = caracteres[i];
                count++;
            }
            if(count == 2) break;
        }
    }
    for(i=0;i<linha;i++)
    {
        for(j=0;j<4;j++) printf("%2c", matriz[i][j]);
        printf("\n");
    }
}
void mostrarMatriz()
{
    int i,j;
    for (i=0;i<linha;i++){
        if (i==0)
            printf ("   1  2  3  4\n");
        printf ("%d ", i+1);
        for (j=0;j<4;j++){
            if(matriz[i][j])
                printf ("[?]");
            else printf("   ");
        }
        printf("\n");
    }
}
void lerCasas()
{
    int i, j , lin1, col1, lin2, col2;
    scanf("%d,%d", &lin1, &col1);
    lin1--; col1--;
    for (i=0;i<linha;i++){
        if (i==0)
            printf ("   1  2  3  4\n");
        printf ("%d ", i+1);
        for (j=0;j<4;j++){
            if(i == lin1 && j == col1)
                printf("[%c]", matriz[i][j]);
            else if(matriz[i][j])
                printf ("[?]");
            else printf("   ");
        }
        printf("\n");
    }
    scanf("%d,%d", &lin2, &col2);
    lin2--; col2--;
    for (i=0;i<linha;i++){
        if (i==0)
            printf ("   1  2  3  4\n");
        printf ("%d ", i+1);
        for (j=0;j<4;j++){
            if(i == lin1 && j == col1)
                printf("[%c]", matriz[i][j]);
            else if(i == lin2 && j == col2)
                printf("[%c]", matriz[i][j]);
            else if(matriz[i][j])
                printf ("[?]");
            else printf("   ");
        }
        printf("\n");
    }
}

>>>>>>> 2553b88afc90d208ad89cfff8470ad13119adef7
