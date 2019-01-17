//******************************************************************************
// File Name: HDU_1695.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月04日 星期六 22时27分43秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int t, a, b, c, d, k;
vector<int> prime;
int mobius[MAXN];
bool done[MAXN];

void get_mobius(int n)
{
	memset(mobius, 0, sizeof(mobius));
	memset(done, false, sizeof(done));
	mobius[1] = 1;
	for (int i = 2; i < n; i++) {
		if (!done[i]) mobius[i] = -1, prime.push_back(i);
		for (int j = 0; j < prime.size() && (ll)i * prime[j] < n; j++) {
			done[i * prime[j]] = true;
			if (i % prime[j] == 0)
				break;
			else
				mobius[i * prime[j]] = -mobius[i];
		}
	}
}

ll solve(int p, int q)
{
	ll  ans = 0;
	for (int i = 1; i <= min(p, q); i++)
		ans += (ll)mobius[i] * (p / i) * (q / i);
	return ans;
}

int main()
{
	get_mobius(MAXN);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		if (b > d) swap(b, d);
		printf("Case %d: ", i);
		if (k == 0) {
			printf("0\n");
			continue;
		}
		printf("%lld\n", solve(b / k, d / k) - solve(b / k, b / k) / 2);
	}
	return 0;
}
