IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj

LIBS=-lsodium

_DEPS = declarations.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = filterArgv.o generateRandomChar.o interpreters.o main.o print.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sogen: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 