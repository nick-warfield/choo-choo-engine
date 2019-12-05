OUTPUT = choo-choo

IDIR = include
SDIR = src
ODIR = src/obj
LDIR = lib

LIBS = -lGL -lsfml-graphics -lsfml-window -lsfml-audio \
	   -lsfml-network -lsfml-system -pthread -lstdc++fs

CC = g++
CFLAGS = -std=c++17 -I$(IDIR)

_DEPS = Game GameException GameObject Attribute \
		Event Listener \
		Sprite \
		Shape Point \
		PhalanxDemo TerrainDemo

_OBJ = main $(_DEPS)

DEPS = $(patsubst %,$(IDIR)/%.hpp,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%.o,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUTPUT): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	trash $(ODIR)/*.o *~ core $(INCDIR)/*~ ./choo-choo ./logs/*.txt
