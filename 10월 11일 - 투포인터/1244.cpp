#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

void turnMultiples(int num, int n, vector<bool> &switches)
{
  int idx = num;

  while (idx <= n)
  {
    switches[idx] = !switches[idx];
    idx += num;
  }
}

void flipMax(int num, int n, vector<bool> &switches)
{
  switches[num] = !switches[num];

  int under = num - 1, upper = num + 1;

  while (under >= 1 && upper <= n)
  {
    if (switches[under] != switches[upper])
    {
      break;
    }
    switches[under] = !switches[under];
    switches[upper] = !switches[upper];
    under--;
    upper++;
  }
}

int main()
{
  int s_n, st_n, input;
  cin >> s_n;

  vector<bool> switches(s_n + 1, false); //스위치 상태 저장하는 배열. true면 켜져 있는 것.

  for (int i = 1; i <= s_n; i++)
  {
    cin >> input;
    if (input)
    {
      switches[i] = true;
    }
  }

  cin >> st_n;

  vector<ci> students(st_n, {0, 0});

  for (int i = 0; i < st_n; i++)
  {
    cin >> students[i].first >> students[i].second;
  }

  for (auto student : students)
  {
    //남학생인 경우
    if (student.first == 1)
    {
      turnMultiples(student.second, s_n, switches);
    }
    //여학생인 경우
    else
    {
      flipMax(student.second, s_n, switches);
    }
  }

  for (int i = 1; i <= s_n; i++)
  {
    cout << switches[i] << " ";

    if (i % 20 == 0)
    {
      cout << "\n";
    }
  }
}