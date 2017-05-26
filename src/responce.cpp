#include "responce.h"

std::string test(std::string data){
	std::stringstream ss;
	ss << data << std::endl;

	std::string message = ss.str();
	return message;
}
