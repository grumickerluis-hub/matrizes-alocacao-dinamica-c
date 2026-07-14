#ifndef MATRIZES_H
#define MATRIZES_H

int** criar_matriz(int l, int c);

void preencher_manual(int **m, int l, int c);
void preencher_aleatorio(int **m, int l, int c);
void imprimir_matriz(int **m, int l, int c);

int somatorio(int **m, int l, int c);
double media(int **m, int l, int c);
int soma_diagonal_principal(int **m, int l, int c);
double media_diagonal_secundaria(int **m, int l, int c);
void mostrar_endereco(int **m, int l, int c, int num);
int contar_ocorrencias(int **m, int l, int c, int num);
int maior_valor(int **m, int l, int c);
int menor_valor(int **m, int l, int c);

void escrever_arquivo(int **m, int l, int c, int num);
void liberar_matriz(int **m, int l);        

#endif  