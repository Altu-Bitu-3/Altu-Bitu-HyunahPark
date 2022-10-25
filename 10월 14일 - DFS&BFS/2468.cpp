#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<bool>> is_higher;

void dfs(int x, int y, int n)
{
  stack<pair<int, int>> st;
  int dx[4] = {1, 0, 0, -1};
  int dy[4] = {0, 1, -1, 0};

  st.push({x, y});

  while (!st.empty())
  {
    int cx = st.top().first;
    int cy = st.top().second;
    st.pop();
    is_higher[cx][cy] = 0;

    for (int i = 0; i < 4; i++)
    {
      int nx = cx + dx[i];
      int ny = cy + dy[i];

      if (nx >= 0 && nx < n && ny >= 0 && ny < n && is_higher[nx][ny])
      {
        st.push({nx, ny});
      }
    }
  }
}

int main()
{
  int n, max_h = 0, h = 1, area = 0, max_area = 1;
  cin >> n;

  vector<vector<int>> ground(n, vector<int>(n, 0));
  is_higher.assign(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> ground[i][j];

      if (max_h < ground[i][j])
      {
        max_h = ground[i][j];
      }
    }
  }

  while (h <= max_h)
  {
    area = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (ground[i][j] > h)
        {
          is_higher[i][j] = true;
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (is_higher[i][j])
        {
          area++;
          dfs(i, j, n);
        }
      }
    }

    if (area > max_area)
    {
      max_area = area;
    }

    h++;
  }

  cout << max_area;
}