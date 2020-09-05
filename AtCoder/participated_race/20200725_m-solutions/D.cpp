
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
  int n; // 2 <= N <= 80
  cin >> n; // N日
  vector<int> a(n, 0); // 100 <= a <= 200
  vector<int> fixed;
  fixed.reserve(n);
  rep(i, n) {
    cin >> a[i];
  }

  // 単調増加・単調減少を間引く
  int point = a[0];
  fixed.push_back(a[0]);
  vector<int> stack;
  int way = -2;
  for (int i = 1; i < n; ++i) {
    //cout << "way=" << way << ",a[i]=" << a[i] << endl;
    if (way == -2) {
      if (point == a[i]) {
        way = 0;
      } else if (point < a[i]) {
        way = 1;
      } else {
        way = -1;
      }
      stack.push_back(a[i]);
      point = a[i];
    } else {
      if (way == 0) {
        if (point != a[i]) {
          stack.clear();
          stack.push_back(a[i]);
          if (point < a[i]) {
            way = 1;
          } else {
            way = -1;
          }
          point = a[i];
        }
      } else if (way == 1) {
        if (point < a[i]) {
          stack.clear();
          stack.push_back(a[i]);
        } else if (point > a[i]) {
          fixed.insert(fixed.end(), stack.begin(), stack.end());
          stack.clear();
          stack.push_back(a[i]);
          way = -1;
          point = a[i];
        }
      } else if (way == -1) {
        if (point > a[i]) {
          stack.clear();
          stack.push_back(a[i]);
        } else if (point < a[i]) {
          fixed.insert(fixed.end(), stack.begin(), stack.end());
          stack.clear();
          stack.push_back(a[i]);
          way = 1;
          point = a[i];
        }
      }
    }
  }
  if (stack.size() > 0 && way != 0) {
    fixed.insert(fixed.end(), stack.begin(), stack.end());
  }

  if (fixed.size() >= 2 && fixed[0] > fixed[1]) {
    fixed.erase(fixed.begin());
  }

  int money = 1000;
  int stock = 0;

  if (fixed.size() == 1) {
    cout << money << endl;
    return 0;
  }

  point = -1;
  int last = -1;
  rep (i, fixed.size()) {
    cout << "[" << i << "]:" << fixed[i] << endl;
    if (point == -1) {
      point = fixed[i];
    } else {
      last = point;
      point = fixed[i];
      if (last < point) {
        stock = money / last;
        money -= last * stock;
      } else {
        money += stock * last;
        stock = 0;
      }
    }
    cout << "[" << i << "]money:" << money << ",stock:" << stock << endl;
  }
  if (stock > 0) {
    money += stock * point;
  }
  cout << money << endl;
  return 0;
}
