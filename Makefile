CC=clang++

CFLAGS=-g -I./ -Igl3w/include -std=c++11 -stdlib=libc++ \
       -Wall `freetype-config --cflags`
LIBS=-lglfw -framework OpenGL -framework Cocoa -lpng \
     `freetype-config --libs`

headers=$(shell find gamelib -type f -name '*.hpp')\
	$(shell find gamelib -type f -name '*.inl')

examples=Random Pong
examplefiles=$(addprefix build/, $(examples))

.PHONY: all res clean test

all: $(examplefiles) res test

res:
	@echo "Copying resources"
	@cp -r res/* build/

build/%: examples/%.cpp $(headers)
	@echo "Compiling example $@"
	@$(CC) -o $@ $< $(CFLAGS) $(LIBS)

clean:
	rm -rf build/*

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
