//******************************************************************************
// File Name: POJ_2478.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月03日 星期五 10时58分25秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;

vector<int> prime;
int phi[MAXN];
bool done[MAXN];
ll ans[MAXN];

void euler(int n)
{
	memset(done, false, sizeof(done));
	for (int i = 2; i < n; i++) {
		if (!done[i]) {
			prime.push_back(i);
			phi[i] = i - 1;
		}
		for (int j = 0; j < prime.size() && (ll)i * prime[j] < n; j++) {
			done[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = prime[j] * phi[i];
				break;
			}
			else
				phi[i * prime[j]] = phi[prime[j]] * phi[i];
		}
	}
}

void solve(int n)
{
	ans[1] = 0;
	for (int i = 2; i < n; i++)
		ans[i] = ans[i - 1] + phi[i];
}

int main()
{
	euler(MAXN);
	solve(MAXN);
	int n;
	while (scanf("%d", &n) == 1 && n) printf("%lld\n", ans[n]);
	return 0;
}
