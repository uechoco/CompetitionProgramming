
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

struct Elem {
  ll x;
  ll y;
  ll d0;
};

int getJigen(ll x, ll y) {
  if (x >= 0) {
    if (y >= 0) {
      return 0;
    } else {
      return 3;
    }
  } else {
    if (y >= 0) {
      return 1;
    } else {
      return 2;
    }
  }
}

int main(){
  ll n;
  cin >> n;
  unordered_map<int, vector<Elem>> jigens;
  jigens[0];
  jigens[1];
  jigens[2];
  jigens[3];
  ll x, y;
  rep(i,n) {
    cin >> x >> y;
    int jigen = getJigen(x, y);
    Elem e;
    e.x = x;
    e.y = y;
    e.d0 = abs(x) + abs(y);
    jigens[jigen].push_back(e);
  }

  for (int i = 0; i < 4; ++i) {
    sort(jigens[i].begin(), jigens[i].end(), [](const Elem& a, const Elem& b){ return a.d0 < b.d0; });
  }

  vector<Elem> can;
  for (int i = 0; i < 4; ++i) {
    if (jigens[i].size() >= 2) {
      can.push_back(jigens[i].front());
      can.push_back(jigens[i].back());
    } else if (jigens[i].size() == 1) {
      can.push_back(jigens[i].front());
    }
  }

  ll ans = 0;
  int s = (int)can.size();
  for (int i = 0; i < s; ++i) {
    for (int j = 0; j < s; ++j) {
      if (i == j) continue;
      ll d1 = abs(can[i].x - can[j].x) + abs(can[i].y - can[j].y);
      if (ans < d1) {
        ans = d1;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
