
CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -g -Og
EXEC=./tp2
TMPOUT=tp2.testresult

$(EXEC): src/main.cpp functions.o
	$(CC) $(CFLAGS) src/main.cpp functions.o -o $(EXEC)

functions.o: src/functions.cpp
	$(CC) $(CFLAGS) -c src/functions.cpp -o functions.o

test: $(EXEC)
	@bash ../run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -rf *.o $(EXEC)

