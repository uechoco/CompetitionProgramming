
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


int main(){
  ll n, m;
  cin >> n >> m;
  int nextcircleno = 0;
  vector<int> circleno(n+1,0); // 0番目は空き (index+1 -> circleno)
  unordered_map<int, unordered_set<int>> circlemap; // circleno -> index+1
  int a, b;
  rep(i,m) {
    cin >> a >> b;
    const int cnoA = circleno[a];
    const int cnoB = circleno[b];
    if (cnoA != 0 && cnoB != 0) {
      if (cnoA == cnoB) {
        // 同じサークル同士
      } else {
        // 別々だと思っていたサークルを合体させる
        int fromcircleno = cnoB;
        int tocircleno = cnoA;
        if (circlemap[fromcircleno].size() > circlemap[tocircleno].size()) {
          std::swap(fromcircleno, tocircleno);
        }
        const auto& fromset = circlemap[fromcircleno];
        circlemap[tocircleno].insert(fromset.begin(), fromset.end());
        for (const auto& elem : fromset) {
          circleno[elem] = tocircleno;
        }
        circlemap.erase(fromcircleno);
      }
    } else if (cnoA == 0 && cnoB != 0) {
      circleno[a] = cnoB;
      circlemap[cnoB].emplace(a);
    } else if (cnoA != 0 && cnoB == 0) {
      circleno[b] = cnoA;
      circlemap[cnoA].emplace(b);
    } else {
      ++nextcircleno;
      circleno[a] = nextcircleno;
      circleno[b] = nextcircleno;
      circlemap[nextcircleno].emplace(a);
      circlemap[nextcircleno].emplace(b);
    }
  }

  ll maxmember = 0;
  if (circlemap.size() == 0) {
    maxmember = 1; // サークルがないので1つのグループに収める
  } else {
    for(const auto& p : circlemap) {
      const int membernum = p.second.size();
      if (maxmember < membernum) {
        maxmember = membernum;
      }
    }
  }
  cout << maxmember << endl;
  return 0;
}
