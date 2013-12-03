
test: test.c src/*.c deps/*.c
	$(CC) -std=c99 $^ -o $@ -Isrc -Ideps
	./test

.PHONY: test
