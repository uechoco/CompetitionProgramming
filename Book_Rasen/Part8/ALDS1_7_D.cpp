
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
    int left;
    int right;

    Node()
    : parent(-1)
    , left(-1)
    , right(-1)
    {}
};

int n;
map<int, Node> tree;
vector<int> preorder, inorder;

void guessTree(int preorderBegin, int inorderBegin, int targetLen) {
    const int id = preorder[preorderBegin];
    //cout << DUMP(id) << DUMP(preorderBegin) << DUMP(inorderBegin) << DUMP(targetLen) << endl;
    auto& node = tree[id];
    node.id = id;

    // idがinorderでは何個indexが離れているか
    //  0: 左のノードはない
    //  1以上: 左のノード数(再起計算)
    // 次のindexが存在する場合、それが右のノード
    int inorderIndex = INT_MIN;
    for(int i = inorderBegin; i < inorderBegin + targetLen; ++i) {
        if (inorder[i] == id) {
            inorderIndex = i;
            break;
        }
    }
    if (inorderIndex == INT_MIN) {
        abort();
    }
    int diff = inorderIndex - inorderBegin;
    //cout << DUMP(diff) << endl;
    if (diff == 0) {
        // 左のノードは存在しない
        node.left = -1;
        // cout << DUMP(node.left) << endl;
    } else {
        node.left = preorder[preorderBegin + 1];
        tree[node.left].parent = id;
        //cout << DUMP(node.left) << DUMP(inorderBegin) << DUMP(diff) << endl;
        guessTree(preorderBegin + 1, inorderBegin, diff);
    }

    if (diff + 1 < targetLen) {
        node.right = preorder[preorderBegin + diff + 1];
        tree[node.right].parent = id;
        //cout << DUMP(node.right) << DUMP(preorderBegin + diff + 1) << DUMP(inorderBegin + diff + 1) << DUMP(targetLen - diff - 1) << endl;
        guessTree(preorderBegin + diff + 1, inorderBegin + diff + 1, targetLen - diff - 1);
    } else {
        node.right = -1;
        //cout << DUMP(node.right) << endl;
    }
}

void printId(int id, bool& bFirst) {
    if (bFirst) {
        cout << id;
        bFirst = false;
    } else {
        cout << " " << id;
    }
}

void walkAsPostorder(int id, bool& bFirst) {
    if (id == -1) return;
    const auto& node = tree[id];
    if (node.left != -1) {
        walkAsPostorder(node.left, bFirst);
    }
    if (node.right != -1) {
        walkAsPostorder(node.right, bFirst);
    }
    printId(node.id, bFirst);
}

int main(){
    cin >> n;
    preorder.resize(n);
    inorder.resize(n);
    rep(i,n) cin >> preorder[i];
    rep(i,n) cin >> inorder[i];
    guessTree(0, 0, n);

    int rootId = tree.begin()->first;
    while (true) {
        const auto& node = tree[rootId];
        if (node.parent == -1) {
            break;
        } else {
            rootId = node.parent;
        }
    }

    bool bFirst = true;
    walkAsPostorder(rootId, bFirst);
    cout << endl;

    return 0;
}
