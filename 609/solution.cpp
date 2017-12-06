/*
 * Project Euler 609
 * Time Complexity: O(N^(3/2)) 
 * Does not work for small values of N. Must change the log(N) in code to
 * a constant around 20 for it to work for small values, as log(N) is not a
 * good approximate for pi-sequence length for small N. A very naive approach,
 * can most likely be improved to linear post-prime-sieving.
 *
 */
#include "../functions/projectEuler.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include <ctime>

static const int N = 100000000;

using namespace std;


int main()
{
  clock_t t;
  t = clock();

  /*
   * Sieving Primes up to N.
   * Complexity: O(N * loglogN)
   *
   */
  cout << "Sieving primes..." << endl;
  bool* is_prime = eSieveBool(N);

  /*
   * Precomputing prime counting function.
   * Complexity: O(N * sqrt(N))
   *
   */

  cout << "Precomputing prime counting values..." << endl;
  vector<long unsigned int> pi;
  pi.push_back(0); // pi(0) = 0
  pi.push_back(0); // pi(1) = 0
  pi.push_back(1); // pi(2) = 1
  int currentP = 1;

  for (long unsigned int i = 3; i <= N; i++)
  {
    if (is_prime[i])
      currentP++;
    
    pi.push_back(currentP);
  }

  cout << "Computing p_values..." << endl;
  vector<long unsigned int> p_values;
  
  /* 
   * Computes the p_values for each starting u_0.
   * log(N) / loglog(N) is rough upperbound for length of pi_sequences
   * known from results in number theory. I overestimate
   * just in case.
   * Time Complexity: O(N * log(N))
   *
   */
  for (int i = 0; i < log(N); i++)
    p_values.push_back(0);

  for (long unsigned int i = 2; i <= N; i++)
  {
    int nonprime_count = 0;
    int pi_sequence_length = 1;

    for (long unsigned int u_x = i; u_x != 1; u_x = pi[u_x], pi_sequence_length++)
    {
      if (!is_prime[u_x])
        nonprime_count++;

      if (pi_sequence_length >= 2)
        p_values[nonprime_count]++;
    }

    p_values[nonprime_count + 1]++;
  }
 
  /*
   * Computes the result.
   * Time Complexity: O(logN * Multiplication)
   *
   */
  long unsigned int runningProd = 1;
  for (int i = 0; i < log(N); i++)
    if (p_values[i] != 0)
      runningProd = (runningProd * p_values[i]) % 1000000007;

  t = clock() - t;
  cout << "Answer: " << runningProd << endl;
  cout << "Took " << (float) t / CLOCKS_PER_SEC << "s to run program!";
}
