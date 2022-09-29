#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 10;
const int MAX = 1e7;

int n, minv = MAX;
vector<int> cities(SIZE);                          //도시 경로 저장
vector<vector<int>> dist(SIZE, vector<int>(SIZE)); //도시간 비용 저장
vector<int> check(SIZE);                           //도시 선택 여부 저장

void backtracking(int cnt)
{
  if (cnt == n)
  {
    int result = 0;
    for (int i = 0; i < (n - 1); i++)
    {
      //도시간 이동이 불가능한 경우
      if (!dist[cities[i]][cities[i + 1]])
      {
        return;
      }
      result += dist[cities[i]][cities[i + 1]];
    }

    //원래 도시로 돌아가기
    //도시간 이동이 불가능한 경우
    if (!dist[cities[n - 1]][cities[0]])
    {
      return;
    }
    result += dist[cities[n - 1]][cities[0]];

    //최소값 갱신
    if (result < minv)
    {
      minv = result;
    }

    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (!check[i])
    {
      cities[cnt] = i;
      check[i] = true;
      backtracking(cnt + 1);
      check[i] = false;
    }
  }
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> dist[i][j];
    }
  }

  backtracking(0);

  cout << minv;
}