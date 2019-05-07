prog:main.o AI.o
	gcc main.o AI.o -o prog -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL
main.o:main.c
	gcc -c main.c
AI.o:AI.c
	gcc -c AI.c