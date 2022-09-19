#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 1e6;
const string err_msg = "Goldbach's conjecture is wrong";

vector<bool> findPrimes(int n)
{
  vector<bool> is_prime(n + 1, true);

  is_prime[0] = is_prime[1] = false;

  for (ll i = 2; i * i <= n; i++)
  {
    if (is_prime[i])
    {
      for (ll j = i * i; j <= n; j += i)
      {
        is_prime[j] = false;
      }
    }
  }

  return is_prime;
}

int main()
{
  int input;
  vector<bool> is_prime = findPrimes(MAX);
  bool is_valid = false;

  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  while (true)
  {
    cin >> input;

    if (!input)
    {
      break;
    }

    for (int i = 3; i <= (input / 2); i += 2)
    {
      if (is_prime[i] && is_prime[input - i])
      {
        is_valid = true;
        cout << input << " = " << i << " + "
             << input - i << "\n";
        break;
      }
    }

    if (!is_valid)
    {
      cout << err_msg << "\n";
    }
  }
}
