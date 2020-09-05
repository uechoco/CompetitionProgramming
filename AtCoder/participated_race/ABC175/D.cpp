
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
  ll n, k;
  cin >> n >> k;
  vector<ll> pn(n, 0);
  vector<ll> cn(n, 0);
  rep(i,n) cin >> pn[i];
  rep(i,n) cin >> cn[i];

  vector<vector<ll>> candidates;

  vector<int> used(n,0);
  while (true){
    int first_i = -1;
    rep(i,n) {
      if (used[i] == 0){
         first_i = i;
         break;
      }
    }
    if (first_i == -1) {
      break; // while抜ける
    }

    vector<ll> candidate;
    int i = first_i;
    while(used[i]==0) {
      used[i] = 1;
      candidate.emplace_back(cn[i]);
      i = pn[i]-1;
    }

    candidates.emplace_back(candidate);
  }

  // デバッグ出力
  // candidate:3,4,-8,
  // candidate:-10,8,
  /*
  for (const auto& c: candidates) {
    cout << "candidate:";
    for (const auto& i: c) {
      cout << i << ",";
    }
    cout << endl;
  }
  */

  ll ans = LONG_LONG_MIN; // Ciの最小値より低い
  // 各candidateの中で、1以上k以下の連続する数列の最大値を求める
  for (const auto& candidate: candidates) {
    const ll suulen = (ll)candidate.size();
    const ll suusum = std::accumulate(candidate.cbegin(), candidate.cend(), 0LL);
    vector<ll> suuretu = candidate;
    suuretu.insert(suuretu.end(), candidate.begin(), candidate.end());

    ll tmax = LONG_LONG_MIN;
    {// 1区間最大値を求める

      const ll tlen = min(k, suulen);
      for (int i = 0; i < suulen; ++i) {
        ll tmpmax = LONG_LONG_MIN;
        ll tmpsum = 0;
        for (int j = i; j < tlen; ++j) {
          tmpsum += suuretu[j];
          if (tmpmax < tmpsum) {tmpmax = tmpsum;}
        }
        if (tmax < tmpmax) {tmax = tmpmax;}
      }
    }

    //cout << "tmax:" << tmax << ",suusum:" << suusum << ",suulen:" << suulen<< endl;

    ll overtmax = LONG_LONG_MIN;
    if (suusum > 0 && k > suulen) {
      // 最終的な合計値 と 1区間最大値のどっちが大きいかは確認すること
      ll loopsum = (k / suulen) * suusum;
      ll restk = k % suulen;

      ll tmpmax = LONG_LONG_MIN;
      for (int i = 0; i < suulen; ++i) {
        ll tmpsum = 0;
        for (int j = i; j < i+restk; ++j) {
          tmpsum += suuretu[j];
        }
        //cout << "tmpmax:" << tmpmax << ",tmpsum:" << tmpsum << endl;
        if (tmpmax < tmpsum) {
          tmpmax = tmpsum;
          //cout << "update tmpmax i:" << i << ",restk:" << restk << ",tmpmax" << tmpmax << endl;
        }
      }

      overtmax = loopsum + tmpmax;

      //cout << "overtmax:" << overtmax << ",loopsum:" << loopsum << ",tmpmax" << tmpmax << ",restk" << restk << endl;
    }

    // ans比較
    if (ans < max(tmax, overtmax)) {
      ans = max(tmax, overtmax);
    }
  }

  cout << ans << endl;
  return 0;
}
