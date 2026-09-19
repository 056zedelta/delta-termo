#define DICIONARIO_H

#include "jogo.h"

#define MAX_PALAVRAS 6000

typedef struct {
    char palavras[MAX_PALAVRAS][MAX_LENGTH + 1];
    int total;
} Dicionario;

int dicionario_carregar(Dicionario *dicionario, const char *caminho);
int dicionario_contem(const Dicionario *dicionario, const char *palavra);
const char *dicionario_escolher_aleatoria(const Dicionario *dicionario);