#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

vector<vector<int>> lettuce;

void dfs(int x, int y, int m, int n)
{
  stack<ci> st;
  int dx[4] = {1, 0, 0, -1};
  int dy[4] = {0, 1, -1, 0};

  st.push({x, y});

  while (!st.empty())
  {
    int cx = st.top().first;
    int cy = st.top().second;
    st.pop();
    lettuce[cx][cy] = 0;

    for (int i = 0; i < 4; i++)
    {
      int nx = cx + dx[i];
      int ny = cy + dy[i];

      if (nx >= 0 && nx < m && ny >= 0 && ny < n && lettuce[nx][ny])
      {
        st.push({nx, ny});
      }
    }
  }
}

int main()
{
  int t, m, n, k, x, y, sum = 0;
  cin >> t;

  while (t--)
  {
    cin >> m >> n >> k;
    lettuce.assign(m, vector<int>(n, 0));
    sum = 0;

    for (int i = 0; i < k; i++)
    {
      cin >> x >> y;
      lettuce[x][y] = 1;
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (lettuce[i][j])
        {
          sum++;
          dfs(i, j, m, n);
        }
      }
    }

    cout << sum << "\n";
  }
}