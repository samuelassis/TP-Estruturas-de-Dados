CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11
EXEC=./tp3

${EXEC}: src/main.cpp lista.o functions.o huffman.o
	${CC} ${CFLAGS} src/main.cpp lista.o functions.o huffman.o -o ${EXEC}

lista.o: src/lista.cpp
	${CC} ${CFLAGS} src/lista.cpp -c -o lista.o

functions.o: src/functions.cpp
	${CC} ${CFLAGS} src/functions.cpp -c -o functions.o

huffman.o: src/huffman.cpp
	${CC} ${CFLAGS} src/huffman.cpp -c -o huffman.o

test: ${EXEC}
	@bash run_tests.sh ${EXEC}

rand_input: rand_gen/rand_gen.cc
	${CC} ${CFLAGS} rand_gen/rand_gen.cc -o rand_input

valgrind_test: rand_input ${EXEC}
	@./rand_input 32 | valgrind ${EXEC}

clean:
	@rm -rf *.o ${EXEC} rand_input
