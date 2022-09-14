#include <iostream>

using namespace std;

string insertNumtoString(string &s, int num)
{
  return s.insert(0, 1, (char)(num + '0'));
}

string addTwoNums(string &s1, string &s2)
{
  string answer;

  int i = s1.size() - 1, j = s2.size() - 1;
  int carry = 0, next;

  while (i >= 0 && j >= 0)
  {
    next = carry + (s1[i--] - '0') + (s2[j--] - '0');

    carry = next / 10;
    insertNumtoString(answer, next % 10);
  }

  while (i >= 0)
  {
    next = carry + (s1[i--] - '0');
    carry = next / 10;
    insertNumtoString(answer, next % 10);
  }

  while (j >= 0)
  {
    next = carry + (s2[j--] - '0');
    carry = next / 10;
    insertNumtoString(answer, next % 10);
  }

  if (carry > 0)
  {
    insertNumtoString(answer, carry);
  }

  return answer;
}

int main()
{
  string s1, s2;

  cin >> s1 >> s2;

  cout << addTwoNums(s1, s2);
}

