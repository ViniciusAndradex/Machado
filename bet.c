#include <stdio.h>

float bet_value() {
    FILE *file;
    float bet;

    file = fopen("file/tmp/bet.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo bet.txt.\n");
        return 0.5; 
    }

    if (fscanf(file, "%f", &bet) != 1) {
        printf("Erro ao ler o valor do arquivo.\n");
        fclose(file);
        return 0.5; 
    }

    fclose(file);

    // 4. Exibir o valor lido
    printf("Valor da aposta lido: %.2f\n", bet);

    return bet; // Programa encerrado com sucesso
}