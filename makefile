CC = gcc
CFLAGS = -Wall -Wextra -g

SRCDIR = src
OBJDIR = obj
BINDIR = .

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
EXEC = $(BINDIR)/task

all: $(EXEC)

$(EXEC): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(EXEC)

.PHONY: all clean
