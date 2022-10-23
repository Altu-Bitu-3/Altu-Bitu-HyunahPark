#include <iostream>
#include <string>
#include <vector>

using namespace std;

void changeType(string input)
{
  string s = "";
  int type = 0;
  vector<string> str;

  //첫 글자가 소문자가 아닌 경우
  if (input[0] < 'a' || input[0] > 'z')
  {
    cout << "Error!";
    return;
  }

  for (int i = 0; i < input.size(); i++)
  {
    if (input[i] == '_')
    {
      str.push_back(s);
      s = "";

      //변수명 타입이 혼용되거나 c++, java 변수명 타입에 해당되지 않는 경우
      if (input[i + 1] < 'a' || input[i + 1] > 'z' || type == -1)
      {
        cout << "Error!";
        return;
      }

      s += toupper(input[++i]);
      type = 1; //c++ 변수명 타입이란 것을 저장
    }

    else if (input[i] >= 'A' && input[i] <= 'Z')
    {
      str.push_back(s + '_');
      s = tolower(input[i]);

      //변수명 타입이 혼용되거나 c++, java 변수명 타입에 해당되지 않는 경우
      if (i > input.size() - 1 &&
          (input[i + 1] < 'a' || input[i + 1] > 'z' || type == 1))
      {
        cout << "Error!";
        return;
      }

      type = -1;
    }

    else
    {
      s += input[i];
    }
  }

  str.push_back(s);

  for (string s : str)
  {
    cout << s;
  }
}

int main()
{
  string input, s = "";
  bool error_flag = false;
  int type = 0;
  vector<string> str;

  cin >> input;
  changeType(input);
}