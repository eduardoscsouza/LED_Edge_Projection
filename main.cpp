#include <iostream>
#include "arduinoserial.hpp"

using namespace std;



int main(int argc, char * argv[])
{
	ArduinoSerial serial;
	serial.begin();
	char * s = (char *) malloc(4);
	s[0] = 'z';
	serial.send(s, 1);
	serial.end();

	return 0;
}