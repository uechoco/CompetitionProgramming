#include <bits/stdc++.h>
using namespace std;
int main(){
    // 配列の場合
int n, a[109]; cin >> n;
for (int i = 0; i < n; i++) cin >> a[i];
do {
    for (int i = 0; i < n; i++) {
        if (i) cout << ",";
        cout << a[i];
    }
    cout << endl;
} while(next_permutation(a, a + n));
}
