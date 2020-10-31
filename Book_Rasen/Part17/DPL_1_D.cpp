
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
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i,n) cin >> A[i];

  vector<int> L(n);
  int len = 0;
  // L[n]: L[i]を長さがi+1であるような増加部分列の最後の要素を最小値とする配列
  // len: i番目の要素までを使ったLIS(最長増加部分列)の長さを表す整数

  L[0] = A[0];
  len = 1;
  rep2(i,1,n) {
    if (L[len-1] < A[i]) {
      L[len++] = A[i];
    } else {
      auto itr = lower_bound(L.begin(), L.begin()+len, A[i]);
      *itr = A[i];
      // Lの途中経過は必ずしもLISそのものを表すわけではない。
      // L[len-1]とlenだけはLISのものを表す。
    }
  }

  cout << len << endl;

  return 0;
}
