#include "BadamshinXOR.h"
#include <fstream>
#include <vector>
#include <random>


int main(int argc, char* argv)
{
	// Files for reading and outputting data
	std::vector<std::string>fileNamesInput {"data1.txt", "data2.txt", "data3.txt", "data4.txt"};
	std::vector<std::string>fileNamesOutput {"result1.txt", "result2.txt", "result3.txt", "result4.txt"};
	// Input and output streams
	std::ifstream fin;
	std::ofstream fout;
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
	for (size_t i = 0; i < fileNamesInput.size(); i++)
	{
		fin.open(fileNamesInput[i]);
		fout.open(fileNamesOutput[i]);
		if (fin.is_open() && fout.is_open())
		{
			while (!fin.eof())
			{
				getline(fin, data);
				resultStr = xorAlgorithms(data, keyXOR);
				std::cout << resultStr;
			}
		}
		else
			std::cerr << "ERROR!!! The file named " << fileNamesInput[i] << " or " << fileNamesOutput[i] << " did not open." << std::endl;
		fin.close();
		fout.close();
	}
	return 0;
};