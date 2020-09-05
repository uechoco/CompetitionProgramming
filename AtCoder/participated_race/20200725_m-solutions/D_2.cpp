
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
  int n; // 2 <= N <= 80
  cin >> n; // N日
  vector<int> a(n+1, 0); // 100 <= a <= 200
  rep(i, n) {
    cin >> a[i];
  }
  ll money = 1000;
  ll stock = 0;

  int last = a[0];
  for(int i = 1; i < n+1; ++i) {
    const int ai = a[i];
    if (last < ai) { // 上がる
      stock += money / last;
      money -= (money / last) * last;
    } else if (last > ai) {
      money += stock * last;
      stock = 0;
    }
    last = ai;
  }
  cout << money << endl;
  return 0;
}
