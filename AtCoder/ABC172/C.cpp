
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


int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> ai(n,0), bi(m,0);
  vector<ll> ta(n+10,0), tb(m+10,0);

  ll a, b;
  rep(i,n){
    cin >> ai[i];
  }
  rep(i,m) {
    cin >> bi[i];
  }
  //reverse(ai.begin(), ai.end());
  //reverse(bi.begin(), bi.end());
  rep(i,n+1){
    if (i > 0) {
      ta[i] = ta[i-1] + ai[i-1];
    } else {
      ta[i] = 0;
    }
  }
  rep(i,m+1){
    if (i > 0) {
      tb[i] = tb[i-1] + bi[i-1];
    } else {
      tb[i] = 0;
    }
  }

  ll ans = 0;
  ll jbest = m;
  rep(i,n+1) {
    if (ta[i] > k) {
      break;
    }
    while (tb[jbest] > k - ta[i]) {
      --jbest;
    }
    ans = max(ans, i+jbest);
  }

  cout << (ans) << endl;
  return 0;
}
