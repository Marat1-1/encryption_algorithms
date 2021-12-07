#include <iostream>
#include <sstream>



#ifndef ALGORITHMS_H
#define ALGORITHMS_H

	// Generator key for XOR
	std::string generateKeyXor(const std::string& key, size_t sizeString);

	// XOR
	std::string xorAlgorithms(const std::string&, std::string);

#endif // !ALGORITHMS_H