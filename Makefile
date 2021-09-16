input: input.c cmdline.c cmdline.h
	gcc input.c cmdline.c -o input -lreadline
cmdline.c cmdline.h: gengetopt.ggo
	gengetopt <gengetopt.ggo
install: input
	mv input /usr/bin/input
clean:
	rm input
