all:
	@mv test test.c
	@make -C ..
	gcc -g -I.. -L.. -lft test.c unicode.c ; mv test.c test

run: all
	./a.out
