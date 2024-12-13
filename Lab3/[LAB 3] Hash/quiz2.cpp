#include <iostream>
#include <math.h>
using namespace std;

long int midSquare(long int seed)
{
    seed = pow(seed, 2);
    seed /= 100;
    return seed % 10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
}
long int digitExtraction(long int seed, int *extractDigits, int size)
{
    string strSeed = to_string(seed);
    string strResult = "";

    for (int i = 0; i < size; i++)
    {
        strResult += strSeed.substr(extractDigits[i], 1);
    }
    return stoll(strResult);
}