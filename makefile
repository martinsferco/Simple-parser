# Makefile para trabajo final 



FLAGS = -Wall -Wextra -Werror -std=c99

programa: main.o glist.o contacto.o
	$(CC) -o $@ $^ $(FLAGS)

main.o: main.c glist.h contacto.h
	$(CC) -c $< $(FLAGS)

glist.o: glist.c glist.h
	$(CC) -c $< $(FLAGS)

contacto.o: contacto.c contacto.h
	$(CC) -c $< $(FLAGS)

clean:
	rm *.o
	rm programa

.PHONY = clean
