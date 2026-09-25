main : main.o smartRelay.o
	g++ main.o smartRelay.o -o main

main.o : main.cpp
	g++ -c main.cpp

smartRelay.o: smartRelay.cpp smartRelay.h
	g++ -c smartRelay.cpp -o smartRelay.o

clean:
	rm -f *.o main

run: main
	./main

.PHONY: clean run