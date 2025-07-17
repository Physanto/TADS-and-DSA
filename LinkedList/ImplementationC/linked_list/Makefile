CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Iinternal

SRC = src/linked_list.c \
      src/singly_linked_list_head_tail.c \
      src/circular_linked_list.c \
      src/doubly_linked_list.c

OBJ = $(SRC:src/%.c=build/%.o)

LIB = lib/liblinkedlist.a

.PHONY: all clean

all: $(LIB)

# Construir la librería
$(LIB): $(OBJ) | lib
	ar rcs $@ $^

# Compilar objetos
build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Crear carpetas necesarias
build:
	mkdir -p build

lib:
	mkdir -p lib

clean:
	rm -rf build lib


