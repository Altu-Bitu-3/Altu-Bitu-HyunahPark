#include <iostream>
#include <stack>
#include <map>

using namespace std;

string infixtoPostfix(string &s)
{
  stack<char> st;
  string post = "";
  //연산자 우선순위 맵핑
  map<char, int> m = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

  for (char c : s)
  {
    //피연산자인 경우
    if ((c - 'A') >= 0 && (c - 'A') <= 26)
    {
      post += c;
      continue;
    }
    if (c == '(')
    {
      st.push(c);
      continue;
    }
    if (c == ')')
    {
      while (st.top() != '(')
      {
        post += st.top();
        st.pop();
      }
      st.pop();
      continue;
    }
    //우선순위가 더 높은 연산자를 먼저 출력
    while (!st.empty() && m[st.top()] >= m[c])
    {
      post += st.top();
      st.pop();
    }
    st.push(c);
  }

  while(!st.empty()){
    post+=st.top();
    st.pop();
  }

  return post;
}

int main()
{
  string input;
  cin >> input;
  cout << infixtoPostfix(input);
}
