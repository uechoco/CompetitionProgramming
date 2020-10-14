
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

struct Node {
  bool fixed = false; // 確定した頂点群に含まれているか
  int distance = INT_MAX; // 確定した頂点群からの最小距離
  int distanceFrom = -1; // どの頂点からのdistanceか
};

int main(){
  int n;
  cin >> n;

  unordered_map<int, Node> nodes;

  VECTOR_DIM2(int, adj, n, n, 0);
  rep(i,n) {
    rep(j,n) {
      cin >> adj[i][j];
    }
    auto& node = nodes[i];
  }

  nodes[0].distance = 0; // 初期頂点
  int ans = 0; // 距離合計

  // Prim's Algorithm(プリムのアルゴリズム)
  while (true) {
    // 一番近い頂点を選択する
    int next_node = -1;
    int min_distance = INT_MAX;
    rep(i,n) {
      const auto& node = nodes[i];
      if (!node.fixed && node.distance < min_distance) {
        next_node = i;
        min_distance = node.distance;
      }
    }

    if (next_node == -1 || min_distance == INT_MAX) {
      break;
    }

    ans += min_distance;

    auto& node = nodes[next_node];
    node.fixed = true;
    rep(i,n) {
      if (adj[next_node][i] == -1) continue; // 辺がない
      auto& target = nodes[i];
      if (target.fixed) continue; // 確定済み頂点はもうみない
      if (adj[next_node][i] < target.distance) {
        target.distance = adj[next_node][i];
        target.distanceFrom = next_node;
      }
    }
  }

  cout << ans << endl;



  return 0;
}
