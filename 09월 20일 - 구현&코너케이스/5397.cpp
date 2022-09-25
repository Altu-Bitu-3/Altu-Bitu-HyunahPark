#include <iostream>
#include <list>

using namespace std;

list<char> calc(string input)
{
  list<char> pw;
  auto index = pw.end();

  for (char c : input)
  {
    //왼쪽으로 커서 이동
    if (c == '<' && index != pw.begin())
    {
      index--;
    }
    //오른쪽으로 커서 이동
    else if (c == '>' && index != pw.end())
    {
      index++;
    }
    //커서 앞 글자 삭제
    else if (c == '-' && index != pw.begin())
    {
      index = pw.erase(--index);
    }
    //글자 삽입
    else if (c != '>' && c != '<' && c != '-')
    {
      pw.insert(index, c);
    }
  }

  return pw;
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  string input;

  while (t--)
  {
    cin >> input;

    for (auto c : calc(input))
    {
      cout << c;
    }

    cout << "\n";
  }
}
