#include "Compacta.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
    FILE* fp;

    fp = fopen(argv[1],"rb");

    int* vet = retornaOcorrencias(fp);

    Arv** a = criaVetorArvores(vet);
    
    a = huffman(a);

    bitmap** tabela = criaTabela(a[0]);

    compacta(argv[1], tabela, a[0]);

    for(int i = 0; i<128; i++){
        liberaArvore(a[i]);
    }

    for(int i = 0; i<128; i++){
        if(tabela[i] != NULL){
            bitmapLibera(tabela[i]);
        }
    }

    free(tabela);
    free(a);
    free(vet);
    fclose(fp); 

    return 0;
}