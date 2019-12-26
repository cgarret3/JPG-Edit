SHELL = /bin/sh

IDIR = include
SDIR = src
ODIR = obj
LDIR = lib

CC = gcc
CFLAGS = -I$(IDIR) -std=c99

_DEPS = jpg_edit.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_SRCS = jpg_edit.c
SRCS = $(patsubst %, $(SDIR)/%, $(_SRCS))

_OBJS = jpg_edit.o
OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))

EXES = test


$(ODIR)/%.o : $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXES) : $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY : clean

clean :
	rm -f $(ODIR)/*.o $(TEST)/*.o $(EXES)
