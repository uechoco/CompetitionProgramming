
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

struct HashPair {
    //注意 constがいる
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {

        //first分をハッシュ化する
        auto hash1 = hash<T1>{}(p.first);

        //second分をハッシュ化する
        auto hash2 = hash<T2>{}(p.second);

        //重複しないようにハッシュ処理
        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

int main(){
  int n, q;
  cin >> n >> q;
  vector<int> col(n, 0);
  vector<int> qleft(q,0);
  vector<int> qright(q,0);
  rep(i,n) {
    cin >> col[i];
  }
  rep(i,q) {
    cin >> qleft[i] >> qright[i];
  }

  // 前処理

  // 使用範囲の印付
  vector<int> usedEdge(n,0);
  vector<int> usedRange(n,0);
  rep(i,q) {
    const int ql = qleft[i];
    const int qr = qright[i];
    usedEdge[ql-1]=1;
    usedEdge[qr-1]=1;
    if (ql == qr) {
      ++usedRange[ql-1];
    } else {
      for (int j = ql-1; j <= qr-1; ++j) {
        ++usedRange[j];
      }
    }
  }

  // 使用範囲でキャッシュの生成
  unordered_map<pair<int, int>, unordered_set<int>, HashPair> cache;
  {
    int el = -1;
    rep(i,n) {
      if (usedRange[i] > 0) {
        el = i;
        break;
      }
    }
    int er = -1;
    if (el != -1) {
      for (int i = el+1; i < n; ++i) {
        if (usedEdge[i]) {
          er = i;
          break;
        }
      }
    }

    while (el != -1 && er != -1 && el != er && el < n) {
      //cout << "caching: el:" << el << ",er:" << er << endl;
      unordered_set<int> sset;
      sset.reserve(er - el + 1);
      for(int j = el; j <= er; ++j) {
        sset.emplace(col[j-1]);
      }
      cache.emplace(make_pair(el, er),sset);

      el = er;
      er = el + 1;
      for (int i = el+1; i < n; ++i) {
        if (usedEdge[i]) {
          er = i;
          break;
        }
      }
    }
  }

/*
  for (const auto& p: cache) {
    cout << "cache:" << p.first.first << "-" << p.first.second << ":" << p.second.size() << endl;
  }
  return 0;
  */

  rep(i,q) {
    const int ql = qleft[i];
    const int qr = qright[i];
    if (ql == qr) {
      cout << 1 << endl;
      continue;
    }
    unordered_set<int> sset;
    sset.reserve(qr - ql + 1);

    {
      int el = ql;
      int er = -1;
      if (el != -1) {
        for (int i = el+1; i < n; ++i) {
          if (usedEdge[i]) {
            er = i;
            break;
          }
        }
      }

      while (el != -1 && er != -1 && el != er && er <= qr) {
        const auto& tmp = cache[make_pair(el, er)];
        sset.insert(tmp.cbegin(), tmp.cend());

        el = er;
        er = el + 1;
        for (int i = el+1; i < n; ++i) {
          if (usedEdge[i]) {
            er = i;
            break;
          }
        }
      }
    }
    cout << sset.size() << endl;
  }

  return 0;
}
