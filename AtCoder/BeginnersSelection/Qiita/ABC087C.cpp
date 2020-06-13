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


// ABC087C - Candies
int main(){
  int N;
  cin >> N;
  VECTOR_DIM2(int, a, 2, N, INT_MAX);
  rep(i,2){
    rep(j,N){
      cin >> a[i][j];
    }
  }

  int maxNum = 0;
  for (int n = 0; n < N; ++n) { // どこで下の列に降りるか
    int i = 0;
    int num = 0;
    for (int j = 0; j < N; ++j) {
      num += a[i][j];
      if (j == n) { // 降りる
        i = 1;
        num += a[i][j];
      }
      //cout << "n=" << n << ",j=" << j << ",num=" << num << endl;
    }
    if (maxNum < num) {
      maxNum = num;
    }
  }

  cout << maxNum << endl;
  return 0;
}

