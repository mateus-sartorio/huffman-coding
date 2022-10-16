#include <string.h>

#include "Descompacta.h"

#define MAT 1000

void descompacta(FILE* fp, char* arquivo, Arv* arvore){
    char saida[MAT] = "./Saida/";
    char nomeArquivo[MAT];
    char txt[] = ".txt";

    sscanf(arquivo, "%[^.]", nomeArquivo);
    strcat(nomeArquivo,txt);
    strcat(saida, nomeArquivo);
    
    FILE* fdes = fopen(saida, "w");

    bitmap* bm = bitmapInit(16);
    Arv* arvAux = arvore;

    unsigned char c;

    while(!feof(fp)){
        int i = 0;
        fscanf(fp, "%c", &c);

        if(feof(fp)) {
            break;
        }
        bitmapSetByte(bm,c);

        while(1){
            if(retornaCrtArvore(arvAux) != 0){
                if(retornaCrtArvore(arvAux) == '\a'){
                    bitmapLibera(bm);
                    fclose(fdes);
                    return;
                }
                fprintf(fdes, "%c", retornaCrtArvore(arvAux));
                arvAux = arvore;
            }

            if(i >= bitmapGetLength(bm)){
                bm = bitmapLimpa(bm);
                i = 0;
                fscanf(fp, "%c", &c);
                bitmapSetByte(bm,c);
            }

            if(bitmapGetBit(bm, i) == 0){
                arvAux = retornaRamo(arvAux , 0);
                i++;
            }else if(bitmapGetBit(bm, i) == 1){
                arvAux = retornaRamo(arvAux , 1);
                i++;
            }
        }
    }

    bitmapLibera(bm);
    fclose(fdes);
}