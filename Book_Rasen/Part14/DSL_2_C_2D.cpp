
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

// ex: KDTree<int, 3>: 3次元intのkd-tree
template <typename T, int DIM>
class KDTree {
public:
  struct Point {
    T no;
    T v[DIM];
  };

  struct Node {
    T location; // Pの位置
    T l;
    T r;
  };

  struct Query {
    Point s;
    Point t;

    bool contains(const Point& p) const {
      for(int i = 0; i < DIM; ++i) {
        if (s.v[i] > p.v[i] || p.v[i] > t.v[i]) {
          return false;
        }
      }
      return true;
    }
  };

  KDTree(int n) {
    this->pointNum = n;
    this->np = 0;
    this->tree = vector<Node>(n);
    this->Points = vector<Point>(n);
  }

  T makeTree(const T l, const T r, const int depth) {
    if (l >= r) {
      return -1;
    }
    //cout << "makeTree: " << DUMP(depth) << DUMP(l) << DUMP(r) << endl;

    // Pについて、l <= x < r の範囲を Point.v[depth % DIM] について昇順に整列する
    const T depthMod = depth % DIM;
    sort(this->Points.begin() + l, this->Points.begin() + r, [&depthMod](const Point& l, const Point& r)->bool{ return l.v[depthMod] < r.v[depthMod]; });

    const T mid = (l + r) / 2;
    const T t = np++; // 二分木のノード番号を設定

    this->tree[t].location = mid; // Pにおける位置
    this->tree[t].l = makeTree(l, mid, depth+1); // 前半で部分木を生成
    this->tree[t].r = makeTree(mid+1, r, depth+1); // 後半で部分木を生成

    return t;
  }

  vector<Point> findTree(const Query& q) const {
    vector<Point> ans;
    findTreeImpl(ans, q, static_cast<T>(0), 0);
    return ans;
  }

private:
  void findTreeImpl(vector<Point>& ans, const Query& q, const T index, const int depth) const {
    const auto& node = this->tree[index];
    const Point& p = this->Points[node.location];
    //cout << "findTreeImpl: " << DUMP(index) << DUMP(depth) << DUMP(node.location) << DUMP(p.v[0]) << endl;
    if (q.contains(p)) {
      ans.push_back(p);
    }

    const T depthMod = depth % DIM;
    if (node.l >= 0 && q.s.v[depthMod] <= p.v[depthMod]) {
      findTreeImpl(ans, q, node.l, depth + 1);
    }
    if (node.r >= 0 && p.v[depthMod] <= q.t.v[depthMod]) {
      findTreeImpl(ans, q, node.r, depth + 1);
    }
  }

public:
  vector<Point> Points;
private:
  vector<Node> tree;
  int np = 0;
  int pointNum = 0;
};


int main(){
/*
入力値
10
16 10 1 3 14 5 21 6 13 19
1
6 15
  */
  /*{ // 1DTree
    using D1Tree = KDTree<int, 1>;
    int n, v;
    cin >> n;
    D1Tree d1(n);
    rep(i,n) {
      cin >> d1.Points[i].v[0];
    }
    d1.makeTree(0, n, 0);

    int q;
    cin >> q;
    rep(i,q) {
      decltype(d1)::Query q;
      cin >> q.s.v[0] >> q.t.v[0];
      auto ans = d1.findTree(q);

      sort(ans.begin(), ans.end(), [](const decltype(d1)::Point& l, const decltype(d1)::Point& r)->bool{return l.v[0] < r.v[0];});
      rep(i,ans.size()) {
        if (i > 0) cout << " ";
        cout << ans[i].v[0];
      }
      cout << endl;
    }
  }*/

  { // 2DTree
    using D2Tree = KDTree<int, 2>;
    int n, v;
    cin >> n;
    D2Tree d2(n);
    rep(i,n) {
      auto& p = d2.Points[i];
      p.no = i;
      cin >> p.v[0] >> p.v[1];
    }
    d2.makeTree(0, n, 0);

    int q;
    cin >> q;
    rep(i,q) {
      decltype(d2)::Query q;
      cin >> q.s.v[0] >> q.t.v[0] >> q.s.v[1] >> q.t.v[1];
      auto ans = d2.findTree(q);

      sort(ans.begin(), ans.end(), [](const decltype(d2)::Point& l, const decltype(d2)::Point& r)->bool{return l.no < r.no;});
      rep(i,ans.size()) {
        cout << ans[i].no << endl;
      }
      cout << endl;
    }
  }

  return 0;
}
