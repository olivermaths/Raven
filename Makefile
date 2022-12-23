CC = clang++
CFLAGS = -Wall -Wextra -Wunreachable-code -Wmissing-field-initializers -pedantic
INCLUDES = -I./src/


TEST_PROJECT_NAME = hesse

.PHONY: test.o


build.o: src/**/*.cpp src/*.cpp 
	$(CC) -std=c++20 -Wall $(INCLUDES) src/**/*.cpp src/*.cpp -o build/raven



test.o: build.o
	build/raven create test/hesse
	build/raven create --module test/hesse/src/testone
	build/raven create --module test/hesse/src/testtwo
	build/raven create --mod    test/testthree


clean:
	rm build/raven

test: build.o test.o clean
	rm -r test/hesse
	rm -r build/testthree
	rm -r testthree
