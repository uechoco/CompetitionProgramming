#include <bits/stdc++.h>
using namespace std;

// ABC087B - Coins
/*
 500 A 100 B 50 C
 これらの硬貨の中から何枚かを選び、合計金額をちょうど X円にする方法は何通りありますか。
 同じ種類の硬貨どうしは区別できません。2 通りの硬貨の選び方は、ある種類の硬貨についてその硬貨を選ぶ枚数が異なるとき区別されます。
*/
int main(){
  int a, b, c, x;
  cin >> a >> b >> c >> x;

  int cnt = 0;
  for (int ai = a; ai >= 0; --ai) {
    int asum = ai * 500;
    if (asum > x) {
      continue;
    }
    int arest = x - asum;
    for (int bi = b; bi >= 0; --bi) {
      int bsum = bi * 100;
      if (bsum > arest) {
        continue;
      }
      int brest = arest - bsum;
      if (brest == 0) {
        ++cnt; // no choise c
      } else if (brest / 50 <= c) {
        ++cnt;
      }
    }
  }

  cout << cnt << endl;
  return 0;
}
