#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int r, b;
  cin >> r >> b;

  for (int i = b; i >= sqrt(b); i--)
  {
    if (b % i == 0)
    {
      if (2 * (i + b / i + 2) == r)
      {
        cout << i + 2 << " " << (b / i) + 2;
        break;
      }
    }
  }
}