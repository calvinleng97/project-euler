#include "projectEuler.h"
#include <iomanip>
#include <iostream>

using namespace std;

/* INPUTS:
 *   num: number to find the proper divisors of
 * OUTPUT:
 *   A vector which contains the proper divisors of the input.
 * SUMMARY:
 *   Computes the proper divisors of the input and puts it into an
 *   unsorted list. Works by finding divisors by pairs up to the
 *   square root of the input.
 */
vector<unsigned long int> properDivisors (unsigned long int num)
{
  int root = sqrt(num) + 1;
  vector<unsigned long int> vector;
  
  // 1 IS A DIVISOR OF EVERY NUMBER, DO NOT WANT PAIR THOUGH
  vector.push_back(1);

  // ALGORITHM
  for (int i = 2; i < root; i++)
  {
    if (num % i == 0 && i * i != num)
    {
      vector.push_back(i);
      vector.push_back(num / i);
    } // if i is not the sqrt, add in a pair of divisors

    if (num % i == 0 && i * i == num)
    {
      vector.push_back(i);
    } // if i is the sqrt, add in only 1 divisor
  }
  
  return vector;
}

/* INPUTS:
 *   num: number to find the divisors of
 * OUTPUT:
 *   A vector which contains the ivisors of the input.
 * SUMMARY:
 *   Computes the divisors of the input and puts it into an
 *   unsorted list. Works by finding divisors by pairs up to the
 *   square root of the input.
 */
vector<unsigned long int> allDivisors (unsigned long int num)
{
  int root = sqrt(num) + 1;
  vector<unsigned long int> vector;
  
  // 1 IS A DIVISOR OF EVERY NUMBER, DO NOT WANT PAIR THOUGH
  vector.push_back(1);
  vector.push_back(num);

  // ALGORITHM
  for (int i = 2; i < root; i++)
  {
    if (num % i == 0 && i * i != num)
    {
      vector.push_back(i);
      vector.push_back(num / i);
    } // if i is not the sqrt, add in a pair of divisors

    if (num % i == 0 && i * i == num)
    {
      vector.push_back(i);
    } // if i is the sqrt, add in only 1 divisor
  }
  
  return vector;
}

/*
 * INPUTS:
 *   num: Number to find the sum of the proper divisors of.
 * OUTPUT:
 *   The sum of the proper divisors of the inputs.
 * SUMMARY:
 *   Sums the proper divisors.
 */
unsigned long int sumProperDivisors (unsigned long int num)
{
  // GENERATES DIVISORS
  vector<unsigned long int> divisors = properDivisors(num);
  unsigned long int sum = 0;

  // SUMS DIVISORS
  for (int i = 0; i < divisors.size(); i++)
    sum += divisors[i];

  return sum;
}

/*
 * INPUTS:
 *   n: The index of the Fibonacci sequence.
 * OUTPUT:
 *   The nth term of the Fibonacci sequence.
 */
unsigned long int fibonacci(int n)
{
  int first = 1, second = 1, next;

  for (int i = 0; i <= n; i++)
  {
    if (i <= 1)
      next = 1;
    else
    {
      next = first + second;
      first = second;
      second = next;
    }
  }

  return next;
}

/*
 * Summary: Creates a list of primes up to n using
 * the Sieve of Eratosthenes.
 * 
 * Complexity: O(n logn loglogn)
 */
vector<unsigned long int> eSieve(unsigned long int n)
{
  vector<unsigned long int> result;

  bool* prime = (bool*) malloc ((n+1) * sizeof(bool));

  for (int i = 0; i < n; i++)
  {
    prime[i] = true;
  }

  for (int p = 2; p * p <= n; p++)
  {
    if (prime[p] == true)
    {
      for (int i = p * 2; i <= n; i += p)
      {
        prime[i] = false;
      }
    }
  }

  for (int p = 2; p <= n; p++)
  {
    if (prime[p])
    {
      result.push_back(p);
    }

  }

  return result;
}

/*
 * Summary: Creates an array where prime indexes are
 * marked as true using the Sieve of Ertosthenes.
 *
 */
bool* eSieveBool(unsigned long int n)
{
  bool *primes = (bool*) malloc(n * sizeof(bool));

  for (int i = 2; i < n; i++)
    primes[i] = true;

  primes[0] = false;
  primes[1] = false;

  for (int i = 2; i < n; i++)
  {
    if (primes[i] == true)
    {
      int temp = 2;

      while (temp * i < n)
      {
        primes[i*temp++] = false;
      }
    }
  }

  return primes;
}

/*
 * Summary: Basic primality tester.
 *
 */
bool isPrime(int n)
{
  if (n <= 1)
    return false;

  if (n == 2)
    return true;

  if (n % 2 == 0)
    return false;

  int counter = 3;
  while ((counter * counter) <= n)
  {
    if (n % counter == 0)
      return false;
    else
      counter += 2;
  }

  return true;
}


/*
 * Summary: Returns the number of digits of the input.
 *
 */
int numDigits(unsigned long int n)
{
  int digits = 0;

  if (n < 0) digits = 1;
  while (n)
  {
    n /= 10;
    digits++;
  }

  return digits;
}

int gcd (int a, int b)
{
  int x, y;

  if (a > b)
  {
    x = a;
    y = b;
  }
  else
  {
    x = b;
    y = a;
  }

  while (x % y != 0)
  {
    int temp = x;
    x = y;
    y = temp % x;
  }

  return y;
}

unsigned long int factorial (int n)
{
  unsigned long int result = 1;
  for (int i = 2; i <= n; i++)
    result *= i;
  return result;
}

unsigned long int choose (int n, int k)
{
  unsigned long int runningProduct = 1;
  for (int i = 1; i <= k; i++)
    runningProduct *= (n - (k - i)) / i;
  return runningProduct;
}
