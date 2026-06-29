# Makefile - Lab 5
# IE-0117 - I-2026

CC     = gcc
CFLAGS = -Wall -Wextra
TARGET = labo5
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

.PHONY: all clean run

all: $(TARGET)

$(TARGET): main.c funciones.c funciones.h
	$(CC) $(CFLAGS) main.c funciones.c -o $(TARGET)
	$(VALGRIND) ./$(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
