#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(string s)
{
  int x = 0, y = 0;
  int min_x = 0, min_y = 0, max_x = 0, max_y = 0;

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, -1, 0, 1};

  //북을 바라보고 시작
  int head = 3;

  for (char c : s)
  {
    switch (c)
    {
    case 'F':
      //전진
      x += dx[head];
      y += dy[head];
      break;
    case 'B':
      //후진
      x -= dx[head];
      y -= dy[head];
      break;
    case 'L':
      //왼쪽으로 90도 회전
      //배열 범위를 초과하지 않도록 처리
      head = (head - 1 + 4) % 4;
      break;
    case 'R':
      //오른쪽으로 90도 회전
      head = (head + 1) % 4;
      break;
    }
    //최소,최대값 갱신
    min_x = min(min_x, x);
    min_y = min(min_y, y);
    max_x = max(max_x, x);
    max_y = max(max_y, y);
  }

  //넓이 계산
  return (max_x - min_x) * (max_y - min_y);
}

int main()
{
  int t;
  cin >> t;

  string s;

  while (t--)
  {
    cin >> s;
    cout << calc(s) << "\n";
  }
}