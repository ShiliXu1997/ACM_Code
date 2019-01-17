//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 04 Nov 2018 04:43:48 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define x first
#define y second

const ll MOD = 2147493647;

struct matrix {
    ll a[7][7];
   
    matrix()
    {
        memset(a, 0, sizeof(a));
    }

    void init(ll x, ll y)
    {
        a[0][0] = x;
        a[1][0] = y;
        a[2][0] = 16;
        a[3][0] = 8;
        a[4][0] = 4;
        a[5][0] = 2;
        a[6][0] = 1;
    }

    matrix operator*(const matrix &another) const
    {
        matrix ans;
        for (int i = 0; i < 7; i++)
            for (int j = 0; j < 7; j++)
                for (int k = 0; k < 7; k++)
                    ans.a[i][j] = (ans.a[i][j] + a[i][k] * another.a[k][j]) % MOD; 
        return ans;
    }
};

int t;
ll n, a, b;

matrix qpow(matrix a, ll b)
{
    matrix ans;
    for (int i = 0; i < 7; i++) ans.a[i][i] = 1;
    while (b) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    matrix T;
    T.a[0][0] = 1; T.a[0][1] = 2; T.a[0][2] = 1; T.a[0][3] = 4; T.a[0][4] = 6; T.a[0][5] = 4; T.a[0][6] = 1;
    T.a[1][0] = 1; T.a[1][1] = 0; T.a[1][2] = 0; T.a[1][3] = 0; T.a[1][4] = 0; T.a[1][5] = 0; T.a[1][6] = 0;
    T.a[2][0] = 0; T.a[2][1] = 0; T.a[2][2] = 1; T.a[2][3] = 4; T.a[2][4] = 6; T.a[2][5] = 4; T.a[2][6] = 1;
    T.a[3][0] = 0; T.a[3][1] = 0; T.a[3][2] = 0; T.a[3][3] = 1; T.a[3][4] = 3; T.a[3][5] = 3; T.a[3][6] = 1;
    T.a[4][0] = 0; T.a[4][1] = 0; T.a[4][2] = 0; T.a[4][3] = 0; T.a[4][4] = 1; T.a[4][5] = 2; T.a[4][6] = 1;
    T.a[5][0] = 0; T.a[5][1] = 0; T.a[5][2] = 0; T.a[5][3] = 0; T.a[5][4] = 0; T.a[5][5] = 1; T.a[5][6] = 1;
    T.a[6][0] = 0; T.a[6][1] = 0; T.a[6][2] = 0; T.a[6][3] = 0; T.a[6][4] = 0; T.a[6][5] = 0; T.a[6][6] = 1;
    while (t--) {
        scanf("%lld %lld %lld", &n, &a, &b);
        if (n == 1) {
            printf("%lld\n", a);
            continue;
        }
        if (n == 2) {
            printf("%lld\n", b);
            continue;
        }
        matrix v;
        v.init(b, a);
        matrix ans = qpow(T, n - 1) * v;
        printf("%lld\n", ans.a[1][0]);
    }
	return 0;
}
