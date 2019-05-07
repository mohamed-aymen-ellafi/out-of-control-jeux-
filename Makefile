

game:main.o fnc.o
	gcc main.o fnc.o -o game  -lSDL -lSDL_image -lSDL_mixer -g 

main.o:main.c
	gcc main.c -c  -lSDL -lSDL_image -lSDL_mixer -g


fnc.o:fnc.c
	gcc fnc.c -c -lSDL -lSDL_image -lSDL_mixer -g
