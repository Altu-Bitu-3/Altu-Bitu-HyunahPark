#include <iostream> //입출력 라이브러리
#include <deque>    //deque 자료구조 사용

using namespace std;

/**
 * [힌트] 벨트의 회전과 로봇의 이동을 인덱스로 관리해볼까요?
 * 1단계(rotate()): 벨트 회전 + n번째 칸 로봇 내리기
 * 2단계(move())  : 로봇 이동시키기 + n번째 칸 로봇 내리기
 * 3단계(put())   : 1번째 칸에 로봇 올리기
 */

struct info
{
  int power; //벨트의 내구도
  int robot; //벨트 위 로봇 존재 여부(1: 존재o, 0:존재x)
};

/**1단계*/
void rotate(deque<info> &belt, int n)
{
  //벨트 회전
  belt.push_front(belt.back()); //맨 뒤에 있던 로봇을 맨 앞에 푸쉬
  belt.pop_back();              //맨 뒤에 있던 로봇 삭제

  //n번째 칸 로봇 내리기
  if (belt[n - 1].robot)
  {                      //n번째 칸에 로봇이 있다면
    belt[n - 1].robot--; //로봇 내리기
  }
}

/**2단계*/
void move(deque<info> &belt, int n)
{ //로봇 이동시키기
  /*
  * [로봇 이동을 위한 조건]
  * 1. 현재 칸에 로봇이 존재하고(belt[i].robot)
  * 2. 다음 칸에 로봇이 존재하지 않고(!belt[i+1].robot)
  * 3. 다음 칸의 내구도가 1 이상일 때(belt[i].power)
  * 
  * 이때 가장 먼저 올라간 로봇은 가장 뒤에 존재! -> 뒤에서부터 접근하기
  */

  int cur = 2 * n - 1, next; //cur:현재 칸, next: 다음 칸
  while (cur >= 0)
  {                             //먼저 올라간 로봇부터 옮기기 시작
    next = (cur + 1) % (2 * n); //다음 칸 인덱스 설정
    if (belt[cur].robot && !belt[next].robot && belt[next].power)
    {                     //로봇을 이동시킬 수 있는 경우
      belt[cur].robot--;  //현재 칸에서 로봇을 옮겨서
      belt[next].robot++; //다음 칸으로 로봇을 이동시킴
      belt[next].power--; //로봇을 이동시킴에 따라 내구도 감소
    }

    cur--; //그 다음에 올라간 로봇에 대해 다시 시행
  }

  //n번째 칸 로봇 내리기
  if (belt[n - 1].robot)
  {                      //로봇이 있다면
    belt[n - 1].robot--; //로봇을 내림
  }
}

/**3단계*/
void put(deque<info> &belt)
{
  //첫 번째 칸에 로봇 올리기
  if (belt[0].power)
  {                  //첫 번째 칸에 내구도가 1 이상이라면
    belt[0].robot++; //첫 번째 칸에 로봇을 올리고
    belt[0].power--; //로봇을 올림에 따라 내구도 감소
  }
}

int countZero(deque<info> &belt, int n)
{              //벨트에서 내구도가 0인 칸 세기
  int cnt = 0; //내구도가 0인 칸을 셀 변수
  for (int i = 0; i < 2 * n; i++)
  { //모든 칸에 대해 시행
    if (belt[i].power == 0)
    {        //해당 칸의 내구도가 0이라면
      cnt++; //개수 증가
    }
  }

  return cnt; //결과값 반환
}

int main()
{
  //cin, cout 속도를 향상시키기 위하여 사용
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  //n과 k 입력받기
  int n, k;
  cin >> n >> k;
  deque<info> belt(2 * n, {0, 0}); //벨트 초기화

  for (int i = 0; i < 2 * n; i++)
  {
    cin >> belt[i].power; //벨트 내구도 입력받기
  }

  int stage = 0; //현재 진행 중인 단계
  do
  {
    rotate(belt, n);                //벨트 회전
    move(belt, n);                  //로봇 이동
    put(belt);                      //로봇 올리기
    stage++;                        //단계 증가
  } while (countZero(belt, n) < k); //내구도가 0인 칸이 k개 미만일 동안 시행

  cout << stage; //몇 번째 단계인지 출력
}