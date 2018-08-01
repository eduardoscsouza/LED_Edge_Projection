#include "arduinoserial.hpp"

#include <unistd.h>
#include <fcntl.h>


#define STD_DEVICE "/dev/ttyACM0"
#define STD_FLAGS O_RDWR | O_SYNC | O_RSYNC | O_NOCTTY



ArduinoSerial::ArduinoSerial()
{
	this->clear();
}

void ArduinoSerial::clear()
{
	this->file_descriptor = -1;
}



bool ArduinoSerial::begin()
{
	return begin(STD_DEVICE);
}

bool ArduinoSerial::begin(const char * filename)
{
	return begin(filename, STD_FLAGS);
}

bool ArduinoSerial::begin(const char * filename, int flags)
{
	this->file_descriptor = open(filename, flags);
	if (file_descriptor > 0) return true;
	else return false;
}



bool ArduinoSerial::end()
{
	if (this->file_descriptor > 0){
		if (close(this->file_descriptor) == 0){
			this->clear();
			return true;
		}
		else return false;
	}
}



bool ArduinoSerial::send(void * data, size_t nbytes)
{
	if (write(this->file_descriptor, data, nbytes) != nbytes) return false;
	else return true;
}

bool ArduinoSerial::receive(void * data, size_t nbytes)
{
	if (read(this->file_descriptor, data, nbytes) != nbytes) return false;
	else return true;
}