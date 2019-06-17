OUTPUT = choo-choo

IDIR = include
SDIR = src
ODIR = src/obj
LDIR = lib

LIBS = -lGL -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -DSPDLOG_COMPILED_LIB

CC = g++
CFLAGS = -std=c++17 -I$(IDIR)

_DEPS = Log.hpp Game.hpp Scene.hpp Sentinel.hpp GUI.hpp
_OBJ = main.o Log.o Game.o Scene.o Sentinel.o GUI.o

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUTPUT): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ ./choo-choo
