#include <stdio.h>
#include <string.h>
#include <array>
#include <algorithm>

int main()
{
    int n;
    // N
    scanf("%d",&n);
    // a1..aN (=a[0]..a[n-1])
    std::array<unsigned int, 200000> arr;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    
    decltype(arr)::iterator itr = arr.begin();
    std::advance(itr, n);
    std::sort(arr.begin(), itr);
    
    bool result = true;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] == arr[i+1]) {
            result = false;
            break;
        }
    }
    
    // 出力
    if (result) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
