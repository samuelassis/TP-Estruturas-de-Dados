CC=g++
CFLAGS= -std=c++11 -Wall -Wextra
EXEC=./tp1
TMPOUT=tp1.testresult


$(EXEC): src/main.cc src/functions.o src/lista.o
	$(CC) $(CFLAGS) src/main.cc functions.o lista.o -o $(EXEC)

functions.o: src/functions.cpp 
	$(CC) $(CFLAGS) -c src/functions.cpp -o functions.o

lista.o: src/lista.cpp 
	$(CC) $(CFLAGS) -c src/lista.cpp -o lista.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: 
	rm -rf *.o *~ $(EXEC)

