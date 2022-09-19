#include <iostream>
#include <stack>

using namespace std;

int calculate(string &s)
{
  stack<char> st;
  int change = 0;

  for (char c : s)
  {
    if (c == '{')
    {
      st.push(c);
      continue;
    }

    //괄호 짝이 맞은 경우
    if (st.top() == '{')
    {
      st.pop();
      continue;
    }

    //괄호 짝이 맞지 않은 경우
    //잘못된 괄호가 있다면 제거
    //괄호를 바꾸어 짝이 맞는 괄호 푸쉬
    if (!st.empty())
    {
      st.pop();
    }
    change++;
    st.push('{');
  }

  //오른쪽 괄호가 올 차례인지 나타내는 변수
  bool isRight = true;

  //모든 괄호가 짝이 맞을 때까지 반복
  while (!st.empty())
  {
    //잘못된 괄호가 온 경우
    //잘못된 괄호 제거 후 알맞은 괄호 푸쉬
    if (isRight && st.top() != '}')
    {
      change++;
      st.pop();
      st.push('}');
    }
    else if (!isRight && st.top() != '{')
    {
      change++;
      st.pop();
    }
    //차례에 맞는 괄호가 온 경우
    //괄호 제거 후 차례 바꾸기
    else
    {
      st.pop();
      isRight = !isRight;
    }
  }

  return change;
}

int main()
{
  int n = 1;
  string input;
  cin >> input;

  while (input[0] != '-')
  {
    cout << n++ << ". " << calculate(input) << "\n";
    cin >> input;
  }
}