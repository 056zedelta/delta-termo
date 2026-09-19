#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#include <jogo.h>
#include "dicionario.h"

int main(void) {
    char palavra[32];

    Dicionario dicionario;

    if (!dicionario_carregar(&dicionario, "data/palavras.csv")) {
        return 1;
    }   

    srand((unsigned)time(NULL));

    const char *wordle = dicionario_escolher_aleatoria(&dicionario);
    
    for (int tentativa = 1; tentativa <= 6; tentativa++) {
        printf("Tentativa %d/6: ", tentativa);
        
        fgets(palavra, sizeof(palavra), stdin);

        palavra[strcspn(palavra, "\r\n")] = '\0';
        para_upper(palavra);

        if (!valida_palavra(palavra)) {
            printf("A palavra tem de ter 5 letras.\n");
            tentativa--;
            continue;
        }

        if (!dicionario_contem(&dicionario, palavra)) {
            printf("Essa palavra não existe na lista.\n");
            tentativa--;
            continue;
        }

        mostrar_resultado(palavra, wordle);

        if (strcmp(palavra, wordle) == 0) {
            printf("Parabéns! Acertaste na palavra!\n");
            return 0;
        }
    }

    printf("Não acertaste. A palavra era %s.\n", wordle);
    return 0;
}
