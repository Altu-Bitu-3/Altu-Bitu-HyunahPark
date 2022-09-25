#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  int w_0, l_0, a_0 = 0, t;
  cin >> w_0 >> l_0 >> t;

  int d, l, a, w, w2, L, L2;
  cin >> d >> l >> a;

  //일일기초대사량 변화를 고려한 계산을 할 w2,L2,diff2 변수
  w = w_0;
  w2 = w_0;
  L = l_0;
  L2 = l_0;
  int diff = l - (L + a);
  int diff2 = diff;

  while (d--)
  {
    w += diff;
    w2 += diff2;

    //일일기초대사량 변화 반영
    if (abs(diff2) > t)
    {
      L2 += floor(diff2 / 2.0);
      diff2 = l - (L2 + a);
    }
  }

  //일일기초대사량 변화 고려 안 한 결과
  if (w <= 0 || L <= 0)
  {
    cout << "Danger Diet"
         << "\n";
  }
  else
  {
    cout << w << " " << L << "\n";
  }

  //일일기초대사량 변화 고려한 결과
  if (w2 <= 0 || L2 <= 0)
  {
    cout << "Danger Diet";
  }
  else
  {
    cout << w2 << " " << L2 << " ";
    if (L > L2)
    {
      cout << "YOYO";
    }
    else
    {
      cout << "NO";
    }
  }
}