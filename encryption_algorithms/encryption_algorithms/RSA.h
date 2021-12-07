#pragma once
//  main.cpp
//  RSA
//
//  Created by Sergiy on 06.06.17.

#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>


long int calculateE(long int t);
long int greatestCommonDivisor(long int e, long int t);
long int calculateD(long int e, long int t);
long int encrypt(long int i, long int e, long int n);
long int decrypt(long int i, long int d, long int n);

std::string RSA(const std::string& msg);

bool isPrime(long int prime);

long int calculateE(long int t);

long int greatestCommonDivisor(long int e, long int t);

long int calculateD(long int e, long int t);

long int encrypt(long int i, long int e, long int n);

long int decrypt(long int i, long int d, long int n);
