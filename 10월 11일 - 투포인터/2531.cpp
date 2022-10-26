#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

int maxKinds(int k, int c, int n, vector<int> &dishes)
{
  map<int, int> section; //구간별 초밥 번호와 개수 카운트
  section[c]++;          //쿠폰으로 먹을 수 있는 초밥 추가
  for (int i = 0; i < k; i++)
  {
    section[dishes[i]]++; //처음 구간 초기화
  }

  int answer = section.size();

  for (int i = k; i < (n + k); i++) //회전가능하므로 n+k까지 확인해줘야 함
  {
    section[dishes[(i - k) % n]]--; //이전 접시는 빼고
    section[dishes[i % n]]++;       //새로운 접시 추가

    if (section[dishes[i - k]] == 0) //개수가 0인 초밥 번호 제거
    {
      section.erase(dishes[i - k]);
    }

    if (answer < section.size())
    {
      answer = section.size();
    }
  }

  return answer;
}

int main()
{
  int n, d, k, c;
  cin >> n >> d >> k >> c;

  vector<int> dishes(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> dishes[i];
  }

  cout << maxKinds(k, c, n, dishes);
}