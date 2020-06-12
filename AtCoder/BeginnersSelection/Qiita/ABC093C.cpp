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


// ABC093C - Same Integers
int main(){
  int a[3]; // 0 <= n <= 50
  vector<int> d(3, 0);
  cin >> d[0] >> d[1] >> d[2];

  std::sort(d.begin(), d.end(), greater<int>());
  const int maxNum = d[0];
  const int diff = 3 * maxNum - (d[0] + d[1] + d[2]);

  int num = 0;
  if (d[1] > d[2]) {
    const int inc = (d[1] - d[2]) / 2;
    d[2] += 2 * inc;
    num += inc;
  }
  if (d[0] > d[1]) {
    const int inc = (d[0] - d[1]);
    d[1] += inc;
    d[2] += inc;
    num += inc;
  }
  if (d[0] == d[1] && d[1] == d[2]) {
    cout << num << endl;
  } else {
    cout << num + 2 << endl;
  }
  return 0;
}

