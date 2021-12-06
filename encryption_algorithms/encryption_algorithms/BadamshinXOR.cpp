#include "BadamshinXOR.h"
#include <sstream>


// Badamshin Marat, XOR
std::string xorAlgorithms(std::string& input, unsigned char key)
{
	std::string result;
	for (size_t i = 0; i < input.size(); i++)
		result += input[i] ^ key;
	return result;
};