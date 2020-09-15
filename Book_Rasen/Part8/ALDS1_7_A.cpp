
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
// @brief modint: mod 計算を int を扱うように扱える構造体
template<int MOD> struct Fp {
    long long val;
    // コンストラクタ
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) { if (val < 0) val += MOD; }
    constexpr int getmod() { return MOD; }
    // 単項演算子マイナス。
    constexpr Fp operator - () const noexcept { return val ? MOD - val : 0;}
    // 足し算 (a + b) mod P を解く。計算途中でもあまりをとって良い。
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    // 引き算 (a - b) mod P を解く。計算途中でもあまりをとって良い。最終結果が負値なら P を足す。
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    // 掛け算 (a * b) mod P を解く。計算途中でもあまりをとって良い。
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    // 割り算 (a / b) mod P を解く。bの逆元をかける。
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept { val += r.val; if (val >= MOD){val -= MOD;} return *this; }
    constexpr Fp& operator -= (const Fp& r) noexcept { val -= r.val; if (val < 0){val += MOD;} return *this; }
    constexpr Fp& operator *= (const Fp& r) noexcept { val = val * r.val % MOD; return *this; }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept { return this->val == r.val; }
    constexpr bool operator != (const Fp& r) const noexcept { return this->val != r.val; }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept { return os << x.val; }
    // 累乗 a^n mod P を二分累乗法で解く O(lon n)
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
const int MOD = 1e9+7; // 1000000007
using mint = Fp<MOD>;

#define ll long long
#define ld long double
#define DUMP(v) "," #v ":" << v

struct Node {
    int id; // 節点番号
    int parent; // 親の節点番号
    int depth; // 深さ
    vector<int> children;

    Node()
    : id(0)
    , parent(-1)
    , depth(0)
    , children()
    {
    }
};

int main(){
    int n;
    cin >> n;
    map<int, Node> nodes; // id => Node

    rep(i,n) {
        int id, k;
        cin >> id >> k;

        auto& node = nodes[id];
        node.id = id;
        auto& children = node.children;
        children.resize(k);
        rep(j,k) {
            int cno;
            cin >> cno;
            children[j] = cno;
            nodes[cno].parent = id;
        }
    }

    int rootId = nodes.begin()->first;
    while (nodes[rootId].parent != -1) {
        rootId = nodes[rootId].parent;
    }

    int depth = 0;
    vector<int> siblingIDs;
    siblingIDs.push_back(rootId);
    while (!siblingIDs.empty()) {
        vector<int> tmpSiblingIDs;
        for(const auto id: siblingIDs) {
            auto& node = nodes[id];
            node.depth = depth;
            tmpSiblingIDs.insert(tmpSiblingIDs.end(), node.children.begin(), node.children.end());
        }
        ++depth;
        siblingIDs = tmpSiblingIDs;
    }

    for(const auto& pair: nodes) {
        const auto&node = pair.second;

        string type;
        if (node.parent == -1) {
            type = "root";
        } else if (node.children.empty()) {
            type = "leaf";
        } else {
            type = "internal node";
        }

        cout << "node " << pair.first << ": parent = " << node.parent << ", depth = " << node.depth << ", " << type << ", [";
        rep(i,node.children.size()) {
            if (i) cout << ", ";
            cout << node.children[i];
        }
        cout << "]" << endl;
    }

    return 0;
}
