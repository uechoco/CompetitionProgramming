
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

int parentNode(int i) { return i / 2; }
int leftNode(int i) { return i * 2; }
int rightNode(int i) { return i * 2 + 1; }

int main(){
  int n;
  cin >> n;
  vector<int> A(n+1);
  rep2(i, 1, n + 1) cin >> A[i];


  rep2(i, 1, n + 1) {
    cout << "node " << i << ": key = " << A[i] << ", ";
    const int pi = parentNode(i);
    const int li = leftNode(i);
    const int ri = rightNode(i);
    if (pi >= 1) cout << "parent key = " << A[pi] << ", ";
    if (li <= n) cout << "left key = " << A[li] << ", ";
    if (ri <= n) cout << "right key = " << A[ri] << ", ";
    cout << endl;
  }

  return 0;
}
