
SRC     = $(wildcard src/*.c)
SRC    += $(wildcard deps/*/*.c)
CFLAGS  = -std=c99 -Ideps -Isrc
CFLAGS += -Wall -Wextra

test: deps
	$(CC) $(CFLAGS) -o $@ test.c $(SRC)
	./$@

deps: package.json
	@clib install

travis:
	git clone https://github.com/clibs/clib.git && \
	  cd clib && \
	  $(MAKE)
	$(MAKE) test

.PHONY: test
