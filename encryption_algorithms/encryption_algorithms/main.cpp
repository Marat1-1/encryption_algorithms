#include "BadamshinXOR.h"
#include <fstream>
#include <vector>
#include <random>
#include <map>
#include <chrono>


int main(int argc, char* argv)
{
	// Files for reading and outputting data
	std::map<std::string, std::vector<std::string>> filesInAndOut{
		{ "data1.txt", { "result1XOR.txt", "result1RC4.txt", "result1RSA.txt" } },
		{ "data2.txt", { "result2XOR.txt", "result2RC4.txt", "result2RSA.txt"} },
		{ "data3.txt", { "result3XOR.txt", "result3RC4.txt", "result3RSA.txt"} }
	};
	// Positions method in Map
	size_t xorPosition = 0, rc4Position = 1, rsaPosition = 2;
	// Input and output streams
	std::ifstream fin;
	std::ofstream foutXOR;
	std::ofstream foutRC4;
	std::ofstream foutRSA;
	// Strings
	std::string data;
	std::string resultStr;
	// Keys
	unsigned char keyXOR;
	// Random number generation from 0 to 256
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 256);
	// Generating the xor key
	keyXOR = dist(gen);
	for (const auto& file : filesInAndOut)
	{
		// Timers for methods
		long long time_XOR = 0, time_RC4 = 0, time_RSA = 0;
		fin.open(file.first);
		foutXOR.open(file.second[xorPosition]);
		foutRC4.open(file.second[rc4Position]);
		foutRSA.open(file.second[rsaPosition]);
		if (fin.is_open() && foutXOR.is_open() && foutRC4.is_open() && foutRSA.is_open())
		{
			while (!fin.eof())
			{
				getline(fin, data);
				// XOR
				auto start_time = std::chrono::steady_clock::now();
				resultStr = xorAlgorithms(data, keyXOR);
				auto end_XOR = std::chrono::steady_clock::now();
				time_XOR += std::chrono::duration_cast<std::chrono::nanoseconds>(end_XOR - start_time).count();
				foutXOR << resultStr;
				// RC4
				// RSA
			}
			std::cout << "\nName of file: " << file.first << std::endl
				<< "Time XOR: " << time_XOR << std::endl
				<< "Time RC4: " << time_RC4<< std::endl
				<< "Time RSA: " << time_RSA << std::endl;
		}
		else
			std::cerr << "ERROR!!! The file for input or output did not open." << std::endl;
		foutXOR.close();
		foutRC4.close();
		foutRSA.close();
		fin.close();
	}
	return 0;
};