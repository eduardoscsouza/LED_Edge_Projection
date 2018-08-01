all:
	g++ -c -std=c++11 -O3 arduinoserial.cpp -o arduinoserial.o
	g++ -std=c++11 -O3 arduinoserial.o main.cpp -o main.out

clean:
	rm -f *.o *.out

run:
	./main.out