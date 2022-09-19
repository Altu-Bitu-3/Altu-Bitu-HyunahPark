#include <iostream>
#include <string>

using namespace std;

int gcdRecur(int a, int b)
{
  if (!b)
  {
    return a;
  }
  return gcdRecur(b, a % b);
}

int main()
{
  string a, b, input;
  bool isFirst = true;
  cin >> input;

  for (char c : input)
  {
    if (c == ':')
    {
      isFirst = false;
      continue;
    }
    if (isFirst)
    {
      a += c;
    }
    else
    {
      b += c;
    }
  }
  int n1 = stoi(a);
  int n2 = stoi(b);
  int gcd = gcdRecur(max(n1, n2), min(n1, n2));
  cout << n1 / gcd << ":" << n2 / gcd;
}