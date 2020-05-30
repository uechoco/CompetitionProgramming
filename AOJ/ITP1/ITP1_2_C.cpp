#include <bits/stdc++.h>
using namespace std;

// ITP1_2_C:   Sorting Three Numbers
int main(){
  /*
  std::vector<int> a(3);
  scanf("%d %d %d", &a[0], &a[1], &a[2]);
  std::sort(a.begin(), a.end());
  printf("%d %d %d\n", a[0], a[1], a[2]);
  */
 int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(begin(a), end(a));
  cout << a[0] << " " << a[1] << " " << a[2] << endl;
}
