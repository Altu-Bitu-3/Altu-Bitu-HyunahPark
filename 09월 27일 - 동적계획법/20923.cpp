//참고한 블로그 링크 : https://seastar105.tistory.com/75
//deque 배열의 인덱스를 이용해 코드를 효율적으로 간소화시킨 아이디어를 참고
#include <iostream>
#include <deque>

using namespace std;

deque<int> deck[2], ground[2];

int check()
{
  //도도가 종을 칠 수 있는 경우
  if (ground[0].size() && ground[0].back() == 5)
    return 0;
  if (ground[1].size() && ground[1].back() == 5)
    return 0;

  //수연이가 종을 칠 수 있는 경우
  if (ground[0].size() && ground[1].size() && ground[0].back() + ground[1].back() == 5)
    return 1;

  //그외
  return -1;
}

int main()
{
  int n, m, x, y;
  cin >> n >> m;

  while (n--)
  {
    cin >> x >> y;
    deck[0].push_front(x);
    deck[1].push_front(y);
  }

  int turn = 0;

  while (m--)
  {
    ground[turn].push_back(deck[turn].front());
    deck[turn].pop_front();

    //게임 진행 도중 deck의 카드 수가 0개가 되는 경우
    if (deck[turn].empty())
    {
      break;
    }

    //종을 칠 수 있는 사람을 확인
    int w = check();

    //종을 쳤다면 카드 더미를 합친다
    if (w != -1)
    {
      deck[w].insert(deck[w].end(), ground[1 - w].begin(), ground[1 - w].end());
      deck[w].insert(deck[w].end(), ground[w].begin(), ground[w].end());
      ground[1 - w].clear();
      ground[w].clear();
    }

    turn = 1 - turn;
  }

  //이긴 사람 체크
  if (deck[0].size() >= deck[1].size())
    cout << "do";
  if (deck[0].size() <= deck[1].size())
    cout << "su";
}