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
CFLAGS := -Wall -Wextra -I$(INCDIR) -std=c++17
LDFLAGS := 

# Archivos fuente y objeto
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# ============================
#        REGLAS
# ============================

# Regla por defecto
all: $(BINDIR)/$(TARGET)

# Regla para el ejecutable
$(BINDIR)/$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Regla para compilar archivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para crear el directorio de objetos
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regla para crear el directorio de binarios
$(BINDIR):
	mkdir -p $(BINDIR)

# Regla para limpiar archivos objeto
clean:
	rm -f $(OBJECTS)

# Regla para limpiar todo (archivos objeto y ejecutable)
distclean: clean
	rm -f $(BINDIR)/$(TARGET)

# Regla para mostrar dependencias (opcional)
# Dependencias automáticas para los archivos objeto
# Para utilizarlas, necesitas generar archivos .d durante la compilación
# Esta sección está comentada y requiere ajustes adicionales si se desea usar
# -include $(OBJECTS:.o=.d)

# ============================
#        .PHONY
# ============================

.PHONY: all clean distclean

