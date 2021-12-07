#include "XOR.h"
#include <sstream>

// Generator key for XOR
std::string generateKeyXor(const std::string& key, size_t sizeString)
{
	std::string result;
	for (size_t i = 0, j = 0; i < sizeString; i++, j++)
	{
		if (j == key.size())
			j = 0;
		result += key[j];
	}
	return result;
}
// Badamshin Marat, XOR
std::string xorAlgorithms(const std::string& input, std::string key)
{
	std::string result;
	key = generateKeyXor(key, input.size());
	for (size_t i = 0, j = 0; i < input.size(); i++, j++)
		result += input[i] ^ key[i];
	return result;
};