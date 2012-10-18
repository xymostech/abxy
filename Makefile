CC=clang++

CFLAGS=-g -I./ -Igl3w/include -std=c++11 -stdlib=libc++ -Wall
LIBS=-Lgl3w/lib -lglfw -framework OpenGL -framework Cocoa -lpng

headers=$(shell find gamelib/ -type f -name '*.hpp')

examples=Test
examplefiles=$(addprefix build/, $(examples))

all: $(examplefiles)
	cp -r res/* build/

build/%: examples/%.cpp $(headers)
	$(CC) -o $@ $< $(CFLAGS) $(LIBS)

clean:
	rm -rf build/*
