# === CONFIGURACIÓN ===

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Isrc -g
AR = ar
ARFLAGS = rcs

SRCDIR = src
INCDIR = include
OBJDIR = build

SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c, build/%.o, $(SOURCES))

LIBRARY = $(OBJDIR)/liblinkedlist.a
TARGET = main
MAIN = main.c

# === REGLAS ===

all: $(LIBRARY) $(TARGET)

# Crear directorio build si no existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compilar .c en .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Crear la librería estática
$(LIBRARY): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

# Compilar el ejecutable
$(TARGET): $(MAIN) $(LIBRARY)
	$(CC) $(CFLAGS) $< -L$(OBJDIR) -llinkedlist -o $@

# Limpiar todo
clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean
