
CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -g -Og
EXEC=./tp2
TMPOUT=tp2.testresult

$(EXEC): main.cpp functions.o
	$(CC) $(CFLAGS) main.cpp functions.o -o $(EXEC)

functions.o: functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp -o functions.o

test: $(EXEC)
	@bash ../run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -rf *.o $(EXEC)

