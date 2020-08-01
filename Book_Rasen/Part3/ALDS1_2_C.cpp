
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

void dump(const vector<string>& a) {
  rep(i,a.size()) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

bool isStable(const vector<string>& stableA, const vector<string>& checkB) {
  rep(i, stableA.size()) {
    if (stableA[i] != checkB[i]) {
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  vector<string> a(n, "");
  rep(i, n) {
    cin >> a[i];
  }

  // bubble sort
  auto ba = a; // copy
  rep(i,n) {
    for(int j = n-1; j >= i+1; --j) {
      if (ba[j][1] < ba[j-1][1]) {
        swap(ba[j], ba[j-1]);
      }
    }
  }

  dump(ba);
  cout << "Stable" << endl;

  // selection sort
  auto sa = a; // copy
  rep(i,n) {
    int minj = i;
    for (int j = i; j < n; ++j) {
      if (sa[j][1] < sa[minj][1]) {
        minj = j;
      }
    }
    if (i != minj) {
      swap(sa[i], sa[minj]);
    }
  }

  dump(sa);
  cout << (isStable(ba, sa) ? "Stable" : "Not stable") << endl;

  return 0;
}
