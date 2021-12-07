
#include "RC4.h"



// �����������. ���������� sBox �� ������ ��������������� �����.
RC4::RC4(std::string& key, size_t size)
{
	// ��������������� ���� ����������� �� ������ ���������������� �����.
	int a = 0, b = 0;
	m_sBox.resize(size);

	for (a = 0; a < 256; a++)
	{
		m_sBox[a] = a;
	}

	for (a = 0; a < 256; a++)
	{
		b = (b + m_sBox[a] + key[a % key.size()]) % 256;
		std::swap(m_sBox[a], m_sBox[b]);
	}
}

// ����������� ��� �����������. ������������� sBox �������. 
            
RC4::RC4()
{}


std::string RC4::encrypt(std::string input)
{
	std::vector<int> sBox = m_sBox;
	int i = 0, j = 0;
	long Offset;

	// ���������� ������. 
	for (Offset = 0; Offset < input.size(); Offset++)
	{
		i = (i + 1) % 256;
		j = (j + sBox[i]) % 256;
		std::swap(sBox[i], sBox[j]);
		input[Offset] ^= sBox[(sBox[i] + sBox[j]) % 256];
	}
	return input;
}