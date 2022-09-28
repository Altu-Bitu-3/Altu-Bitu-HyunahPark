#include <iostream>
#include <string>

using namespace std;
const int fee1 = 10;
const int fee2 = 5;

//전화요금 계산
int calc(string t, int d)
{
  auto iter = t.find(':');
  int h = stoi(t.substr(0, iter));  //전화 시작 시각
  int m = stoi(t.substr(iter + 1)); //전화 시작 분

  //전화 시간 반영
  if ((m + d) >= 60)
  {
    h = (h + 1) % 24;
    m = m + d - 60;
  }
  else
  {
    m += d;
  }

  //6시대에 전화를 시작하여 7시대에 끝난 경우
  if (h == 7 && d > m)
  {
    return m * fee1 + (d - m) * fee2;
  }
  //18시대에 전화를 시작하여 19시대에 끝난 경우
  if (h == 19 && d > m)
  {
    return m * fee2 + (d - m) * fee1;
  }

  //같은 요금 구간 내에서 전화가 이뤄진 경우
  if (h >= 7 && h <= 18)
  {
    return d * fee1;
  }
  else
  {
    return d * fee2;
  }
}

int main()
{
  int n;
  cin >> n;

  int answer = 0, d;
  string start_t;

  while (n--)
  {
    cin >> start_t >> d;
    answer += calc(start_t, d);
  }

  cout << answer;
}