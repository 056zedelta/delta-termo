#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include <jogo.h>

//retorna 0 ou 1 consoante a palavra tenha 5 letras ou não
int valida_palavra(const char *palavra){
    return strlen(palavra) == MAX_LENGTH;
}

void mostrar_resultado(const char *tentativa, const char *secreta) {
    int resultado[MAX_LENGTH] = {0};
    int usada[MAX_LENGTH] = {0};

    // Primeiro: letras na posição certa
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (tentativa[i] == secreta[i]) {
            resultado[i] = 2;
            usada[i] = 1;
        }
    }

    // Depois: letras existentes noutra posição
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (resultado[i] == 2) {
            continue;
        }

        for (int j = 0; j < MAX_LENGTH; j++) {
            if (!usada[j] && tentativa[i] == secreta[j]) {
                resultado[i] = 1;
                usada[j] = 1;
                break;
            }
        }
    }

    // Mostrar o resultado
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (resultado[i] == 2) {
            printf("[%c]", tentativa[i]);
        } else if (resultado[i] == 1) {
            printf("(%c)", tentativa[i]);
        } else {
            printf(" %c ", tentativa[i]);
        }
    }

    printf("\n");
}

//transforma os caracteres em maiusculas
void para_upper (char *palavra){
    for(int i = 0; palavra[i] != '\0'; i++){
        //toupper so aceita unsigned char
        palavra[i] = toupper((unsigned char)palavra[i]);
    }
}