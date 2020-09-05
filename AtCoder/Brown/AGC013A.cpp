
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

// AGC013 A - Sorted Arrays
int main(){
  ll n;
  cin >> n;
  vector<ll> A(n,0);
  rep(i,n) cin >> A[i];

  ll count = 0; // divided count

  int way = 0;
  ll num = 0;
  ll last = LONG_LONG_MIN;
  rep (i,n) {
    if (num == 0) {
      last = A[i];
      way = 0;
      ++num;
    } else if (num > 0 && way == 0) {
      ++num;
      if (last == A[i]) {
        continue; // 方向性定まらず
      } else if (last < A[i]) {
        way = 1;
        last = A[i];
      } else {
        way = -1;
        last = A[i];
      }
    } else {
      if (way == 1 && last > A[i] || way == -1 && last < A[i]) {
        ++count;
        way = 0;
        num = 1;
        last = A[i];
      } else {
        ++num;
        last = A[i];
      }
    }
  }

  cout << count + 1 << endl;

  return 0;
}
