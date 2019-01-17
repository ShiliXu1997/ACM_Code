#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 30, MOD = 1e9 + 7;

long long prime[MAXN], factorial[MAXN], inverse[MAXN], pow[MAXN];
bool boolprime[MAXN];
int t, total;
long long x, y;

long long qpow(long long a, long long b)
{
    long long ans = 1;
    while (b != 0) {
        if (b & 1 == 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void euler(long long n)
{
    total = 0;
    memset(boolprime, false, sizeof(boolprime));
    for (int i = 2; i <= n; i++) {
        if (!boolprime[i]) prime[++total] = i;
        for (int j = 1; j <= total && i * prime[j] <= n; j++) {
            boolprime[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

void init()
{
    euler(1100);
    factorial[0] = 1; pow[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
        pow[i] = pow[i - 1] * 2 % MOD;
    }
    inverse[MAXN - 1] = qpow(factorial[MAXN - 1], MOD - 2) % MOD;
    for (int i = MAXN - 2; i >= 0; i--) inverse[i] = inverse[i + 1] * (i + 1) % MOD;
}

long long comb(long long n, long long m)
{
    if (n < m) return 0;
    if (n - m < m) m = n - m;
    return factorial[n] * inverse[n - m] % MOD * inverse[m] % MOD;
}

int main()
{
    scanf("%d", &t);
    init();
    while (t--) {
        scanf("%lld %lld", &x, &y);
        long long ans = 1;
        for (int i = 1; i <= total && prime[i] <= x; i++) {
            int cnt = 0;
            while (x % prime[i] == 0) {
                x /= prime[i];
                cnt++;
            }
            if (cnt >= 1) ans = ans * comb(y - 1 + cnt, cnt) % MOD;
        }
        if (x != 1) ans = ans * comb(y, 1) % MOD;
        ans = ans * pow[y - 1] % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
