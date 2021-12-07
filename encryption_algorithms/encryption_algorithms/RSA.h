#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>


long int calculateE(long int t);
long int greatestCommonDivisor(long int e, long int t);
long int calculateD(long int e, long int t);
auto generatePublicKeys(int p, int q);
auto generatePrivateKeys(int p, int q);
long int encrypt(long int i, std::pair<long, long>);
long int decrypt(long int i, std::pair<long, long>);


std::string RSA(const std::string& msg);

std::string deRSA(const std::string& msg);