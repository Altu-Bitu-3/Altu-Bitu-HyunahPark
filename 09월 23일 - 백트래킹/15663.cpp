#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX = 1e4;
const int SIZE = 8;

int n, m;
vector<int> nums(SIZE);   //숫자 저장
vector<int> counts(MAX);  //숫자별 개수 저장
vector<int> output(SIZE); //출력할 조합 저장
vector<int> check(MAX);   //숫자별 선택한 횟수 저장

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

    //해당 숫자를 입력받은 횟수보다 더 적게 선택한 경우
    //출력할 숫자 수보다 같은 숫자를 선택한 횟수가 적은 경우(같은 숫자를 더 선택할 수 있음)
    if (check[k] < counts[k] && check[k] < m)
    {
      output[cnt] = k;
      check[k]++;
      backtracking(cnt + 1);
      check[k]--;
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