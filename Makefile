CFLAGS=-Wall -Werror

.PHONY: clean run-imageprocessing run-interactive

run-imageprocessing: imageprocessing
	./imageprocessing

run-interactive: interactive
	./interactive

interactive: interactive.c imageprocessing.c bmp.c
	gcc interactive.c imageprocessing.c bmp.c $(CFLAGS) -o interactive

imageprocessing: imageprocessing.c
	gcc imageprocessing.c $(CFLAGS) -o imageprocessing

clean:
	rm -f imageprocessing interactive
