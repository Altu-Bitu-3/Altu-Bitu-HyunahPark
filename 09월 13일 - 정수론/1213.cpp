#include <deque>
#include <iostream>
#include <vector>

using namespace std;

const int ALPHA = 26;
const string error_msg = "I'm Sorry Hansoo";

string toPalindrome(string input)
{
  deque<char> d;
  vector<int> alphabets(ALPHA);

  //알파벳별 개수 카운트
  for (char c : input)
  {
    alphabets[c - 'A']++;
  }

  int start = -1;

  for (int i = 0; i < ALPHA; i++)
  {
    //전체 개수가 홀수인 알파벳이 두 종류 이상이라면 변환 불가능
    if (alphabets[i] % 2 && start != -1)
    {
      return error_msg;
    }

    if (alphabets[i] % 2)
    {
      start = i;
    }
  }

  //전체 개수가 홀수인 알파벳을 먼저 삽입
  if (start != -1)
  {
    d.push_back(start + 'A');
    alphabets[start]--;
  }

  //사전적으로 뒤에 오는 알파벳부터 삽입
  for (int i = ALPHA - 1; i >= 0; i--)
  {
    //양쪽에 추가
    while (alphabets[i])
    {
      d.push_front(i + 'A');
      d.push_back(i + 'A');
      alphabets[i] -= 2;
    }
  }

  string answer = "";

  while (!d.empty())
  {
    answer += (d.front());
    d.pop_front();
  }

  return answer;
}

int main()
{
  string input;
  cin >> input;
  cout << toPalindrome(input);
}