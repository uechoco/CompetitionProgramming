
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

void dump(const vector<int>& a) {
  if (a.size() == 0) {
    return;
  }
  cout << a[0];
  rep2(i,1,a.size()) {
    cout << " " << a[i];
  }
  cout << endl;
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n, 0);
  rep(i, n) {
    cin >> a[i];
  }
  rep2(i,1,n) {
    dump(a);
    const int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      --j;
    }
    a[j+1] = v;
  }
  dump(a);
  return 0;
}
