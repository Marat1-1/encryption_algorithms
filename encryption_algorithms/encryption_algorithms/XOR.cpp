#include "XOR.h"
#include <sstream>

// XOR
std::string xorAlgorithms(const std::string& input, std::string key)
{
	std::string result;
	/*key = generateKeyXor(key, input.size());*/
	for (size_t i = 0, j = 0; i < input.size(); i++, j++)
	{
		if (j == key.size())
			j = 0;
		result += input[i] ^ key[j];
	}
	return result;
};