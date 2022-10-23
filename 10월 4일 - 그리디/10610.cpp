#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool isAvailable(string &s)
{
  int sum = 0;
  bool isZero = false; //0이 있는지 여부

  for (char c : s)
  {
    if (c == '0')
    {
      isZero = true;
    }
    sum += (c - '0');
  }

  return sum % 3 == 0 && isZero; //각 자리수의 합이 3의 배수이고 0이 존재한다면 30의 배수로 만들 수 있음
}

int main()
{
  string s;
  cin >> s;

  if (!isAvailable(s))
  {
    cout << -1;
  }
  else
  {
    sort(s.begin(), s.end(), greater<char>()); //가장 큰 30의 배수로 만들기 위해 역순으로 정렬
    cout << s;
  }
}