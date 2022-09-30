#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX = 1e4;
const int SIZE = 8;

int n, m;
vector<int> nums(SIZE);   //숫자 저장
vector<int> counts(MAX);  //숫자별 사용할 수 있는 개수 저장
vector<int> output(SIZE); //출력할 조합 저장

void backtracking(int cnt)
{
  //m개를 모두 골랐을 떄
  if (cnt == m)
  {
    //선택한 숫자들을 출력
    for (int i = 0; i < cnt; i++)
    {
      cout << output[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; i++)
  {
    int k = nums[i];

    //해당 숫자를 사용할 수 있는 경우
    if (counts[k])
    {
      output[cnt] = k;
      counts[k]--;
      backtracking(cnt + 1);
      counts[k]++;
    }
  }
}

int main()
{
  int input;
  cin >> n >> m;

  set<int> s;

  for (int i = 0; i < n; i++)
  {
    cin >> input;
    s.insert(input);
    counts[input]++;
  }

  //중복 제거 및 정렬을 위해 set으로 입력받은 후 할당
  nums.assign(s.begin(), s.end());

  backtracking(0);
}
