#include <bits/stdc++.h>
using namespace std;

// syntax sugar: 浮動小数点型の桁数を指定出来るマニピュレータ
#define MANIP_DOUBLE(num) \
  std::fixed << std::setprecision(num)

// ITP1_4_A:   A / B Problem
int main(){
 int a, b;
  cin >> a >> b;
  double c = static_cast<double>(a) / b;
  cout << (a / b) << " " << (a % b) << " " << MANIP_DOUBLE(8) << (double(a) / b) << endl;
}
