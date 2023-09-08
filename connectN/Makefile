connectn.out: main.o board.o setup.o play_game.o win.o input_validation.o
	gcc -g -Wall -Werror -o connectn.out main.o board.o setup.o play_game.o win.o input_validation.o

main.o: main.c board.h setup.h
	gcc -g -Wall -Werror -c main.c 

board.o: board.c 
	gcc -g -Wall -Werror -c board.c 

setup.o: setup.c board.h
	gcc -g -Wall -Werror -c setup.c

play_game.o: play_game.c board.h setup.h win.c
	gcc -g -Wall -Werror -c play_game.c

win.o: win.c play_game.h board.h setup.h
	gcc -g -Wall -Werror -c win.c

input_validation.o: input_validation.c
	gcc -g -Wall -Werror -c input_validation.c

clean:
	rm -f *.o *.out