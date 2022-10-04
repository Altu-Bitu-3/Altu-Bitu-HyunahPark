#include <iostream>
#include <vector>

using namespace std;

int calc(int n, vector<int> &inputs)
{
  vector<int> dp(n + 1, 0);

  dp[1] = inputs[1];
  dp[2] = inputs[1] + inputs[2];

  for (int i = 3; i <= n; i++)
  {
    dp[i] = max(max(dp[i - 2] + inputs[i], dp[i - 1]),dp[i-3]+inputs[i-1]+inputs[i]);
  }

  return dp[n];
}

int main()
{
  int n;
  cin >> n;

  vector<int> inputs(n + 1);

  for (int i = 1; i <= n; i++)
  {
    cin >> inputs[i];
  }

  cout << calc(n, inputs);
}
