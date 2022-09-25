#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, k, s, index = 0;
  cin >> n >> k;

  char c;
  vector<char> vec(n, '?');
  bool alpha[27] = {}; //이미 존재하는 알파벳 체크

  while (k--)
  {
    cin >> s >> c;
    index = (index - (s % n) + n) % n; //회전 후 위치

    //이미 해당 위치에 해당 문자가 있는 경우
    if (vec[index] == c)
    {
      continue;
    }
    //해당 위치에 다른 문자가 있는 경우(해당하는 행운의 바퀴가 없는 경우)
    if (vec[index] != '?' || alpha[c - 'A'])
    {
      cout << "!";
      return 0;
    }

    //해당 위치에 문자 삽입
    vec[index] = c;
    alpha[c - 'A'] = true;
  }

  for (int i = 0; i < n; i++)
  {
    //마지막으로 가리키던 문자부터 출력
    cout << vec[(index + i) % n];
  }
}