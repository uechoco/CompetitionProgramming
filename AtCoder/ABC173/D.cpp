
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
  ll n;
  cin >> n;
  vector<ll> ai(n, 0); // フレンドリーさ
  rep(i,n) {
    cin >> ai[i];
  }
  sort(ai.begin(), ai.end(), std::greater<ll>());

  std::list<ll> ring;
  int lastspartn = (n-1)/2;

  ll ans = 0;
  ll left = 0;
  ll right = 0;
  bool first = true;
  std::list<ll>::iterator itr;
  rep(i, n) {
    if (i <= lastspartn) {
      if (i == 0) {
        left = ai[i];
        right = ai[i];
        ring.push_back(ai[i]);
      } else if (i % 2 == 1) {
        ans += min(left, right);
        left = ai[i];
        ring.push_front(ai[i]);
      } else {
        ans += min(left, right);
        right = ai[i];
        ring.push_back(ai[i]);
      }
    } else {
      if (first) {
        itr = ring.begin();
      }
      auto v1 = (*itr);
      auto v2 = (*(++itr));
      ans += min(v1, v2);
    }
    //cout << "ai[i]=" << ai[i] << ",ans:" << ans << ",left=" << left << ",right=" << right <<  endl;
  }

  cout << ans << endl;
  return 0;
}
