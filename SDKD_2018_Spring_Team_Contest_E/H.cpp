//************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月07日 星期六 19时24分07秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int t;
long long n;

struct matrix {
	long long a[4][4];

	matrix()
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) a[i][j] = 0;
	}

	void init()
	{
		for (int i = 0; i < 4; i++) a[i][i] = 1;
	}

	matrix operator*(const matrix &another) const
	{
		matrix ans;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
					ans.a[i][j] = (ans.a[i][j] + (a[i][k] * another.a[k][j]) % MOD) % MOD;
		return ans;
	}
};

matrix qpow(matrix a, long long b)
{
	matrix ans; ans.init();
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
	while (t--) {
		scanf("%lld", &n);
		matrix trans, f;
		trans.a[0][0] = trans.a[0][2] = trans.a[1][0] = trans.a[2][1] = trans.a[3][2] = 1;
		f.a[0][0] = 6; f.a[1][0] = 4; f.a[2][0] = 3; f.a[3][0] = 1;
		if (n <= 4) {
			printf("%lld\n", f.a[4 - n][0]);
			continue;
		}
		trans = qpow(trans, n - 1);
		f = trans * f;
		printf("%lld\n", f.a[3][0]);
	}
	return 0;
}
