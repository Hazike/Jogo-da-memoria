#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int receberDificuldade(int tam, int qtdPares[]);
void criarMatriz(int dificuldade, char caracteres[9]);
void mostrarMatriz();
void lerCasas();
int matriz[4][4];
int linha,pontos;

int main(void)
{
    char caracteres[9] = "!@#$%&*(";
    int qtdPares[3] = {4, 6, 8}, dificuldade;
    criarMatriz(receberDificuldade(3, qtdPares), caracteres);
    while (checarProgresso()!=0){
		mostrarMatriz();
    	lerCasas();
    	printf ("A tela sera limpa em 2 segundos!");
		sleep(3);
		LimpaTela();
	}
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
        printf("Dificuldade %d: %d pares.\n", i+1, qtdPares[i]);
    }
    while (1)
    {
        printf("Selecione a dificuldade: ");
        scanf("%d", &dificuldade);
        if	(dificuldade>0 && dificuldade<=tam) 
			break;
        else 
			printf("Dificuldade selecionada invalida!\n");
    }
    return dificuldade;
}
void criarMatriz(int dificuldade, char caracteres[9]){
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
void mostrarMatriz(){
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
void lerCasas(){
    int i, j , lin1, col1, lin2, col2;
    printf ("Insira a casa que quer revelar no formato: LINHA,COLUNA: ");
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
    printf ("Insira a segunda casa que quer revelar no formato: LINHA,COLUNA: ");
    scanf("%d,%d", &lin2, &col2);
    lin2--; col2--;
    for (i=0;i<linha;i++){
        if (i==0)
            printf ("   1  2  3  4\n");
        printf ("%d ", i+1);
        for (j=0;j<4;j++){
            if(i == lin1 && j == col1 || i == lin2 && j == col2)
                printf("[%c]", matriz[i][j]);
            else if(matriz[i][j])
                printf ("[?]");
            else printf("   ");
        }
        printf("\n");
    	if (matriz[lin1][col1] == matriz[lin2][col2]){
            	atualizarMatriz(lin1,col1,lin2,col2);
		}
    }
}
void atualizarMatriz(int lin1, int col1, int lin2, int col2){
	matriz[lin1][col1] = 0;
	matriz[lin2][col2] = 0;

}
int checarProgresso(){
	int i,j,cont=0;
	for (i=0;i<linha;i++){
		for (j=0;j<4;j++){
			if (matriz[i][j] == 0)
				cont++;
		}
	}
	if (cont == (linha*4))
		return 0;
	else
		return 1;
}
void LimpaTela(){
    #if defined(linux) || defined(unix) || defined(APPLE)
        system("clear");
    #endif

    #if defined(WIN32) || defined(WIN64)
        system("cls");
    #endif
}
