#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> findPrimes(int n)
{
  vector<bool> is_prime(n + 1, true);
  vector<ll> primes;

  is_prime[0] = is_prime[1] = false;

  for (ll i = 2; i <= n; i++)
  {
    if (is_prime[i])
    {
      for (ll j = i * i; j <= n; j += i)
      {
        is_prime[j] = false;
      }
    }
  }

  for (ll i = 2; i <= n; i++)
  {
    if (is_prime[i])
    {
      primes.push_back(i);
    }
  }

  return primes;
}

ll calcSum(int n)
{
  ll sum = 0;
  int tmp = n;

  while (tmp)
  {
    sum += (tmp % 10) * (tmp % 10);
    tmp /= 10;
  }

  return sum;
}

bool isValid(int n)
{
  ll result, tmp = n;
  set<ll> chk;

  while (true)
  {
    result = calcSum(tmp);

    if (result == 1)
    {
      return true;
    }

    if (chk.count(result))
    {
      return false;
    }

    chk.insert(result);
    tmp = result;
  }
}

int main()
{
  int n;
  cin >> n;

  vector<ll> primes = findPrimes(n);

  for (ll prime : primes)
  {
    if (isValid(prime))
    {
      cout << prime << "\n";
    }
  }
}