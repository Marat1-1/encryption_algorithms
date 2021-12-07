#include "RSA.h"

const int P = 11, Q = 13;

auto generatePublicKeys(int p, int q) {
    long int n, t, e;
    // 1. Вычисляется их произведение n = p ⋅ q, которое называется модулем.
    n = p * q;
    // 2. Вычисляется значение функции Эйлера от числа n: φ(n) = (p−1)⋅(q−1)
    t = (p - 1) * (q - 1);
    // 3. Выбирается целое число e ( 1 < e < φ(n) ), взаимно простое со значением функции Эйлера (t)
  //	  Число e называется открытой экспонентой
    e = calculateE(t);
    return std::make_pair(n, e);
}

auto generatePrivateKeys(int p, int q) {
    long int n, t, d;
    n = p * q;
    t = (p - 1) * (q - 1);
    // 4. Вычисляется число d, мультипликативно обратное к числу e по модулю φ(n), то есть число, удовлетворяющее сравнению:
//    d ⋅ e ≡ 1 (mod φ(n))
    d = calculateD(generatePublicKeys(p, q).second, t);
    return std::make_pair(n, d);
}

std::string RSA(const std::string& msg)
{
    std::vector<long int> encryptedText(msg.size());

    std::string result;

    auto public_key = generatePublicKeys(P, Q);

    auto private_key = generatePrivateKeys(P, Q);

    // encryption

    for (long int i = 0; i < msg.size(); i++)
    {
        encryptedText[i] = encrypt(msg[i], public_key);
    }

    for (long int i = 0; i < msg.length(); i++)
    {
        result += encryptedText[i];
    }

    //decryption
    return result;
}

std::string deRSA(const std::string& msg) {

    std::vector<long int> encryptedText(msg.size());

    std::string result;

    auto public_key = generatePublicKeys(P, Q);

    auto private_key = generatePrivateKeys(P, Q);

    // encryption

    for (long int i = 0; i < msg.size(); i++)
    {
        encryptedText[i] = encrypt(msg[i], public_key);
    }

    std::vector<long int> decryptedText(msg.size());

    for (long int i = 0; i < msg.size(); i++)
    {
        decryptedText[i] = decrypt(encryptedText[i], private_key);
    }

    for (long int i = 0; i < encryptedText.size(); i++)
    {
        result += (char)decryptedText[i];
    }
    return result;
}

long int calculateE(long int t)
{
    // Выбирается целое число e ( 1 < e < t ) // взаимно простое со значением функции Эйлера (t)

    long int e;

    for (e = 2; e < t; e++)
    {
        if (greatestCommonDivisor(e, t) == 1)
        {
            return e;
        }
    }

    return -1;
}

long int greatestCommonDivisor(long int e, long int t)
{
    while (e > 0)
    {
        long int myTemp;

        myTemp = e;
        e = t % e;
        t = myTemp;
    }

    return t;
}

long int calculateD(long int e, long int t)
{
    // Вычисляется число d, мультипликативно обратное к числу e по модулю φ(n), то есть число, удовлетворяющее сравнению:
    //    d ⋅ e ≡ 1 (mod φ(n))

    long int d;
    long int k = 1;

    while (1)
    {
        k = k + t;

        if (k % e == 0)
        {
            d = (k / e);
            return d;
        }
    }

}


long int encrypt(long int i, std::pair<long, long> key)
{
    long int current, result;

    current = i - 97;
    result = 1;

    for (long int j = 0; j < key.second; j++)
    {
        result = result * current;
        result = result % key.first;
    }

    return result;
}

long int decrypt(long int i, std::pair<long int, long int> key)
{
    long int current, result;

    current = i;
    result = 1;

    for (long int j = 0; j < key.second; j++)
    {
        result = result * current;
        result = result % key.first;
    }

    return result + 97;
}