#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>

#include "bitmap.h"

typedef struct caractere_st Caractere;

typedef struct arvore_st Arv;


/*Aloca memoria para o caractere e inicializa seus campos
 * inputs: o caractere e o peso da estrutura
 * output: um ponteiro para a estrutura Caractere inicializado
 * pre-condicao: os campos crt e peso devem ser validos
 * pos-condicao: a estrutura Caractere foi criada, seus campos foram inicializados, e seu endereco eh retornado
*/
Caractere* inicCaractere(int crt, int peso);

/*Retorna o campo peso da estrutura caractere
 * inputs: o ponteiro para estrutura Caractere
 * output: o valor inteiro do peso da estrutura
 * pre-condicao: a estrutura Caractere ter sido devidamente inicializada
 * pos-condicao: nenhuma
*/
int retornaPeso(Caractere* ch);

/*Retorna o campo peso da estrutura caractere dentro de uma estrutura de arvore
 * inputs: o ponteiro para estrutura Arv
 * output: o valor inteiro do peso da estrutura Caractere dentro da estrutura Arv
 * pre-condicao: a estrutura Arv ter sido devidamente inicializada
 * pos-condicao: nenhuma
*/
int retornaPesoArvore(Arv* a);

/*Retorna o campo crt da estrutura caractere dentro de uma estrutura de arvore
 * inputs: o ponteiro para estrutura Arv
 * output: o valor inteiro do crt da estrutura Caractere dentro da estrutura Arv
 * pre-condicao: a estrutura Arv ter sido devidamente inicializada
 * pos-condicao: nenhuma
*/
int retornaCrtArvore(Arv* a);

/*Retorna o campo crt da estrutura caractere
 * inputs: o ponteiro para estrutura Caractere
 * output: o valor inteiro do "crt" da estrutura
 * pre-condicao: a estrutura Caractere ter sido devidamente inicializada
 * pos-condicao: nenhuma
*/
int retornaCrt(Caractere* ch);

/*Retorna um dos ramos de uma arvore dependendo da direcao: 0 = esquerda, 1 = direita
 * inputs: o ponteiro para estrutura Arv e a direcao
 * output: o ponteiro da estrutura Arv da direcao especificada
 * pre-condicao: a estrutura Arv ter sido devidamente inicializada e a direcao ser valida
 * pos-condicao: nenhuma
*/
Arv* retornaRamo(Arv* a, int direcao);

/*Cria uma arvore com os ramos vazios
 * inputs: nenhum
 * output: o ponteiro para a arvore inicializada (NULL)
 * pre-condicao: nenhuma
 * pos-condicao: nenhuma
*/
Arv* criaArvoreVazia();

/*Cria uma arvore com os parametros passados
 * inputs: o ponteiro para um Caractere, um ponteiro para se por a esquerda e a direita da arvore criada
 * output: o ponteiro para uma arvore inicializada com os paramentros passados
 * pre-condicao: a estrutura Caractere ter sido devidamente inicializada, e os ponteiros para a esquerda e direita tambem inicializados
 * pos-condicao: a arvore foi devidamente alocada na heap
*/
Arv* criaArvore(Caractere* ch, Arv* esq, Arv* dir);

/*Retorna se a arvore eh vazia ou nao
 * inputs: o ponteiro para estrutura Arv
 * output: o valor booleano da expressao
 * pre-condicao: a estrutura Arv ter sido devidamente inicializada
 * pos-condicao: nenhuma
*/
int arvoreVazia(Arv* arvore);

/*Retorna a estrutura Caractere presente dentro de uma estrutura arvore
 * inputs: o ponteiro para estrutura Arv
 * output: o ponteiro para a estrutura Caractere
 * pre-condicao: a estrutura Arv ter sido devidamente inicializada
 * pos-condicao: nenhuma
*/
Caractere* retornaCaractere(Arv* a);

/*Verifica se um caractere pertence na arvore alvo
 * inputs: a arvore alvo e o caractere desejado
 * output: 1 caso o caractere pertenca a arvore alvo e 0 caso contrario
 * pre-condicao: a arvore deve ter sido alocada adequadamente e o caractere deve pertencer a tebela ascii com indice entre 0 e 127
 * pos-condicao: 1 eh retornado caso o caractere pertence na arvore e 0 caso contrario
*/
int pertenceArvore(Arv* arvore, Caractere* ch);


/*Cria um vetor de bitmaps contendo o caminho para cada caractere (cada caractere eh um indice do vetor) a partir da leitura da arvore alvo passada
 * inputs: a arvore alvo, o vetor de bitmaps pre-inicializado e um caminho inicial contendo nenhum bit
 * output: nenhum
 * pre-condicao: a arvore e o vetor de bitmaps devem existir e terem sido alocados adequadamente
 * pos-condicao: o vetor contendo um bitmap representativo do caminho para cada caractere eh preenchido
*/
void caminho(Arv* arvore, bitmap** tabela, bitmap* path);


/*Cria uma arvore a partir da leitura de um arquivo compactado
 * inputs: o ponteiro para o arquivo alvo
 * output: a arvore criada a partir da leitura do arquivo alvo
 * pre-condicao: o arquivo deve ser do tipo .comp e criado a partir da execucao do Compila
 * pos-condicao: a arvore criada a partir do arquivo alvo eh retornada
*/
Arv* criaArvoreCompactada(FILE* fp);


/*Calcula a quantidade de nos folha da arvore passada
 * inputs: a arvore alvo
 * output: o numero de nos folha da arvore alvo
 * pre-condicao: a arvore existir e ter sido alocada corretamente
 * pos-condicao: o numero de folhas da arvore alvo eh retornado
*/
int folhas (Arv* arvore);


/*Retorna o numero de ocorrencias do caractere passado na arvore passada
 * inputs: o caractere e a arvore desejada
 * output: o numero de ocorrencias do caractere na arvore passada
 * pre-condicao: a arvore existir e ter sido alocada adequadamente e o caractere deve qualquer caractere da tabela ascii entre 0 e 127
 * pos-condicao: o numero de ocorrencias do caractere na arvore passada eh retornado
*/
int ocorrencias (Arv* arvore, Caractere* ch);


/*Retorna a altura da arvore binaria passada
 * inputs: a arvore que se deseja calcular a altura
 * output: um inteiro que representa a altura da arvore
 * pre-condicao: a arvore deve existir e ter sido alocada adequadamente
 * pos-condicao: a altura da arvore eh calculada e eh retornada pela funcao
*/
int altura (Arv* arvore);


/*Imprime a arvore passada no terminal
 * inputs: a arvore a ser impressa
 * output: nenhum
 * pre-condicao: a arvore existir e ter sido alocada adequadamente
 * pos-condicao: a arvore passada eh impressa no terminal
*/
void imprimeArvore(Arv* arvore);


/*Imprime a arvore passada no arquivo binario apontado pelo ponteiro de arquivo passado
 * inputs: o ponteiro para o arquivo e a arvore a ser impressa
 * output: nenhum
 * pre-condicao: o ponteiro de arquivo apontar para um arquivo valido e a arvore existir e ter sido alocada corretamente
 * pos-condicao: a arvore passada eh impressa no arquivo apontado pelo poteiro de arquivo tambem passado
*/
void imprimeArvoreArquivo(FILE* fp, Arv* arvore);


/*Libera a arvore passada, todas as suas sub-arvores e o conteudo de cada no
 * inputs: a estrutura arvore que se deseja liberar
 * output: retorna o ponteiro do endereço da arvore liberada
 * pre-condicao: a arvore passada deve existir e ter sido alocada adequadamente
 * pos-condicao: a arvore passada e todas as suas sub-arvores sao liberadas
*/
Arv* liberaArvore(Arv* arvore);

#endif