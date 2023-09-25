#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50

// a função getNome deve colocar o seu nome dentro da chamada
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();


void preencherVetor(int* vetor, int tamVetor);
void imprimirVetor(int vetor[], int tam);
/* Assuma que os vetores estão ordenados ao chamar as funções de busca
As funções de busca não devem alterar o vetor
O retorno das funções de busca é o índice do elemento no vetor,

ou -1 caso o elemento não exista no vetor
Você deve armazenar no ponteiro int* numComparacoes o número de comparações
envolvendo elementos do vetor feito pelo seu algoritmo na chamada
a busca sequencial é a busca ingênua */

int buscaSequencialRecursiva(int vetor[], int inicio, int tam, int valor, long* numComparacoes);
int buscaSequencial(int vetor[], int tam, int valor, long* numComparacoes);

// busca binária no vetor
int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor, long* numComparacoes);
int buscaBinaria(int vetor[], int tam, int valor, long* numComparacoes);

// Cada uma das funções deve ordenar o vetor passado como parâmetro
// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor

void insert(int vetor[], int n, long* numComparacoes);
long insertionSortRec(int vetor[], int n);
long insertionSort(int vetor[], int tam);

void troca(int *a, int *b);
int encontrarMenor(int vetor[], int inicio, int tam, long* numComparacoes);
void selectionSortRecursivo(int vetor[], int inicio, int tam, long* numComparacoes);
long selectionSort(int vetor[], int tam);

void merge(int vetor[], int inicio, int meio, int fim, long* numComparacoes);
long mergeSort(int vetor[], int tam);

long partition(int vetor[], int inicio, int fim, long* numComparacoes);
long quickSortRecursivo(int vetor[], int inicio, int fim, long* numComparacoes);
long quickSort(int vetor[], int tam);

void maxHeapify(int vetor[], int tam, int i, long* numComparacoes);
long heapSort(int vetor[], int tam);

#endif // ORDENACAO_H_
