#MAKEFILE

all: obj/lib/libply.a bin/Test

bin/Test: obj/main.o obj/scene.o obj/camera.o obj/axis.o obj/stuff.o
	g++ $^ -o $@ -Lobj/lib -lGL -lglut -lGLU -lply

obj/lib/libply.a: obj/lib/ply.o
	ar rc $@ $^
	ranlib $@

obj/lib/ply.o: lib/ply/ply.c lib/ply/ply.h
	gcc -c $< -o $@

obj/main.o: src/main.cc 
	g++ -Werror -Wall -g -Iinclude -Ilib/ply -c $< -o $@ 

obj/scene.o: src/scene.cc 
	g++ -Werror -Wall -g -Iinclude -Ilib/ply -c $< -o $@ 

obj/camera.o: src/camera.cc 
	g++ -Werror -Wall -g -Iinclude -Ilib/ply -c $< -o $@ 

obj/axis.o: src/axis.cc 
	g++ -Werror -Wall -g -Iinclude -Ilib/ply -c $< -o $@ 


obj/stuff.o: src/stuff.cc 
	g++ -Werror -Wall -g -Iinclude -Ilib/ply -c $< -o $@ 



clear: 
	rm obj/*.o obj/lib/*.o bin/*
