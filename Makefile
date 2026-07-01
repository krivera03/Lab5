# Makefile - Lab 5
# IE-0117 - I-2026

CC     = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = labo5
VALGRIND = -Iinclude -g -O0 
SRC_DIR = src
COMPLETO = $(SRC_DIR)/main.c $(SRC_DIR)/dinarr.c $(SRC_DIR)/lista.c $(SRC_DIR)/dlista.c $(SRC_DIR)/stackarr.c
.PHONY: all clean run

all: $(TARGET)

$(TARGET):  
	$(CC) $(CFLAGS)  $(COMPLETO) -o $(TARGET)

run: all
	./$(TARGET)
debug: clean
	$(CC) $(VALGRIND) $(COMPLETO) -o $(TARGET)

valgrind: debug
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f $(TARGET)
