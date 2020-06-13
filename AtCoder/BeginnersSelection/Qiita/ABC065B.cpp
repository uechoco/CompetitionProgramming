#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
// syntax sugar: `for (int i = 0; i < N; ++i)`
#define REP(type, name, beginValue, endCondValue) \
  for (type name = beginValue; name < endCondValue; ++name)
// syntax sugar: 多次元vector
#define VECTOR_DIM3(T, name, d1, d2, d3, initValue) \
    std::vector<std::vector<std::vector<T>>> name(d1, std::vector<std::vector<T>>(d2, std::vector<int>(d3, initValue)));
#define VECTOR_DIM2(T, name, d1, d2, initValue) \
    std::vector<std::vector<T>> name(d1, std::vector<T>(d2, initValue));
#define VECTOR_DIM1(T, name, d1, initValue) \
    std::vector<T> name(d1, initValue);
#define ll long long
#define ld long double


// ABC065B - Trained?
int main(){
  int N; // 2 <= N <= 1e5
  cin >> N;
  VECTOR_DIM1(int, ai, N+1, 0);
  bool has2 = false;
  rep(i, N) {
    cin >> ai[i+1];
    if (ai[i+1] == 2) {
      has2 = true;
    }
  }
  if (!has2) {
    cout << -1 << endl;
    return 0;
  }
  // 1度押したのに到達すると、ループするので-1

  // dp[i] = ボタンiが光るのに必要な最小回数
  VECTOR_DIM1(int, dp, N+10, INT_MAX);
  dp[1] = 0; // 最初からボタン1が光っている

  // dp[2] に 有効な数字があれば、それが答え
  bool loop = true;
  int pos = 1, bpos = 1;
  rep(i, N) {
    bpos = pos;
    pos = ai[pos];
    if (dp[pos] != INT_MAX) {
     // cout << "再訪" << endl;
      break; // 再訪
    }
    dp[pos] = dp[bpos] + 1;
    if (pos == 2) {
      //cout << "pos2 i:" << i << ",pos:" << pos << endl;
      break;
    }
    //cout << "i:" << i << ",pos:" << pos << endl;
  }

  cout << ((dp[2] < INT_MAX) ? dp[2] : -1) << endl;
  return 0;
}

