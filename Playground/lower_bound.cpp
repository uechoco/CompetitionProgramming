
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
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

int main(){

  /**
   * @brief std::lower_bound 指定された要素以上の値が現れる最初の位置のイテレータを取得する。
   *
   * この関数の用途としては、ソート済み範囲に対して、任意の値を二分探索で見つけるために使用できる。
   * std::multisetのように同じキーを持つ要素が複数あり、その全てを列挙したい場合にはこの関数の代わりにstd::equal_range()関数を使用できる。
   **/

  std::vector<ll> ai = {19,1,7,3,9,3,8,12,13,19,2,23,6};
  // 19,1,7,3,9,3,8,12,13,19,2,23,6

  std::sort(ai.begin(), ai.end());
  // 1,2,3,3,6,7,8,9,12,13,19,19,23

  // 19以上の値が現れる最初のイテレータを取得
  const auto itr1 = std::lower_bound(ai.begin(), ai.end(), 19);
  if (itr1 != ai.end()) {
    std::size_t pos = std::distance(ai.begin(), itr1);
    std::cout << *itr1 << " pos=" << pos << " ai[pos]=" << ai[pos] << std::endl;
    // 19 pos=10 ai[pos]=19
  }

  // 11以上の値が現れる最初のイテレータを取得
  const auto itr2 = std::lower_bound(ai.begin(), ai.end(), 11);
  if (itr2 != ai.end()) {
    std::size_t pos = std::distance(ai.begin(), itr2);
    std::cout << *itr2 << " pos=" << pos << " ai[pos]=" << ai[pos] << std::endl;
    // 12 pos=8 i[pos]=12
  }

  struct Student {
    int id;
    std::string name;
  };
  std::vector<Student> v2 = {
    {1, "Bob"},
    {5, "Alice"},
    {4, "Carol"},
    {9, "Dave"},
    {2, "Eve"},
  };
  // (1,Bob),(5,Alice),(4,Carol),(9,Dave),(2,Eve)

  std::sort(v2.begin(), v2.end(), [](const Student& l, const Student& r)->bool{
    return l.name < r.name;
  });
  // (5,Alice),(1,Bob),(4,Carol),(9,Dave),(2,Eve)

  const std::string target3 = "Dave";
  const auto itr3 = std::lower_bound(v2.begin(),v2.end(), Student{-1,target3}, [](const Student& a, const Student& b){
    return a.name < b.name;
  });
  if (itr3 != v2.end() && itr3->name == target3) {
    std::size_t pos = std::distance(v2.begin(), itr3);
    std::cout << "(" << itr3->id << "," << itr3->name << ")" << " pos=" << pos << std::endl;
    // (9,Dave) pos=3
  }

  return 0;
}
