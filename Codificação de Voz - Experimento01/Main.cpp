/******************************************************************
*	Programa dat2raw.c                                             *
*                                                                 *
*  Transforma um arquivo texto de a�dio (-1 <= x < +1) em a�dio   *
*  bin�rio usando  8 bits.                                        *
*                                                                 *
*  Autor: Waslon Terllizzie Ara�jo Lopes                          *
*  Data: 29/01/2017                                               *
*                                                                 *
*  Uso: dat2raw.out entrada.dat saida.raw                         *
******************************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Dependencias/include/inout.h"

#define cnome 100 /* comprimento max de nome de arquivo */

int main(void) {

    FILE* f;
    char amos[cnome], quant[cnome];
    int8_t bytes[1];
    unsigned int t;
    int n_amos;
    double* y;

    /* Abre os arquivos de entrada e sa�da */
    printf("Qual o nome do arquivo original (*.dat)?\n");
    scanf_s("%s", amos);
    y = ler_vetor_arquivo_treino(amos, &n_amos);

     printf("Qual o nome do arquivo de a�dio (*.raw)?\n");
        scanf_s("%s", quant);
        fopen_s(&f, quant, "wb");
  
  /*  else {
        y = ler_vetor_arquivo_treino(argv[1], &n_amos);
        fopen_s(&f, argv[2], "wb");
    }*/

    //for (t = 0; t < n_amos; ++t) {
    //    bytes[0] = INT8_MAX * y[t];
    //    fwrite(bytes, 1, sizeof(int8_t), f);
    //}
    fclose(f);
    return EXIT_SUCCESS;
}