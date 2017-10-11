#include <iostream>
#include <iomanip>

using namespace std;

bool isPalindrome (int n)
{
  string s = to_string(n);
  for (int i = 0; i <= s.length() - i - 1; i++)
    if (s[i] != s[s.length() - 1 - i])
      return false;

  return true;
}

int main()
{
  int record = 0;

  for (int i = 100; i <= 999; i++)
  {
    for (int j = 100; j <= 999; j++)
    {
      int prod = i * j;

      if (isPalindrome(prod) && prod > record)
        record = prod;
    }
  }

  cout << record << endl;

  return 0;
}
