#ifndef DESCOMPACTA_H
#define DESCOMPACTA_H

#include <stdio.h>
#include "arvore.h"

/*Le a partir de um arquivo compactado e o transforma de volta para o original
 * inputs: o ponteiro para o arquivo compactado, a string com o nome do arquivo e a arvore recriada atraves da leitura
 * output: nenhum
 * pre-condicao: o ponteiro do arquivo ter sido previamente inicializado e a arvore ja ter sido recriada pela funcao criaArvoreCompactada()
 * pos-condicao: o arquivo original ser reescrito no caminho ./Saida/nome_arquivo.txt
*/
void descompacta(FILE* fp, char* arquivo, Arv* arvore);

#endif