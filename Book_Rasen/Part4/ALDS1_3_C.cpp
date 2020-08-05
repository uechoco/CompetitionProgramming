
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


int main(){
  ll n;
  cin >> n;

  string cmd;
  ll key;
  list<ll> dll;
  rep(i,n) {
    cin >> cmd;
    if (cmd == "insert") {
      cin >> key;
      dll.push_front(key);
    } else if (cmd == "delete") {
      cin >> key;
      auto itr = std::find(dll.begin(), dll.end(), key);
      if (itr != dll.end()) {
        dll.erase(itr);
      }
    } else if (cmd == "deleteFirst") {
      dll.pop_front();
    } else if (cmd == "deleteLast") {
      dll.pop_back();
    }
  }

  bool bFirst = true;
  for(const auto& v: dll) {
    if (!bFirst) cout << " ";
    if (bFirst) bFirst = false;
    cout << v;
  }
  cout << endl;

  return 0;
}
