#ifndef ARDUINOSERIAL_HPP
#define ARDUINOSERIAL_HPP



#include <stddef.h>

class ArduinoSerial
{
public:
	int file_descriptor;

	ArduinoSerial();
	void clear();

	bool begin();
	bool begin(const char *);
	bool begin(const char *, int);

	bool end();

	bool send(void *, size_t);
	bool receive(void *, size_t);
};



#endif