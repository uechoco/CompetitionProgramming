
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
  int no; // u
  int outNum; // k
  int distance = -1;
  set<int> neighborNo;
  bool visited = false;
};

map<int, Node> nodes;

int main(){
  int n;
  cin >> n;

  rep(i,n) {
    int u, k, v;
    cin >> u >> k;
    auto& node = nodes[u];
    node.no = u;
    node.outNum = k;
    rep(j,k) {
      cin >> v;
      node.neighborNo.emplace(v);
    }
  }

  stack<pair<int, int>> st;
  st.push(std::move(pair<int,int>(1, 0)));
  while (!st.empty()) {
    const auto& p = st.top();
    const int no = p.first;
    const int dist = p.second;
    st.pop();
    auto& node = nodes[no];
    node.visited = true;
    if (node.distance == -1 || node.distance > dist) {
      node.distance = dist;
      for(const int& to : node.neighborNo) {
        st.push(std::move(pair<int,int>(to, dist + 1)));
      }
    }
  }

  for (const auto& p : nodes) {
    cout << p.first << " " << p.second.distance << endl;
  }

  return 0;
}
