#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrizes.h"

int main(){

    int l, c, opcao, num;
    int **m;


    printf("Digite o numero de linhas: ");
    scanf("%d", &l);

    printf("Digite o numero de colunas: ");
    scanf("%d", &c);

    if(l <= 0 || c <= 0){
        printf("Linhas e colunas devem ser maiores que zero.\n");
    return 1;
    }

    m = criar_matriz(l, c);

    printf("\n1 - Preencher manualmente");
    printf("\n2 - Preencher aleatoriamente");
    printf("\nEscolha: ");
    scanf("%d", &opcao);

    if(opcao == 1){
        preencher_manual(m, l, c);
    } else {
        preencher_aleatorio(m, l, c);
    }

    imprimir_matriz(m, l, c);

    printf("\nDigite um numero para buscar: ");
    scanf("%d", &num);

    mostrar_endereco(m, l, c, num);

    printf("\nSomatorio: %d", somatorio(m, l, c));
    printf("\nMedia: %.2lf", media(m, l, c));
    printf("\nSomatorio diagonal principal: %d", soma_diagonal_principal(m, l, c));
    printf("\nMedia diagonal secundaria: %.2lf", media_diagonal_secundaria(m, l, c));
    printf("\nQuantidade de ocorrencias de %d: %d", num, contar_ocorrencias(m, l, c, num));
    printf("\nMaior valor: %d", maior_valor(m, l, c));
    printf("\nMenor valor: %d", menor_valor(m, l, c));

    escrever_arquivo(m, l, c, num);

    liberar_matriz(m, l);

    return 0;
}