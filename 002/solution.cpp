#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
  int x1 = 1, x2 = 1;
  unsigned long int result = 0;

  do
  {
    if (x2 % 2 == 0)
      result += x2;
    
    int temp = x2;
    x2 = x1 + x2;
    x1 = temp;
  } while (x2 <= 4000000);

  cout << result << endl;

  return 0;
}