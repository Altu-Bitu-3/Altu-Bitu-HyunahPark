#include <iostream>
#include <stack>
#include <map>

using namespace std;

string infixtoPostfix(string &s)
{
  stack<char> st;
  string post = "";
  map<char, int> m = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

  for (char c : s)
  {
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
    while (m[st.top()] > m[c])
    {
      post += st.top();
      st.pop();
    }
    st.push(c);
  }

  return post;
}

int main()
{
  string input;
  cout << infixtoPostfix(input);
}