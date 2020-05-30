
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define REP(T, name, beginValue, endCondValue) \
  for (T name = beginValue; name < endCondValue; ++name)

int main(){
  int r, c;
  cin >> r >> c;
  REP(int, i, 0, r) {
    REP(int, j, 0, c) {
      cout << i * j << endl;
    }
  }
  return 0;
}
