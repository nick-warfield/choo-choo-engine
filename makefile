IDIR = include
SDIR = src
ODIR = src/obj
LDIR = lib

LIBS = 

CC = g++
CFLAGS = -std=c++17 -I$(IDIR) -I$(SDIR)

_DEPS = Scene.hpp SceneTree.hpp
_OBJ = main.o Scene.o SceneTree.o

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

choo-choo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
