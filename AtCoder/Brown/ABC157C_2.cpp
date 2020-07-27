
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

// nのketa桁目の数値を取得する。ketaは1以上の整数である必要がある。
template <typename T>
int get_digit(T n, int keta) {
  for(int i = 1; i < keta; ++i) {
    n /= 10;
  }
  return n % 10;
}

// ABC157 C - Guess The Number
int main(){
  int n, m; // 1 <= N <= 3, 0 <= M <= 5
  cin >> n >> m;

  vector<int> ss(n, 0);
  vector<int> cc(n, 0);
  rep(i,m) {
    cin >> ss[i] >> cc[i];
  }
  int minI = 0;
  switch (n) {
    case 1:
      minI = 0;
      break;
    case 2:
      minI = 10;
      break;
    case 3:
      minI = 100;
      break;
  }
  for (int i = minI; i < 1000; ++i) {
    std::string ns = to_string(i);
    bool hit = true;
    rep(j,m) {
      const int rightDigit = n - ss[j] + 1;
      const int d = get_digit(i, rightDigit);
      if (cc[j] != d) {
        hit = false;
        break;
      }
    }
    if (hit) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
