#include <string>
using namespace std;

class CRC4
{
public:

	CRC4(unsigned char* pKey, unsigned int lenKey);
	CRC4();

	void RC4(unsigned char pData[], unsigned long lenData);
	string RC4Str(unsigned char* pInputData, unsigned long InputSize);
	void Initialize(unsigned char* pKey, unsigned int lenKey);

private:
	int m_sBox[256]; // Переменная для подстановки 
	int a, b;	
	unsigned char swap;
};