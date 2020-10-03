
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
    int key;
    Node *parent, *left, *right;
};

Node* root = nullptr;

void insert(Node* T, Node* z) {
    Node* y = nullptr; // xの親
    Node* x = T;
    while (x != nullptr) {
        y = x; // 親を設定
        if (z->key < x->key) {
            x = x->left; // 左の子へ移動
        } else {
            x = x->right; // 右の子へ移動
        }
    }
    z->parent = y;

    if (y == nullptr) {
        // Tが空の場合
        root = z;
    } else if (z->key < y->key) {
        y->left = z; // z を y の左の子にする
    } else  {
        y->right = z; // z を y の右の子にする
    }
}

void inorder(Node* x) {
    if (x == nullptr) return;
    inorder(x->left);
    cout << " " << x->key;
    inorder(x->right);
}

void preorder(Node* x) {
    if (x == nullptr) return;
    cout << " " << x->key;
    preorder(x->left);
    preorder(x->right);
}

int main(){
    int m;
    cin >> m;
    rep(i,m) {
        string s;
        int k;
        cin >> s;
        if (s == "insert") {
            cin >> k;
            Node* z = (Node*)malloc(sizeof(Node));
            z->key = k;
            z->parent = nullptr;
            z->left = nullptr;
            z->right = nullptr;
            insert(root, z);
        } else {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }

    return 0;
}
