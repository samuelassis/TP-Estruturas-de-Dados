CC=g++
CFLAGS= -std=c++11 -Wall -Wextra
EXEC=./tp1
TMPOUT=tp1.testresult

$(EXEC): src/main.cc functions.o lista.o
	$(CC) $(CFLAGS) src/main.cc functions.o lista.o -o $(EXEC)

functions.o: src/functions.cpp functions.h 
	$(CC) $(CFLAGS) -c src/functions.cpp functions.h -o functions.o

lista.o: src/ lista.cpp lista.h
	$(CC) $(CFLAGS) -c src/lista.cpp lista.h -o lista.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: 
	rm -rf *.o *~ $(EXEC)

