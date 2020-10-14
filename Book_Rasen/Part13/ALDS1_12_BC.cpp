
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
  int distance = INT_MAX;
  unordered_map<int, int> adjCosts; // 隣接頂点no => cost
};

int main(){
  int n;
  cin >> n;

  unordered_map<int, Node> nodes;
  unordered_set<int> fixedNodes;

  rep(i,n) {
    int u, k, v, c;
    cin >> u >> k;
    auto& node = nodes[u];
    rep(j,k) {
      cin >> v >> c;
      node.adjCosts.emplace(v, c);
    }
  }

  struct Elem {
    int from;
    int to;
    int distance;
  };
  const auto comparator = [](Elem& l, Elem& r) -> bool { return l.distance > r.distance; };
  using distanceQueueType = priority_queue<Elem, vector<Elem>, decltype(comparator)>;
  distanceQueueType distanceQueue(comparator);

  const auto fillEdges = [&n, &nodes, &fixedNodes, &distanceQueue](int from, int baseDistance){
    const auto& fromNode = nodes[from];
    for(const auto& p : fromNode.adjCosts) {
      if (fixedNodes.find(p.first) == fixedNodes.end()) {
        distanceQueue.push(std::move(Elem{from, p.first, p.second + baseDistance}));
        //cout << "distanceQueue filled. from:" << from << ", to:" << p.first << ", cost:" << p.second << endl;
      }
    }
  };

  { // 初期化
    const int initNo = 0;
    auto& node = nodes[initNo];
    node.distance = 0;
    fillEdges(initNo, node.distance);
    fixedNodes.emplace(initNo);
  }

  // Dijkstra's Algorithm(ダイクストラのアルゴリズム、優先度付きキューによる二分ソート)
  while (true) {
    // 一番近い頂点を選択する
    int nextNodeNo = -1;
    int minDistance = INT_MAX;

    while (!distanceQueue.empty()) {
      const auto& elem = distanceQueue.top();
      const auto& node = nodes[elem.to];
      if (!node.fixed) {
        nextNodeNo = elem.to;
        minDistance = elem.distance;
        //cout << "selected min cost node. no:" << elem.to << ", distance:" << elem.distance << endl;
        distanceQueue.pop();
        break;
      }
      distanceQueue.pop();
    }

    if (nextNodeNo == -1 || minDistance == INT_MAX) {
      break;
    }

    auto& node = nodes[nextNodeNo];
    node.fixed = true;
    node.distance = minDistance;
    fixedNodes.emplace(nextNodeNo);
    fillEdges(nextNodeNo, node.distance);
  }

  rep(i,n) {
    const auto& node = nodes[i];
    cout << i << " " << node.distance << endl;
  }

  return 0;
}
