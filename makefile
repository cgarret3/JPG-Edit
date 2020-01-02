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

_OBJS = jpg_edit.o test_jpg_edit.o
OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))

EXES = test_jpg_edit


$(ODIR)/%.o : $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXES) : $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY : clean open_files

clean :
	rm -f $(ODIR)/*.o $(TEST)/*.o $(EXES)

open_files :
	atom -n $(IDIR)/jpg_edit.h $(SDIR)/jpg_edit.c $(SDIR)/test_jpg_edit.c
