//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月11日 星期六 23时53分56秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 3005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct person {
	int to, id;
	ll val;

	bool operator<(const person &another) const
	{
		return val < another.val;
	}
};

int n, m;
person p[MAXN];
vector<person> party[MAXN];
bool done[MAXN];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d %lld", &p[i].to, &p[i].val);
		p[i].id = i;
		party[p[i].to].push_back(p[i]);
	}
	sort(p + 1, p + 1 + n);
	for (int i = 1; i <= m; i++) sort(party[i].begin(), party[i].end());
	ll ans = INF;
	for (int i = n; i >= 1; i--) {
		memset(done, false, sizeof(done));
		ll sum = 0;
		int cnt = party[1].size();
		for (int j = 2; j <= m; j++) {
			if (party[j].size() == 0) continue;
			if ((int)party[j].size() >= i) {
				for (int k = 0; k <= (int)party[j].size() - i; k++) {
					sum += party[j][k].val;
					done[party[j][k].id] = true;
					cnt++;
				}
			}
		}
		for (int j = 1; j <= n && cnt < i; j++) {
			if (p[j].to != 1 && !done[p[j].id]) cnt++, sum += p[j].val;
		}
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}
