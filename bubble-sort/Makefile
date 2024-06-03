ALGORITMO = bubble_sort

CC = gcc
LD = gcc

# CFLAGS = -Wall -pipe 
LISTA_DIR = -I../listas_header/
OFLAGS = -c -I/usr/include
LFLAGS = $(CFLAGS) -L/usr/lib/ $(LISTA_DIR) 

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

DEBUG = no
PROFILE = no
PEDANTIC = no
OPTIMIZATION = -O0

ifeq ($(DEBUG), yes)
	CFLAGS += -g
	OPTIMIZATION = -O0
endif

ifeq ($(PROFILE), yes)
	CFLAGS += -pg
endif

CFLAGS += $(OPTIMIZATION)

all: $(ALGORITMO)

$(ALGORITMO): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(ALGORITMO)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(ALGORITMO)

rebuild: clean all

.PHONY : clean
.SILENT : clean