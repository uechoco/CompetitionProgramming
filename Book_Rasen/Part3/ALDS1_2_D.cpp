
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

void insertionSort(vector<int>& a, int n, int g, int& cnt) {
  for (int i = g; i < n; ++i) {
    const int v = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j+g] = a[j];
      j = j-g;
      ++cnt;
    }
    a[j+g] = v;
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n, 0);
  rep(i, n) {
    cin >> a[i];
  }

  int cnt = 0;
  vector<int> g;
  for(int h=1;;) {
    if (h > n) {
      break;
    }
    g.push_back(h);
    h = 3*h + 1;
  }
  reverse(g.begin(), g.end());

  int m = (int)g.size();
  rep(i,m) {
    insertionSort(a, n, g[i], cnt);
  }

  cout << m << endl;
  rep(i,m) {
    if (i > 0) cout << " ";
    cout << g[i];
  }
  cout << endl << cnt << endl;
  rep(i,n) {
    cout << a[i] << endl;
  }

  return 0;
}
