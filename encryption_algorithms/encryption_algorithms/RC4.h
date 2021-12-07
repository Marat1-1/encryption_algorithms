#include <string>
#include <vector>

class RC4
{
public:

	RC4(std::string& key, size_t size = 256);
	RC4();
	std::string encrypt(std::string input);

private:
	std::vector<int> m_sBox; // Переменная для подстановки
};