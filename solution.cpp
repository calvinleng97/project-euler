#include <iostream>
#include <iomanip>
#include "../functions/projectEuler.h"

using namespace std;

int main()
{
  vector<unsigned long int> primes = eSieve(2000000);
  cout << primes[10000] << endl;
}
