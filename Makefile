CC = gcc
ECHO = echo
RM = rm -f

CFLAGS = -Wall -Werror -ggdb
LDFLAGS = -lncurses

BIN = omc
OBJS = one_among_many.o map.o

all: $(BIN) etags

$(BIN): $(OBJS)
	@$(ECHO) Linking $@
	@$(CC) $^ -o $@ $(LDFLAGS)

-include $(OBJS:.o=.d)

%.o: %.c
	@$(ECHO) Compiling $<
	@$(CC) $(CFLAGS) -MMD -MF $*.d -c $<

.PHONY: clean clobber etags

clean:
	@$(ECHO) Removing all generated files
	@$(RM) *.o $(BIN) *.d TAGS core vgcore.*

clobber: clean
	@$(ECHO) Removing backup files
	@$(RM) *~ \#*

etags:
	@$(ECHO) Updating TAGS
	@etags *.[ch]
