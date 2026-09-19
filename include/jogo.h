#define JOGO_H

#define MAX_LENGTH 5

int valida_palavra(const char *palavra);
void mostrar_resultado(const char *tentativa, const char *secreta);
void para_upper(char *palavra);