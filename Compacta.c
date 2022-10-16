#include <stdlib.h>
#include <string.h>

#include "Compacta.h"

#define TAM 128
#define MAT 1000

int* retornaOcorrencias (FILE* fp){
    int* vetor = (int*) calloc(TAM, sizeof(int));
    int c;

    while(1){
        c = fgetc(fp);

        if(c < 0)
            break;

        //putchar(c);
        vetor[c]++;
    }

    vetor[7]++;

    return vetor;
}

static int compara(Arv* a1, Arv* a2) {
    if(a1 == NULL && a2 == NULL)
        return 0;
    else if(a1 == NULL) {
        return 1;
    }
    else if(a2 == NULL)
        return -1;
    else
        return ( retornaPesoArvore(a1) - retornaPesoArvore(a2) );
}

static void organizaVetor(Arv** vetor, int tamanho){
	int aux, i, j;
	for(j = tamanho - 1; j >= 1; j--){
		for(i = 0; i < j; i++){
			if(compara(vetor[i], vetor[i+1]) > 0){
                Arv* temp = vetor[i]; 
                vetor[i] = vetor[i+1]; 
                vetor[i+1] = temp;
            }
        }
    }
}

Arv** criaVetorArvores(int* vetor) {
    Arv** a = (Arv**) calloc(TAM,sizeof(Arv*));
    int n = 0;
    for(int i = 0; i < TAM; i++) {
        if(vetor[i] != 0) {
            Caractere* ch = inicCaractere(i, vetor[i]);
            a[n] = criaArvore(ch, criaArvoreVazia(), criaArvoreVazia());
            n++;
        }
    }

    organizaVetor(a, TAM);

    return a;
}

Arv** huffman(Arv** arvores) {
    if(arvores[0] != NULL && arvores[1] == NULL){
        return arvores;
    }
    
    Arv** arvores2 = (Arv**) calloc(TAM, sizeof(Arv*));
    
    for(int i = 0; i<TAM; i++){
        if(arvores[0] != NULL && arvores[1] != NULL) {
            Caractere* ch = inicCaractere(0, retornaPesoArvore(arvores[0]) + retornaPesoArvore(arvores[1]));

            Arv* tr = criaArvore(ch, arvores[0], arvores[1]);

            arvores[0] = NULL;
            arvores[1] = NULL;

            organizaVetor(arvores, TAM);

            arvores2[i] = tr;
        }
        else {
            arvores2[i] = arvores[0];
            break;
        }        
    }

    organizaVetor(arvores2, TAM);

    free(arvores);

    return huffman(arvores2);
}


bitmap** criaTabela(Arv* arvore) {
    bitmap** tabela = (bitmap**) calloc(128, sizeof(bitmap*));
    bitmap* temp = bitmapInit(altura(arvore)+1);

    caminho(arvore, tabela, temp);

    bitmapLibera(temp);

    return tabela;
}

void compacta(char* arquivo, bitmap** tabela, Arv* arvore) {
    FILE* fl = fopen(arquivo, "rb");

    char nomeArquivo[MAT];
    char comp[] = ".comp";

    bitmap* buffer = bitmapInit(8);

    if(fl == NULL) {
        printf("Falha na abertura do arquivo\n");
        exit(1);
    }

    sscanf(arquivo, "%[^.]", nomeArquivo);
    strcat(nomeArquivo, comp);

    FILE* fe = fopen(nomeArquivo, "ab");

    imprimeArvoreArquivo(fe, arvore);

    while(!feof(fl)){
        char c = fgetc(fl);

        if(feof(fl))
            break;
        
        for(int i = 0; i<bitmapGetLength(tabela[c]); i++){
            bitmapAppendLeastSignificantBit(buffer, bitmapGetBit(tabela[c], i));

            if(bitmapGetLength(buffer) == 8) {
                fprintf(fe, "%c", bitmapGetContents(buffer)[0]);
                buffer = bitmapLimpa(buffer);
            }
        }
    }

    for(int j = 0; j<bitmapGetLength(tabela['\a']); j++){
        bitmapAppendLeastSignificantBit(buffer, bitmapGetBit(tabela['\a'], j));

        if(bitmapGetLength(buffer) == 8) {
            fprintf(fe, "%c", bitmapGetContents(buffer)[0]);
            buffer = bitmapLimpa(buffer);
        }
    }

    while(bitmapGetLength(buffer)%8){
        bitmapAppendLeastSignificantBit(buffer, 0);
    }
    fprintf(fe, "%c", bitmapGetContents(buffer)[0]);
    
    bitmapLibera(buffer);

    fclose(fl);
    fclose(fe);
}

void imprimeVetor(int* vet, int tam) {
    for(int i = 0; i < tam; i++) {
        char c = (char) i;
        printf("vetor[%d]: %d\n", c, vet[i]);
    }
}