
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
#define rep2(i, startValue, N) for (int i = (int)(startValue); i < (int)(N); ++i)
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


int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> H(n);
    rep(i,n) {
        cin >> H[i];
    }
    vector<ll> W(m);
    rep(i,m) {
        cin >> W[i];
    }

    sort(H.begin(), H.end());
    vector<ll> diffs(n-1);
    {
        ll last = H[0];
        rep2(i,1,n) {
            diffs.emplace_back(H[i] - last);
            last = H[i];
        }
    }

    sort(diffs.begin(), diffs.end(), std::greater<ll>());
    rep(i, m) {
        const ll w = W[i];
    }

    return 0;
}
