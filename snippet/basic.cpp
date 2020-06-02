
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(n); ++i)

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define REP(type, name, beginValue, endCondValue) \
  for (type name = beginValue; name < endCondValue; ++name)

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
