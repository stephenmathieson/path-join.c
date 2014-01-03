
SRC     = $(wildcard src/*.c)
SRC    += $(wildcard deps/*/*.c)
CFLAGS  = -std=c99 -Ideps -Isrc
CFLAGS += -Wall -Wextra

test: test.c $(SRC)
	$(CC) $(CFLAGS) $^ -o $@
	./$@

.PHONY: test
