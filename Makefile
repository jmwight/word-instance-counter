ARGS = -g3
OBJ = main.o getch.o getword.o

word-instance-counter: $(OBJ)
	cc $(ARGS) -o word-instance-counter $(OBJ)

main.o: main.c getword.h
	cc $(ARGS) -c main.c

getword.o: getword.c getword.h getch.h
	cc $(ARGS) -c getword.c

getch.o: getch.c
	cc $(ARGS) -c getch.c

.PHONY: clean
clean:
	rm -rf $(OBJ) word-instance-counter
