#include "Descompacta.h"

int main(int argc, char** argv)
{
    FILE* fp = fopen(argv[1],"rb");

    Arv* a = criaArvoreCompactada(fp);
    descompacta(fp, argv[1], a);

    liberaArvore(a);

    fclose(fp);

    return 0;
}