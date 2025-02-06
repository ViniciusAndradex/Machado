#include <stdio.h>
#include "modules/file.h"

float bet_value() {
    FILE *rfile;
    float bet;

    rfile = fopen("file/tmp/bet.txt", "r");
    if (rfile == NULL) {
        printf("Erro ao abrir o arquivo bet.txt.\n");
        return 0.5; 
    }

    if (fscanf(rfile, "%f", &bet) != 1) {
        printf("Erro ao ler o valor do arquivo.\n");
        fclose(rfile);
        return 0.5; 
    }

    fclose(rfile);

    printf("Valor da aposta lido: %.2f\n", bet);

    return bet; 
}