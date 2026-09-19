CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
CPPFLAGS = -Iinclude

TARGET = build/main
OBJ = build/main.o build/jogo.o build/dicionario.o

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

build/main.o: src/main.c include/jogo.h include/dicionario.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c src/main.c -o build/main.o

build/jogo.o: src/jogo.c include/jogo.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c src/jogo.c -o build/jogo.o

build/dicionario.o: src/dicionario.c include/dicionario.h include/jogo.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c src/dicionario.c -o build/dicionario.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)