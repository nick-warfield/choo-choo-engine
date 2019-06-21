OUTPUT = choo-choo

IDIR = include
SDIR = src
ODIR = src/obj
LDIR = lib

LIBS = -lGL -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -pthread -DSPDLOG_COMPILED_LIB

CC = g++
CFLAGS = -std=c++17 -I$(IDIR)

_DEPS = Game.hpp Scene.hpp Unit.hpp Sentinel.hpp GUI.hpp Attribute.hpp
_OBJ = main.o Game.o Scene.o Unit.o Sentinel.o GUI.o Attribute.o

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUTPUT): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ ./choo-choo ./logs/*.txt
