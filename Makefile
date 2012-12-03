CC=clang++

CFLAGS=-g \
       -I./ \
       -std=c++11 -stdlib=libc++ \
       -Wall `freetype-config --cflags`
LIBS=-lglfw -framework OpenGL -framework Cocoa \
     -lpng \
     `freetype-config --libs` \
      -lao -Ldependencies/libvorbis/lib/.libs -lvorbis -lvorbisfile

headers=$(shell find gamelib -type f -name '*.hpp') \
	$(shell find gamelib -type f -name '*.inl')

examples=Random Pong
examplefiles=$(addprefix build/, $(examples))

.PHONY: all libs res clean test docs

all: libs $(examplefiles) res test

.PHONY: libvorbis

libs: libvorbis

VORBISLIB=dependencies/libvorbis/lib/.libs/libvorbis.a

libvorbis: $(VORBISLIB)

$(VORBISLIB):
	@echo "Configuring libvorbis"
	@cd dependencies/libvorbis && ./configure > /dev/null
	@echo "Compiling libvorbis"
	@$(MAKE) -C dependencies/libvorbis > /dev/null 2>&1

res:
	@echo "Copying resources"
	@cp -r res/* build/

build/%: examples/%.cpp $(headers)
	@echo "Compiling example $@"
	@$(CC) -o $@ $< $(CFLAGS) $(LIBS)

clean:
	@echo "Cleaning build"
	@rm -rf build/*
	@echo "Cleaning tests/build"
	@rm -rf tests/build/*

UNITTESTLIB=dependencies/UnitTest++/libUnitTest++.a

TESTCFLAGS=-Idependencies/UnitTest++/src $(CFLAGS)
TESTLIBS=$(UNITTESTLIB) $(LIBS)

test: tests/build/test
	@echo "Running tests"
	@cd tests/build && ./test

testheaders=$(shell find tests -type f -name '*.hpp')

tests/build/test: tests/main.cpp $(testheaders) $(UNITTESTLIB) $(headers)
	@echo "Compiling tests"
	@$(CC) -o $@ $< $(TESTCFLAGS) $(TESTLIBS)

$(UNITTESTLIB):
	@echo "Compiling UnitTest++ library"
	@$(MAKE) -C dependencies/UnitTest++/

docs:
	@echo "Building docs"
	@doxygen Doxyfile
