#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dicionario.h"

int dicionario_carregar(Dicionario *dicionario, const char *caminho) {
    FILE *ficheiro = fopen(caminho, "r");
    char linha[32];

    dicionario->total = 0;

    if (ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro %s\n", caminho);
        return 0;
    }

    while (fgets(linha, sizeof(linha), ficheiro) != NULL &&
           dicionario->total < MAX_PALAVRAS) {

        linha[strcspn(linha, "\r\n")] = '\0';

        if (valida_palavra(linha)) {
            strcpy(dicionario->palavras[dicionario->total], linha);
            dicionario->total++;
        }
    }

    fclose(ficheiro);
    return dicionario->total > 0;
}

int dicionario_contem(const Dicionario *dicionario, const char *palavra) {
    for (int i = 0; i < dicionario->total; i++) {
        if (strcmp(dicionario->palavras[i], palavra) == 0) {
            return 1;
        }
    }

    return 0;
}

const char *dicionario_escolher_aleatoria(const Dicionario *dicionario) {
    if (dicionario->total == 0) {
        return NULL;
    }

    return dicionario->palavras[rand() % dicionario->total];
}