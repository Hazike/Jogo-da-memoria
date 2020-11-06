#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int receberDificuldade(int tam, int qtdPares[]);
void criarMatriz(int dificuldade, char caracteres[9]);
void mostrarMatriz();
void lerCasas();
void atualizarMatriz(int lin1, int col1, int lin2, int col2);
void limpaTela();
void checaFim();
void mostraPontuacao();
void delay(int segundos);

int matriz[4][4];
int linha, jogadas, acertos, running, qtdChar, dificuldade;

int main(void)
{
    char caracteres[9] = "!@#$%&*(";
    int qtdPares[3] = {4, 6, 8};
    jogadas = 0; acertos = 0, running = 1;
    dificuldade = receberDificuldade(3, qtdPares);
    criarMatriz(dificuldade, caracteres);
    while(running)
    {
        mostrarMatriz();
        lerCasas();
        delay(3);
        limpaTela();
        checaFim();
    }
    
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
    limpaTela();
    return dificuldade;
}
void criarMatriz(int dificuldade, char caracteres[9])
{
    int i, j, linAleatoria, colAleatoria, count;
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
    /* apagar dps */
    for(i=0;i<linha;i++)
    {
        for(j=0;j<4;j++) printf("%2c", matriz[i][j]);
        printf("\n");
    }
}
void mostrarMatriz()
{
    int i,j;
    mostraPontuacao();
    for (i=0;i<linha;i++)
    {
        if (i==0)
            printf ("   1  2  3  4\n");
        printf ("%d ", i+1);
        for (j=0;j<4;j++)
        {
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
    printf ("Insira a casa que quer revelar no formato: LINHA,COLUNA: ");
    scanf("%d,%d", &lin1, &col1);
    limpaTela();
    lin1--; col1--;
    for (i=0;i<linha;i++)
    {
        if (i==0)
            printf ("   1  2  3  4\n");
        printf ("%d ", i+1);
        for (j=0;j<4;j++)
        {
            if(i == lin1 && j == col1)
                printf("[%c]", matriz[i][j]);
            else if(matriz[i][j])
                printf ("[?]");
            else printf("   ");
        }
        printf("\n");
    }
    printf ("Insira a segunda casa que quer revelar no formato: LINHA,COLUNA: ");
    scanf("%d,%d", &lin2, &col2);
    limpaTela();
    lin2--; col2--;
    for (i=0;i<linha;i++)
    {
        if (i==0)
            printf ("   1  2  3  4\n");
        printf ("%d ", i+1);
        for (j=0;j<4;j++)
        {
            if((i == lin1 && j == col1) || (i == lin2 && j == col2))
                printf("[%c]", matriz[i][j]);
            else if(matriz[i][j])
                printf ("[?]");
            else printf("   ");
        }
        printf("\n");
    }
    if (matriz[lin1][col1] == matriz[lin2][col2])
    {
        atualizarMatriz(lin1,col1,lin2,col2);
        acertos++;
	}
    jogadas++;
}
void atualizarMatriz(int lin1, int col1, int lin2, int col2)
{
	matriz[lin1][col1] = 0;
	matriz[lin2][col2] = 0;
}
void limpaTela()
{
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #elif __APPLE__
        system("clear");
    #endif
    
} 
void checaFim()
{
    if(acertos == qtdChar)
    {
    running = 0;
    limpaTela();
    printf("Parabens!!!!\nVoce concluiu a dificuldade %d com %d jogadas.", dificuldade, jogadas);
    } 
}
void mostraPontuacao()
{
    printf("Jogadas: %d  Acertos: %d\n", jogadas, acertos);
}
void delay(int segundos)
{
    int tempFinal = time(0) + segundos;
    while(time(0)<tempFinal);
}