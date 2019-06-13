IDIR = include
SDIR = src
ODIR = src/obj
LDIR = lib

LIBS = -lGL -lGLEW -lGLU -lglut -lglfw

CC = g++
CFLAGS = -std=c++17 -I$(IDIR)

_DEPS = Scene.hpp SceneTree.hpp GUI.hpp
_OBJ = main.o Scene.o SceneTree.o GUI.o

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

choo-choo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ ./choo-choo
