//******************************************************************************
// File Name: 1010.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月13日 星期一 12时37分43秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

struct matrix {
    ll a[3][3];

    matrix()
    {
        memset(a, 0, sizeof(a));
    }

    matrix operator*(const matrix &another) const
    {
        matrix ans;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    ans.a[i][j] = (ans.a[i][j] + a[i][k] * another.a[k][j] % MOD);
        return ans;
    }
};

int t;
ll a, b, c, d, p, n;
matrix A, B;

matrix qpow(matrix a, int b)
{
    matrix ans;
    ans.a[0][0] = 1; ans.a[0][1] = 0; ans.a[0][2] = 0;
    ans.a[1][0] = 0; ans.a[1][1] = 1; ans.a[1][2] = 0;
    ans.a[2][0] = 0; ans.a[2][1] = 0; ans.a[2][2] = 1;
	while (b) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

vector<ll> mul_matrix_vector(matrix a, vector<ll> b)
{
	vector<ll> ans;
	for (int i = 0; i < 3; i++) {
		ll now = 0;
		for (int j = 0; j < 3; j++) now = (now + a.a[i][j] * b[j]) % MOD;
		ans.push_back(now);
	}
	return ans;
}

void init()
{
	A.a[0][0] = 1; A.a[0][1] = 0; A.a[0][2] = 0;
	A.a[1][0] = 1; A.a[1][1] = d; A.a[1][2] = c;
	A.a[2][0] = 0; A.a[2][1] = 1; A.a[2][2] = 0;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &p, &n);
		if (n == 1) {
			printf("%lld\n", a);
			continue;
		}
		if (n == 2) {
			printf("%lld\n", b);
			continue;
		}
		init();
		vector<ll> now;
		now.push_back(0); now.push_back(b); now.push_back(a);
		for (ll l = 3, r; l <= n; l = r + 1) {
			if (p / l != 0)
				r = min(p / (p / l), n);
			else
				r = n;
			B = qpow(A, r - l + 1);
			now[0] = p / l;
			now = mul_matrix_vector(B, now);
		}
		printf("%lld\n", now[1]);
	}
	return 0;
}
