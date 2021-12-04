
#include "cRC4.h"

// �����������. ���������� sBox �� ������ ��������������� �����.
CRC4::CRC4(unsigned char* pKey, unsigned int lenKey)
{
	Initialize(pKey, lenKey);
}

// ����������� ��� �����������. ������������� sBox �������. 
            
CRC4::CRC4()
{}


void CRC4::Initialize(unsigned char* pKey, unsigned int lenKey)
{
	// ��������������� ���� ����������� �� ������ ���������������� �����.

	b = 0;

	for (a = 0; a < 256; a++)
	{
		m_sBox[a] = a;
	}

	for (a = 0; a < 256; a++)
	{
		b = (b + m_sBox[a] + pKey[a % lenKey]) % 256;
		swap = m_sBox[a];
		m_sBox[a] = m_sBox[b];
		m_sBox[b] = swap;
	}
}


void CRC4::RC4(unsigned char pData[], unsigned long lenData)
{
	int sBox[256];
	int i = 0, j = 0;
	long Offset;

	// ������� ��������� ����� �����. 
	memcpy(sBox, m_sBox, 256 * sizeof(int));

	// ���������� ������. 
	for (Offset = 0; Offset < lenData; Offset++)
	{
		i = (i + 1) % 256;
		j = (j + sBox[i]) % 256;
		swap = sBox[i];
		sBox[i] = sBox[j];
		sBox[j] = swap;
		pData[Offset] ^= sBox[(sBox[i] + sBox[j]) % 256];
	}
}


// ���������� ������� � ��������� ������ 
string CRC4::RC4Str(unsigned char* pInputData, unsigned long InputSize)
{
	string sInputOutputData((char*)pInputData, InputSize);
	RC4((unsigned char*)sInputOutputData.c_str(), InputSize);
	return sInputOutputData;
}