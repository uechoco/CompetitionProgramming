
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

// c.f. DSL_1_A: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=ja
// c.f. https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396
template<typename T>
struct UnionFind {
  std::vector<T> parent; // parent[i] ... iの親の番号

  // 森の初期化。最初はすべての要素が根(互いに素、互いに独立した木)であるとして初期化する
  UnionFind(T N) {
    parent.resize((static_cast<std::size_t>(N)));
    for (T i = 0; i < N; ++i) {
      parent[i] = i;
    }
  }
  // データxが属する木における根を再帰的に探索する。同時に経路圧縮を行う。
  T root(T x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = root(parent[x]);
  }
  // xとyの属する木を併合する
  void unite(T x, T y) {
    const T rx = root(x);
    const T ry = root(y);
    if (rx == ry) {
      return; // 根が一緒なのですでに同じ木に属している
    }
    parent[rx] = ry; // xの根rxをyの根ryに紐付ける
  }
  // データが同じ木に属しているかを判定する
  bool same(T x, T y) {
    const T rx = root(x);
    const T ry = root(y);
    return rx == ry;
  }
};

/*
入力例
5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0

出力例
0
0
1
1
1
0
1
1

*/

int main(){
  int n, q;
  cin >> n >> q;

  UnionFind<int> uf(n);
  rep(i,q) {
    int cmd, x, y;
    cin >> cmd >> x >> y;
    if (cmd == 0) { // unite
      uf.unite(x,y);
    } else if (cmd == 1) { // same
      cout << (uf.same(x,y) ? 1 : 0) << endl;
    }
  }

  return 0;
}
