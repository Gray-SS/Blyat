CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

#Source directory path
SRCDIR = src
#Include directory path
INCLUDEDIR = include
#Build directory path
BUILDDIR = build
TARGET = blyatc

SRCS = $(SRCDIR)/main.c \
	   $(SRCDIR)/syntax.c \
	   $(SRCDIR)/view.c \
	   $(SRCDIR)/file.c \
	   $(SRCDIR)/context.c 
	   
OBJS = $(SRCS:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)
	rm -rf ${TARGET}

valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./$(TARGET)

.PHONY: all clean valgrind