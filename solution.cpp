#include <iostream>
#include <iomanip>

static const unsigned long long int N = 600851475143;

using namespace std;

int main()
{
  unsigned long long int n = N;
  unsigned long int largestFactor = 1;

  // The loop update goes from 2 to 3, and elsewise
  // loops through the odd numbers
  for (int i = 2; n != 1; i += ((i == 2) ? 1 : 2))
  {
    while (n % i == 0)
    {
      n /= i;
      largestFactor = i;
    }
  }

  cout << largestFactor << endl;

  return 0;
}
