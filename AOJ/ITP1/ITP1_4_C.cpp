#include <bits/stdc++.h>
using namespace std;

// ITP1_4_C:   Simple Calculator
int main(){
  int a, b;
  char op;
  while (true) {
    cin >> a >> op >> b;
    switch (op) {
      case '+':
        cout << (a + b) << endl;
        break;
      case '-':
        cout << (a - b) << endl;
        break;
      case '*':
        cout << (a * b) << endl;
        break;
      case '/':
        cout << (a / b) << endl;
        break;
      case '?':
        return 0;
    }
  }
}
