OUTPUT = choo-choo

IDIR = include
SDIR = src
ODIR = src/obj
LDIR = lib

LIBS = -lGL -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -pthread -DSPDLOG_COMPILED_LIB

CC = g++
CFLAGS = -std=c++17 -I$(IDIR)

_DEPS = Game Scene Unit Sentinel Move Attack Shape GUI Attribute Point
_OBJ = main $(_DEPS)

DEPS = $(patsubst %,$(IDIR)/%.hpp,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%.o,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUTPUT): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ ./choo-choo ./logs/*.txt
