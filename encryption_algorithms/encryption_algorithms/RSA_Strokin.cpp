#include "RSA.h"

const int P = 11, Q = 13;

std::string RSA(const std::string& msg)
{
    long int n, t, e, d;


    long int encryptedText[100];
    memset(encryptedText, 0, sizeof(encryptedText));

    std::string result;

    bool flag;

    // 1. Вычисляется их произведение n = p ⋅ q, которое называется модулем.
    n = P * Q;

    // 2. Вычисляется значение функции Эйлера от числа n: φ(n) = (p−1)⋅(q−1)
    t = (P - 1) * (Q - 1);

    // 3. Выбирается целое число e ( 1 < e < φ(n) ), взаимно простое со значением функции Эйлера (t)
    //	  Число e называется открытой экспонентой
    e = calculateE(t);

    // 4. Вычисляется число d, мультипликативно обратное к числу e по модулю φ(n), то есть число, удовлетворяющее сравнению:
    //    d ⋅ e ≡ 1 (mod φ(n))
    d = calculateD(e, t);

    // 5. Пара {e, n} публикуется в качестве открытого ключа RSA
    //std::cout << "\nRSA public key is (n = " << n << ", e = " << e << ")" << std::endl;

    // 6. Пара {d, n} играет роль закрытого ключа RSA и держится в секрете
    //std::cout << "RSA private key is (n = " << n << ", d = " << d << ")" << std::endl;

    // encryption

    for (long int i = 0; i < msg.length(); i++)
    {
        encryptedText[i] = encrypt(msg[i], e, n);
    }

    for (long int i = 0; i < msg.length(); i++)
    {
        result += (char)encryptedText[i];
    }

    return result;

    //decryption

    //for (long int i = 0; i < msg.length(); i++)
    //{
      //  decryptedText[i] = decrypt(encryptedText[i], d, n);
   // }

    //std::cout << "\n\nTHE DECRYPTED MESSAGE IS:" << std::endl;

    //for (long int i = 0; i < msg.length(); i++)
    //{
      //  printf("%c", (char)decryptedText[i]);
    //}
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


long int encrypt(long int i, long int e, long int n)
{
    long int current, result;

    current = i - 97;
    result = 1;

    for (long int j = 0; j < e; j++)
    {
        result = result * current;
        result = result % n;
    }

    return result;
}

long int decrypt(long int i, long int d, long int n)
{
    long int current, result;

    current = i;
    result = 1;

    for (long int j = 0; j < d; j++)
    {
        result = result * current;
        result = result % n;
    }

    return result + 97;
}
