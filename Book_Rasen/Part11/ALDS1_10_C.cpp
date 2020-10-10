
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
#define rep2(i, startValue, N) for (int i = (int)(startValue); i < (int)(N); ++i)
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
#define DUMP(v) "," #v ":" << v

int main(){
  int q;
  cin >> q;

  rep(iii,q) {
    string x, y;
    cin >> x >> y;
    const int xl = (int)x.size();
    const int yl = (int)y.size();
    x = ' ' + x;
    y = ' ' + y;

    VECTOR_DIM2(int, dp, xl + 1, yl + 1, 0);

    // dp[0][0] = 0;
    // rep(i,xl) dp[i][0] = 0;
    // rep(j,yl) dp[0][j] = 0;

    rep2(i,1,xl+1) {
      rep2(j,1,yl+1) {
        if (x[i] == y[j]) {
          dp[i][j] = dp[i-1][j-1] + 1;
        } else {
          dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
      }
    }

    cout << dp[xl][yl] << endl;
  }

  return 0;
}
