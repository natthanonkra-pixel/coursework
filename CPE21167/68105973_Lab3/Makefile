main: main.o IrrigationValve.o
	g++ main.o IrrigationValve.o -o main

main.o: main.cpp
	g++ -c main.cpp

IrrigationValve.o: IrrigationValve/IrrigationValve.cpp IrrigationValve/IrrigationValve.h
	g++ -c IrrigationValve/IrrigationValve.cpp -o IrrigationValve.o

clean:
	rm -f *.o main

run: main
	./main

.PHONY: clean run