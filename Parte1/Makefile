CXX=g++
CXXFLAGS=-std=c++14 -O3 -ggdb -Wall -w -lm -g

SRCDIR=src
OBJDIR=obj

# Lista de archivos fuente
SRCS=$(wildcard $(SRCDIR)/*.cpp)

# Lista de archivos objeto generados a partir de los archivos fuente
OBJS=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Archivo fuente principal
MAIN_SRC=$(SRCDIR)/main.cpp

# Archivo objeto principal
MAIN_OBJ=$(OBJDIR)/main.o

TARGET=app

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

# Regla de compilación para los archivos fuente en src/
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET)
	rm -f $(OBJDIR)/*.o
	rm -f *~

all: clean $(TARGET)
