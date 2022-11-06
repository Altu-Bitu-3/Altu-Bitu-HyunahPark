#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> board(n, vector<int>(m, 0));
vector<vector<int>> dp;

void calc()
{
  dp[0][0] = board[0][0];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i > 0 && j > 0)
      {
        dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + board[i][j];
      }
      else if (i > 0)
      {
        dp[i][j] = dp[i - 1][j] + board[i][j];
      }
      else if (j > 0)
      {
        dp[i][j] = dp[i][j - 1] + board[i][j];
      }
    }
  }
}

int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> board[i][j];
    }
  }

  calc();

  cout << dp[n - 1][m - 1];
}