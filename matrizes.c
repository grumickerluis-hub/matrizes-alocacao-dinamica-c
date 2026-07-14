#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"

int** criar_matriz(int l, int c){

    int **m;

    
    m = malloc(l * sizeof(int*)); //Reserva os ponteiros das linhas

    // Aloca cada linha da matriz
    for(int i = 0; i < l; i++){
        m[i] = malloc(c * sizeof(int)); // reserva os inteiros de cada linha
    }

    return m; //devolve o endereço da matriz
}

void preencher_manual(int **m, int l, int c){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("Digite o valor para[%d][%d]: ", i, j);
                scanf("%d", &m[i][j]);
        }
    }
}

void preencher_aleatorio(int **m, int l, int c){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            m[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimir_matriz(int **m, int l, int c){
    printf("Matriz: \n");
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
        printf("%d\t", m[i][j]);
    }
    printf("\n");
}
}
int somatorio(int **m, int l, int c){
    int soma = 0;
     for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            soma += m[i][j];
        }
}
    return soma;
}
double media(int **m, int l, int c){
    int soma = somatorio(m, l, c);
    return (double)soma / (l * c);
}
int soma_diagonal_principal(int **m, int l, int c){
    int soma = 0;
    int limite;

    if(l < c)
        limite = l;
    else
        limite = c;
    for(int i = 0; i < limite; i++){
        soma += m[i][i];
}
    return soma;
}
double media_diagonal_secundaria(int **m, int l, int c){
       int soma = 0;
        int limite;

    if(l < c)
        limite = l;
    else
        limite = c;
    for(int i = 0; i < limite; i++){
        soma += m[i][c - 1 - i];
}
    return (double)soma / limite;
}
void mostrar_endereco(int **m, int l, int c, int num){
    int encontrado = 0;
     for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(m[i][j] == num){
                encontrado = 1;
            printf("Número encontrado em [%d][%d]\n", i, j);
            printf("Endereço: %p\n", (void*)&m[i][j]);
        }
    }
  }
  if(!encontrado){
    printf("Número não encontrado.\n");
}
}
int contar_ocorrencias(int **m, int l, int c, int num){
    int qtde = 0;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(m[i][j] == num){
            qtde ++;
        }
    }
}
    return qtde;
}
int maior_valor(int **m, int l, int c){
    int maior = m[0][0];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if (m[i][j] > maior){
                maior = m[i][j];
            }
        }
    }
    return maior;
}
int menor_valor(int **m, int l, int c){
    int menor = m[0][0];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if (m[i][j] < menor){
                menor = m[i][j];
            }
        }
    }
    return menor;
}
void liberar_matriz(int **m, int l){

    for(int i = 0; i < l; i++){
        free(m[i]);
    }
free(m);
}
void escrever_arquivo(int **m, int l, int c, int num){

    // Ponteiro para manipulação do arquivo
    FILE *arquivo;

    // Cria (ou sobrescreve) o arquivo para escrita
    arquivo = fopen("resultado.txt", "w");

    // Verifica se o arquivo foi aberto corretamente
    if(arquivo == NULL){
        printf("Erro ao criar o arquivo.\n");
    return;
    }
    // Escreve o resultado dos arquivos
    fprintf(arquivo, "Resultado, Valor\n");
    fprintf(arquivo, "Somatorio, %d\n", somatorio(m, l, c));
    fprintf(arquivo, "Media, %.2lf\n", media(m, l, c));
    fprintf(arquivo, "Somatorio diagonal principal, %d\n", soma_diagonal_principal(m, l, c));
    fprintf(arquivo, "Media diagonal secundaria, %.2lf\n", media_diagonal_secundaria(m, l, c));
    fprintf(arquivo, "Ocorrencias do numero %d, %d\n", num, contar_ocorrencias(m, l, c, num));
    fprintf(arquivo, "Maior valor, %d\n", maior_valor(m, l, c));
    fprintf(arquivo, "Menor valor, %d\n", menor_valor(m, l, c));

    fclose(arquivo); // fecha o arquivo
}