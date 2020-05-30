#include <stdio.h>
#include <string.h>
#include <array>
#include <algorithm>

int main()
{
    int n, k;
    // N, K
    scanf("%d %d",&n, &k);
    // a1..aN (=a[0]..a[n-1])
    std::array<unsigned int, 200000> arr;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    
    // 一番総和の大きな組み合わせを探し当てる
    int max_i = 0;
    int max_total = 0;
    int latest_total = 0;

    // i = 0 だけ特別に計算する
    for (int j = 0; j < k; ++j) {
        max_total += arr[j];
    }
    latest_total = max_total - arr[max_i];
    
    int total = 0;
    for (int i = 1; i <= n - k; ++i) {
        total = latest_total + arr[i + k - 1];
        if (max_total < total) {
            max_i = i;
            max_total = total;
        }
        latest_total = total - arr[i];
    }
    
    float expect = 0.f;
    for (int i = max_i; i < max_i + k; ++i) {
        expect += ((arr[i]*(arr[i]+1)) / 2.0f) / arr[i];
    }
    
    // 出力
    printf("%f\n", expect);
    return 0;
}
