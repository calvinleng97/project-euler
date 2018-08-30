/*
 * Project Euler 635
 *
 */
#include "../functions/projectEuler.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include <ctime>

static const int N = 100000000;
static const int mod = 1000000009;

using namespace std;

// for division over F_mod
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        int q = a / m;
        int t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
       x += m0;

    return x;
}

int main()
{
    clock_t t;
    t = clock();

    vector<unsigned long int> primes = eSieve(N);
    vector<unsigned long int>::iterator itr = primes.begin();
    vector<unsigned long int>::iterator next = itr;
    next++;

    unsigned long long int fact2 = choose(4, 2);
    unsigned long long int fact3 = choose(6, 2);
    unsigned long long int runningSum = 0;

    for (;itr != primes.end(); itr++, next++) {
        unsigned long int p = *itr;
        runningSum += ((fact2 - 2) % mod) * modInverse(p, mod) + 2;
        runningSum %= mod;
        runningSum += ((fact3 - 3) % mod) * modInverse(p, mod) + 3;
        runningSum %= mod;

        // updates the factorial dynamically rather than recomputing
        if (*next) {
            unsigned long int nextP = *next;

            for (unsigned long long int x = 2*p + 1; x <= 2*nextP; x++) {
                fact2 *= x;
                fact2 %= mod;
            }
             
            for (unsigned long long int x = 1; x <= nextP - p; x++) {
                unsigned long long int multInverse = modInverse(p + x, mod);
                fact2 *= multInverse;
                fact2 %= mod;
                fact2 *= multInverse;
                fact2 %= mod;
            }

            for (unsigned long long int x = 3*p + 1; x <= 3*nextP; x++) {
                fact3 *= x;
                fact3 %= mod;
            }

            for (unsigned long long int x = 2*p + 1; x <= 2*nextP; x++) {
                fact3 *= modInverse(x, mod);
                fact3 %= mod;
            }

            for (unsigned long long int x = p + 1; x <= nextP; x++) {
                fact3 *= modInverse(x, mod);
                fact3 %= mod;
            }
        }
    }
   
    runningSum -= 5; // off-by-x error for case of p = 2
    t = clock() - t;
    cout << "Answer: " << runningSum << endl;
    cout << "Took " << (float) t / CLOCKS_PER_SEC << "s to run program!";
}
