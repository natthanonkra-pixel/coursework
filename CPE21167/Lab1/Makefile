main: main.o EnvironmentSensor.o
	g++ main.o EnvironmentSensor.o -o main

main.o: main.cpp
	g++ -c main.cpp

EnvironmentSensor.o: EnvironmentSensor/EnvironmentSensor.cpp EnvironmentSensor/EnvironmentSensor.h
	g++ -c EnvironmentSensor/EnvironmentSensor.cpp -o EnvironmentSensor.o

clean:
	rm -f *.o main

run: main
	./main

.PHONY: clean run