
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
    int id;
    int parent;
    int sibling;
    int left;
    int right;
    int depth;
    int height;

    Node() = default;

    Node(int id)
    : id(id)
    , parent(-1)
    , sibling(-1)
    , left(-1)
    , right(-1)
    , depth(-1)
    , height(-1)
    {}

    Node(int id, int left, int right)
    : id(id)
    , parent(-1)
    , sibling(-1)
    , left(left)
    , right(right)
    , depth(-1)
    , height(-1)
    {}
};

int getDepth(map<int, Node>& tree, int id) {
    if (id == -1) {
        return -1;
    } else {
        auto& node = tree[id];
        if (node.depth != -1) {
            return node.depth;
        } else {
            return getDepth(tree, node.parent) + 1;
        }
    }
}
int getHeight(map<int, Node>& tree, int id) {
    auto& node = tree[id];
    if (node.height != -1) {
        return node.height;
    }
    const int leftHeight = (node.left == -1 ? -1 : getHeight(tree, node.left));
    const int rightHeight = (node.right == -1 ? -1 : getHeight(tree, node.right));
    return max(leftHeight, rightHeight) + 1;
}

int main(){
    int n;
    cin >> n;

    map<int, Node> tree;

    rep(i,n) {
        int id, left, right;
        cin >> id >> left >> right;
        tree.emplace(id, std::move(Node(id, left, right)));
    }

    // parent, sibling
    for(auto& p : tree) {
        const int left = p.second.left;
        const int right = p.second.right;
        if (left != -1) {
            auto& node = tree[left];
            node.parent = p.first;
            node.sibling = right;
        }
        if (right != -1) {
            auto& node = tree[right];
            node.parent = p.first;
            node.sibling = left;
        }
    }

    for (auto& p : tree) {
        auto& node = p.second;
        if (node.depth != -1) continue;
        node.depth = getDepth(tree, node.id);
        node.height = getHeight(tree, node.id);
    }

    for (const auto& p : tree) {
        const auto& node = p.second;
        const int degree = (node.left != -1 ? 1 : 0) + (node.right != -1 ? 1 : 0);
        cout << "node " << node.id << ": parent = " << node.parent;
        cout << ", sibling = " << node.sibling << ", degree = " << degree;
        cout << ", depth = " << node.depth << ", height = " << node.height;
        if (node.parent == -1) {
            cout << ", root" << endl;
        } else if (degree == 0) {
            cout << ", leaf" << endl;
        } else {
            cout << ", internal node" << endl;
        }
    }

    return 0;
}
