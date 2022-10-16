#include <stdlib.h>

#include "arvore.h"

struct caractere_st{
    int crt;
    int peso;
};

struct arvore_st{
    Caractere* inf;
    Arv* esq;
    Arv* dir;
};

Caractere* inicCaractere(int crt, int peso){
    Caractere* ch = (Caractere*) malloc(sizeof(Caractere));
    ch->crt = crt;
    ch->peso = peso;

    return ch;
}

int retornaPeso(Caractere* ch){
    return ch->peso;
}

int retornaPesoArvore(Arv* a){
    return a->inf->peso;
}

int retornaCrtArvore(Arv* a){
    return a->inf->crt;
}

int retornaCrt(Caractere* ch){
    return ch->crt;
}

Arv* retornaRamo(Arv* a, int direcao){
    if(direcao == 0) return a->esq;
    else if(direcao == 1) return a->dir;
    else return NULL;
}

Arv* criaArvoreVazia(){
    return NULL;
}

Arv* criaArvore(Caractere* caractere, Arv* esq, Arv* dir){
    Arv* arvore = (Arv*) malloc(sizeof(Arv));

    arvore->inf = caractere;
    arvore->esq = esq;
    arvore->dir = dir;

    return arvore;
}

int arvoreVazia(Arv* arvore){
    return arvore==NULL;
}

Caractere* retornaCaractere(Arv* a){
    return a->inf;
}

int pertenceArvore(Arv* arvore, Caractere* caractere) {
    if(arvoreVazia(arvore))
        return 0;
    else
        return arvore->inf->crt == caractere->crt || pertenceArvore(arvore->esq, caractere) || pertenceArvore(arvore->dir, caractere);
}


void caminho(Arv* arvore, bitmap** tabela, bitmap* path) {
    if(arvore == NULL) return;
    if(arvore->inf->crt != 0){
        bitmap* cpy = bitmapCopia(path);
        tabela[arvore->inf->crt] = cpy;
        return;
    }
    
    bitmap* cpy2 = bitmapCopia(path);
    bitmapAppendLeastSignificantBit(cpy2,0);
    caminho(arvore->esq, tabela, cpy2);

    bitmap* cpy3 = bitmapCopia(path);
    bitmapAppendLeastSignificantBit(cpy3,1);
    caminho(arvore->dir, tabela, cpy3);

    bitmapLibera(cpy2);
    bitmapLibera(cpy3);    
}

Arv* criaArvoreCompactada(FILE* fp) {
    char c1, c2;
    
    fscanf(fp, "%c%c", &c1, &c2);

    if(c1 == '0' && c2 == '0') {
        Caractere* char1 = inicCaractere(0, 0);
        Arv* arv1 = criaArvore(char1, criaArvoreVazia(), criaArvoreVazia());

        arv1->esq = criaArvoreCompactada(fp);
        arv1->dir = criaArvoreCompactada(fp);

        return arv1;
    }
    else {
        Caractere* char2 = inicCaractere(c2, 1);
        Arv* arv2 = criaArvore(char2, criaArvoreVazia(), criaArvoreVazia());

        return arv2;
    }
}

int folhas (Arv* arvore){
    if(!arvoreVazia(arvore)){
        if(arvoreVazia(arvore->esq) && arvoreVazia(arvore->dir)) return 1;
        return folhas(arvore->esq) + folhas(arvore->dir);
    }
    return 0;
}

int ocorrencias (Arv* arvore, Caractere* caractere){
    if(!(arvoreVazia(arvore))){
        return ocorrencias(arvore->esq, caractere) + ocorrencias(arvore->dir, caractere) + (arvore->inf->crt == caractere->crt);
    }
    return 0;
}

static int maior(int a, int b){
    return (a>b) ? a : b;
}

int altura (Arv* arvore){
    if(arvoreVazia(arvore)) return -1;
    else return 1+ maior(altura(arvore->esq), altura(arvore->dir));
}

void imprimeArvore(Arv* arvore) {
    if(arvore != NULL) {
        printf("<%c(%d)", arvore->inf->crt, arvore->inf->peso);
        imprimeArvore(arvore->esq);
        imprimeArvore(arvore->dir);
        printf(">");
    }
    else
        printf("<>");
}

void imprimeArvoreArquivo(FILE* fp, Arv* arvore) {

    if(arvore != NULL) {
        
        if(arvore->inf->crt == 0) {
            fprintf(fp, "00");
        }
        else {
            fprintf(fp, "1%c", arvore->inf->crt);
        }
        
        imprimeArvoreArquivo(fp, arvore->esq);
        imprimeArvoreArquivo(fp, arvore->dir);
    }
}

Arv* liberaArvore(Arv* arvore){
    if(!arvoreVazia(arvore)){
        liberaArvore(arvore->esq);
        liberaArvore(arvore->dir);
        free(arvore->inf);
        free(arvore);
    }
    return NULL;
}