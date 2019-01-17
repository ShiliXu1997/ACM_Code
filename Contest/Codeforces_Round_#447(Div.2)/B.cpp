#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long MOD = 1e9 + 7;

long long n, m, k;

long long qpow(long long a, long long b)
{
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%lld %lld %lld", &n, &m, &k);
    long long ans = 0;
    if (k == -1 && (n & 1) != (m & 1))
        ans = 0;
    else {
        ans = qpow(2, n - 1);
        ans = qpow(ans, m - 1);
    }
    printf("%lld\n", ans);
    return 0;
}
