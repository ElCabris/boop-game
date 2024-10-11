# Directorios
SRCDIR = src
INCDIR = include
OBJDIR = obj

# Compilador y flags
CC = g++
CFLAGS = -c -Wall -I$(INCDIR)

# Archivos fuente y objeto
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Regla para asegurarse de que el directorio de objetos existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regla para compilar los archivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) $< -o $@

# Regla para compilar el ejecutable
all: $(OBJECTS)
	$(CC) $(OBJECTS) -o programa

# Regla para limpiar los archivos objeto
clean:
	rm -f $(OBJECTS)

# Regla para eliminar el ejecutable
distclean: clean
	rm -f programa

# Declarar reglas como .PHONY para evitar conflictos con archivos del mismo nombre
.PHONY: all clean distclean

