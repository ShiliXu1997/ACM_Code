//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月29日 星期三 13时32分17秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 2005;

struct thing {
	string name;
	int w;

	bool operator<(const thing &another) const
	{
		return w < another.w;
	}
};

int n, m, wkit;
thing t[MAXN];
bool dp[MAXN];
pair<int, int> state[MAXN];
int ans[MAXN];

int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> wkit >> m;
	for (int i = 1; i <= m; i++) cin >> t[i].name >> t[i].w;
	sort(t + 1, t + 1 + m);
	cin >> n;
	while (n--) {
		int x, half;
		cin >> x;
		half = x / 2; if (2 * half < x) half++;
		if (wkit >= half) {
			cout << 0 << endl;
			continue;
		}
		memset(dp, false, sizeof(dp));
		dp[wkit] = true;
		for (int j = 1; j <= m; j++) {
			for (int i = 2000; i >= wkit + t[j].w; i--) {
				if (dp[i]) continue;
				if (dp[i - t[j].w]) {
					dp[i] = true;
					state[i] = make_pair(i - t[j].w, j);
				}
			}
		}
		int cnt = 0;
		for (int i = half; i <= 2000; i++) 
			if (dp[i]) {
				for (int j = i; j > wkit; j = state[j].first) ans[++cnt] = state[j].second;
				break;
			}
		if (cnt) {
			cout << cnt << " ";
			for (int i = 1; i <= cnt; i++) cout << t[ans[i]].name << " ";
			cout << endl;
		}
		else
			cout << -1 << endl;
	}
	return 0;
}
