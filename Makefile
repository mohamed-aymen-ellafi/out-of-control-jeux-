menu:mainMenu.o menu.o
	gcc mainMenu.o menu.o -o menu -g  -lSDL -lSDL_image -lSDL_mixer
mainMenu.o:mainMenu.c 
	gcc -c mainMenu.c -g 
menu.o:menu.c
	gcc -c menu.c -g





