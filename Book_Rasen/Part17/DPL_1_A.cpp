
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
  int n, m;
  cin >> n >> m;
  vector<int> c(m);
  rep(i,m) cin >> c[i];

  // c[m]: c[i]をi番目のコインの額面とする配列
  // t[m][n+1]: t[i][j]をi番目までのコインを使ってj円支払うときのコインの最小枚数とする二次元配列

  VECTOR_DIM2(int, t, m, n+1, 0);
  rep(i,m) t[i][0] = 0;
  rep2(j,1,n+1) t[0][j] = INT_MAX; // 無限枚数必要とする

  rep(i,m) {
    rep2(j,1,n+1) {
      if (j-c[i] >= 0 && i-1 >= 0) {
        t[i][j] = min(t[i-1][j], t[i][j-c[i]]+1);
        //cout << "1.t[" << i << "][" << j << "]=" << t[i][j] << endl;
      } else if (j-c[i] >= 0) {
        t[i][j] = t[i][j-c[i]]+1;
        //cout << "2.t[" << i << "][" << j << "]=" << t[i][j] << endl;
      } else if (i-1 >= 0) {
        t[i][j] = t[i-1][j];
        //cout << "3.t[" << i << "][" << j << "]=" << t[i][j] << endl;
      }
    }
  }
  cout << t[m-1][n] << endl;

  return 0;
}
