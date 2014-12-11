#MAKEFILE

all: folders bin/Test

bin/Test: obj/main.o obj/scene.o obj/camera.o obj/axis.o obj/stuff.o
	g++ $^ -o $@ -Lobj/lib -lGL -lglut -lGLU 

obj/main.o: src/main.cc 
	g++ -Werror -Wall -g -Iinclude  -c $< -o $@ 

obj/scene.o: src/scene.cc 
	g++ -Werror -Wall -g -Iinclude  -c $< -o $@ 

obj/camera.o: src/camera.cc 
	g++ -Werror -Wall -g -Iinclude  -c $< -o $@ 

obj/axis.o: src/axis.cc 
	g++ -Werror -Wall -g -Iinclude  -c $< -o $@ 

obj/stuff.o: src/stuff.cc 
	g++ -Werror -Wall -g -Iinclude  -c $< -o $@ 

folders:
	mkdir -p bin obj obj/lib

clear: 
	rm obj/*.o obj/lib/*.o bin/*
