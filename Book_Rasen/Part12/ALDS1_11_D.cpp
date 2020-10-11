
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
  int groupNo = 0;
  set<int> neighbors;
};

unordered_map<int, Node> nodes;

void traversal(int no, int currentGroupNo) {
  auto& node = nodes[no];
  if (node.groupNo > 0) {  // visited
    return;
  }
  node.groupNo = currentGroupNo;
  for (const auto& to : node.neighbors) {
    traversal(to, currentGroupNo);
  }
}

int main(){
  int n, m, s, t;
  cin >> n >> m;
  rep(i,m) {
    cin >> s >> t;
    auto& from = nodes[s];
    from.neighbors.emplace(t);
    auto& to = nodes[t];
    to.neighbors.emplace(s);
  }

  // グラフグループの分類
  int currentGroupNo = 0;
  for (const auto& p : nodes) {
    if (p.second.groupNo == 0) {
      traversal(p.first, ++currentGroupNo);
    }
  }

  int q;
  cin >> q;
  rep(i,q) {
    cin >> s >> t;
    const auto& from = nodes[s];
    const auto& to = nodes[t];
    if (from.groupNo == to.groupNo && from.groupNo != 0) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}
