
SRC     = $(wildcard src/*.c)
SRC    += $(wildcard deps/*/*.c)
OBJS    = $(SRC:.c=.o)
CFLAGS  = -std=c99 -Ideps -Isrc
CFLAGS += -Wall -Wextra

test: test.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	./$@

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	rm -f $(OBJS) test

.PHONY: test
