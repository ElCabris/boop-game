# ============================
#        VARIABLES
# ============================

# Directorios
SRCDIR := src
INCDIR := include
OBJDIR := obj
BINDIR := bin

# Nombre del ejecutable
TARGET := boop 

# Compilador y flags
CC := g++
CFLAGS := -Wall -Wextra -I$(INCDIR) -std=c++17 -g
LDFLAGS := 

# Archivos fuente y objeto
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
DEPS := $(OBJECTS:.o=.d)

# ============================
#        REGLAS
# ============================

# Regla por defecto
all: $(BINDIR)/$(TARGET)

# Regla para el ejecutable
$(BINDIR)/$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Regla para compilar archivos objeto y generar archivos de dependencia
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Regla para crear el directorio de objetos
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regla para crear el directorio de binarios
$(BINDIR):
	mkdir -p $(BINDIR)

# Regla para limpiar archivos objeto y de dependencia
clean:
	rm -f $(OBJECTS) $(DEPS)

# Regla para limpiar todo (archivos objeto, de dependencia y ejecutable)
distclean: clean
	rm -f $(BINDIR)/$(TARGET)

# Incluir los archivos de dependencia generados
-include $(DEPS)

# ============================
#        .PHONY
# ============================

.PHONY: all clean distclean

