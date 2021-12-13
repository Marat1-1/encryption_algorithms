#include "XOR.h"
#include "RSA.h"
#include "RC4.h"
#include <fstream>
#include <vector>
#include <random>
#include <map>
#include <chrono>


int main()
{
	// Files for reading and outputting data
	std::map<std::string, std::vector<std::string>> filesInAndOut{
		{ "data1.txt", { "result1XOR.txt", "result1RC4.txt", "result1RSA.txt" } },
		{ "data2.txt", { "result2XOR.txt", "result2RC4.txt", "result2RSA.txt"} },
		{ "data3.txt", { "result3XOR.txt", "result3RC4.txt", "result3RSA.txt"} }
	};
	// Positions method in Map
	int xorPosition = 0, rc4Position = 1, rsaPosition = 2;
	// Input and output streams for encryption
	std::ifstream fin;
	std::ofstream foutXOR, foutRC4, foutRSA;
	// Strings
	std::string resultEncryptXOR, resultEncryptRSA, resultEncryptRC4, data;
	// Key for methods
	std::string key = "RTX";
	// Object class RC4
	RC4 rc4(key);
	// Encryption
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
			// Encryption
			while (!fin.eof())
			{
				getline(fin, data);
				// XOR
				auto start_time = std::chrono::steady_clock::now();
				resultEncryptXOR = xorAlgorithms(data, key);
				auto end_XOR = std::chrono::steady_clock::now();
				time_XOR += std::chrono::duration_cast<std::chrono::nanoseconds>(end_XOR - start_time).count();
				foutXOR << resultEncryptXOR;
				// RSA
				auto start_RSA = std::chrono::steady_clock::now();
				resultEncryptRSA = RSA(data);
				auto end_RSA = std::chrono::steady_clock::now();
				time_RSA += std::chrono::duration_cast<std::chrono::nanoseconds>(end_RSA - start_RSA).count();
				foutRSA << resultEncryptRSA;
				// RC4
				auto start_RC4 = std::chrono::steady_clock::now();
				resultEncryptRC4 = rc4.encrypt(data);
				auto end_RC4 = std::chrono::steady_clock::now();
				time_RC4 += std::chrono::duration_cast<std::chrono::nanoseconds>(end_RC4 - start_RC4).count();
				foutRC4 << resultEncryptRC4;
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