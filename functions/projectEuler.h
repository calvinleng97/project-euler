#ifndef PROJECT_EULER
#define PROJECT_EULER

#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>

std::vector<unsigned long int> properDivisors (unsigned long int num);

std::vector<unsigned long int> allDivisors (unsigned long int num);

unsigned long int sumProperDivisors (unsigned long int num);

unsigned long int fibonacci (int n);

std::vector<unsigned long int> eSieve (unsigned long int n);

bool* eSieveBool (unsigned long int n);

bool isPrime(unsigned long int n);

int numDigits(unsigned long int n);

int gcd(int x, int y);

unsigned long int factorial (int n);

unsigned long int choose (int n, int k);

#endif
