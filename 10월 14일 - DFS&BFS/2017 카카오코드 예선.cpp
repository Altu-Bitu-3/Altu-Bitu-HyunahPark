#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<bool>> visited;

int dfs(int x, int y, int m, int n, vector<vector<int>> &picture)
{
  stack<pair<int, int>> st;
  st.push({x, y});
  visited[x][y] = true;

  int cx, cy, nx, ny, cnt = 0;
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  while (!st.empty())
  {
    cx = st.top().first;
    cy = st.top().second;
    st.pop();
    cnt++;

    for (int i = 0; i < 4; i++)
    {
      nx = cx + dx[i];
      ny = cy + dy[i];

      if (nx >= 0 && nx < m && ny >= 0 && ny < n && (picture[cx][cy] == picture[nx][ny]) && !visited[nx][ny])
      {
        st.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
  return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
  int number_of_area = 0;
  int max_size_of_one_area = 0;
  int size_of_one_area = 0;

  visited.assign(m, vector<bool>(n, false));

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (picture[i][j] && !visited[i][j])
      {
        number_of_area++;
        size_of_one_area = dfs(i, j, m, n, picture);
        max_size_of_one_area = max(max_size_of_one_area, size_of_one_area);
      }
    }
  }

  vector<int> answer(2);
  answer[0] = number_of_area;
  answer[1] = max_size_of_one_area;
  return answer;
}