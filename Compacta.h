#ifndef COMPACTA_H
#define COMPACTA_H

#include <stdio.h>

#include "arvore.h"

/*Retorna um vetor que possui todas as ocorrencias de uma caractere em um texto e seu respectivo indice (ou seja vetor[caractere] = peso desse caractere)
 * inputs: o ponteiro para o arquivo a ser lido
 * output: o vetor contendo as ocorrencias de cada caractere
 * pre-condicao: o ponteiro do arquivo ter sido previamente inicializado
 * pos-condicao: o ponteiro do arquivo foi totalmente percorrido
*/
int* retornaOcorrencias (FILE* fp);

/*Cria um vetor contendo todas as arvores inicializadas com as informacoes obtidas pela funcao retornaOcorrencias()
 * inputs: o vetor contendo as ocorrencias (pesos) dos caracteres
 * output: um vetor de todas as arvores inicializadas
 * pre-condicao: o vetor de ocorrencias ter sido previamente inicializado
 * pos-condicao: aloca todos os enderecos de arvores na heap, e o vetor dessas arvores
*/
Arv** criaVetorArvores(int* vetor);

/*Gera o arquvo compactada a partir de um endereco de arquivo e tabela de compactacao
 * inputs: o nome do arquivo alvo e a tabela de compactacao
 * output: nenhum
 * pre-condicao: a tabela de compactacao e a arvore de huffman deve ter sido alocada adequadamente
 * pos-condicao: o arquivo compactado eh gerado
*/
void compacta(char* arquivo, bitmap** tabela, Arv* arvore);

/*Imprime um vetor de inteiros na entrada padrao
 * inputs: o vetor alvo e seu tamanho
 * output: nenhum
 * pre-condicao: o vetor deve ter sido alocado adequadametne
 * pos-condicao: o vetor eh impresso na saida padrao
*/
void imprimeVetor(int* vet, int tam);

/*Cria a arvore de compactacao a partir de um vetor de arvores
 * inputs: o vetor de arvores alvo
 * output: o vetor de arvores contendo apenas um elemento, que consiste da arvore de compactacao
 * pre-condicao: o vetor de arvores estar ordenado em ordem crescente
 * pos-condicao: a arvore de compacatacao eh criada
*/
Arv** huffman(Arv** arvores);

/*Cria um vetor de bitmaps (tabela) contendo o caminho para para cada caractere
 * inputs: a tabela alvo
 * output: eh retornado o vetor de bitmaps
 * pre-condicao: a estrutura Arv ter sido devidamente inicializada
 * pos-condicao: o vetor de bitmaps contendo os caminhos de cada caractere eh criado
*/
bitmap** criaTabela(Arv* arvore);

#endif