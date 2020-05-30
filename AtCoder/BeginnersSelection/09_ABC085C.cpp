#include <bits/stdc++.h>
using namespace std;

// ABC085C - Otoshidama
// 10000, 5000, 1000
// 10, 5, 1
// 1 <= N <= 2000 枚
// 合計 Y 円

int main(){
  int n, y;
  cin >> n >> y;
  y /= 1000;

  bool found = false;
  for (int ai = (y/10 >= 2000 ? 2000 : y/10); ai >= 0; --ai) {
    int asum = ai * 10; // 10000
    if (asum > y) {
      continue;
    }
    int arest = y - asum;
    for (int bi = (arest/5 >= n-ai ? n-ai : arest/5); bi >= 0; --bi) {
      int bsum = bi * 5; // 5000
      if (bsum > arest) {
        continue;
      }
      int brest = arest - bsum;
      if (brest == n-ai-bi) {
        cout << ai << " " << bi << " " << brest << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}
