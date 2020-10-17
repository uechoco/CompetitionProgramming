
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

struct Point {
  int x;
};

struct Node {
  int location; // Pの位置
  int l;
  int r;
};

int make1DTree(int& np, vector<Point>& P, vector<Node>& T, int l, int r) {
    if (l >= r) {
      return -1;
    }

    // Pについて、l <= x < r の範囲を x について昇順に整列する
    sort(P.begin() + l, P.begin() + r, [](const Point& l, const Point& r)->bool{ return l.x < r.x; });

    const int mid = (l + r) / 2;
    const int t = np++; // 二分木のノード番号を設定
    T[t].location = mid; // Pにおける位置
    T[t].l = make1DTree(np, P, T, l, mid); // 前半で部分木を生成
    T[t].r = make1DTree(np, P, T, mid+1, r); // 後半で部分木を生成

    return t;
}

void find1DTree(vector<int>& ans, const vector<Point>& P, const vector<Node>& T, int sx, int tx, const int index) {
  const auto& node = T[index];
  const int x = P[node.location].x;
  // cout << DUMP(sx) << DUMP(tx) << DUMP(index) << DUMP(x) << endl;
  if (sx <= x && x <= tx) {
    ans.push_back(x);
  }

  if (node.l >= 0 && sx <= x) {
    find1DTree(ans, P, T, sx, tx, node.l);
  }

  if (node.r >= 0 && x <= tx) {
    find1DTree(ans, P, T, sx, tx, node.r);
  }
}

/*
入力値
10
16 10 1 3 14 5 21 6 13 19
1
6 15
*/

int main(){
  int n;
  cin >> n;

  int np = 0; // ノード番号
  vector<Node> T(n);
  vector<Point> P(n);
  rep(i,n) {
    cin >> P[i].x;
  }
  make1DTree(np,P,T,0,n);

  /*cout << endl;
  rep(i,n) {
    const auto& node = T[i];
    cout << DUMP(i) << DUMP(P[node.location].x) << DUMP(node.location) << DUMP(node.l) << DUMP(node.r) << endl;
  }
  cout << endl;*/

  int q;
  cin >> q;
  rep(i,q) {
    int sx, tx;
    cin >> sx >> tx;

    vector<int> ans;
    find1DTree(ans, P, T, sx, tx, 0);
    sort(ans.begin(), ans.end());
    rep(i,ans.size()) {
      if (i > 0) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }

  return 0;
}
