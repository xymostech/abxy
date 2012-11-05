CC=clang++

CFLAGS=-g -I./ -Igl3w/include -std=c++11 -stdlib=libc++ \
       -Wall `freetype-config --cflags`
LIBS=-lglfw -framework OpenGL -framework Cocoa -lpng \
     `freetype-config --libs`

headers=$(shell find gamelib -type f -name '*.hpp')\
	$(shell find gamelib -type f -name '*.inl')

examples=Test Pong
examplefiles=$(addprefix build/, $(examples))

all: $(examplefiles)
	cp -r res/* build/

build/%: examples/%.cpp $(headers)
	$(CC) -o $@ $< $(CFLAGS) $(LIBS)

clean:
	rm -rf build/*
