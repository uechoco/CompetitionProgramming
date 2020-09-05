
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
  int a, b, c, k; // 1 <= n <= 7
  cin >> a >> b >> c >> k;

  // A < B < C
  bool succeeded = false;
  int n = 0;
  while (n++ < k) {
    if (a >= b) {
      b *= 2;
      //cout << "n:" << n << "=" << a << "," << b << "," << c << endl;
      if (a < b && b < c) {
        succeeded = true;
        break;
      }
      continue;
    }
    if (b >= c) {
      c *= 2;
      //cout << "n:" << n << "=" << a << "," << b << "," << c << endl;
      if (a < b && b < c) {
        succeeded = true;
        break;
      }
      continue;
    }
    if (a < b && b < c) {
        succeeded = true;
        break;
    }
  }
  //cout << a << "," << b << "," << c << endl;


  cout << (succeeded ? "Yes" : "No") << endl;
  return 0;
}
