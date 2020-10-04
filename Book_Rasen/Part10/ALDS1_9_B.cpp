
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

int parentNode(int i) { return i / 2; }
int leftNode(int i) { return i * 2; }
int rightNode(int i) { return i * 2 + 1; }

// 節点iを根とする部分木がmax-ヒープになるようA[i]の値をmax-ヒープの葉へ向かって下降させる。Hはヒープサイズ
void maxHeapify(vector<int>& A, const int i, const int heapSize) {
  const int l = leftNode(i);
  const int r = rightNode(i);
  // 左の子、自分、右の子で値が最大のノードを選ぶ
  int largest;
  if (l <= heapSize && A[l] > A[i]) {
    largest = l;
  } else {
    largest = i;
  }
  if (r <= heapSize && A[r] > A[largest]) {
    largest = r;
  }

  if (largest != i) { // iの子のほうが値が大きい場合
    swap(A[i], A[largest]);
    maxHeapify(A, largest, heapSize);
  }
}

// ボトムアップにmaxHeapifyを適用することで配列Aをmax-ヒープに変換する
void buildMaxHeap(vector<int>& A, const int heapSize) {
  for (int i = heapSize / 2; i >= 1; --i) {
    maxHeapify(A, i, heapSize);
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> A(n+1);
  rep2(i, 1, n + 1) cin >> A[i];

  buildMaxHeap(A, n);

  rep2(i,1,n+1) {
    cout << " " << A[i];
  }
  cout << endl;

  return 0;
}
