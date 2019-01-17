//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月01日 星期二 15时12分32秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

const int MAXN = 205;

struct team {
	int num, time, id;

	team(int _num, int _time, int _id) : num(_num), time(_time), id(_id) {}

	bool operator<(const team &another) const
	{
		if (num == another.num && time == another.time) return id > another.id;
		if (num == another.num) return time > another.time;
		return num < another.num;
	}
};

int n, m, p;
priority_queue<team> q;
map<string, int> mp;
int cnt[MAXN], tot[MAXN];
int t[MAXN][150];

int main()
{
	scanf("%d %d %d", &n, &m, &p);
	memset(cnt, 0, sizeof(cnt));
	memset(tot, 0, sizeof(tot));
	memset(t, 0, sizeof(t));
	char name[500];
	for (int i = 1; i <= n; i++) {
		scanf("%s", name);
		string na(name);
		mp[na] = i;
		q.push(team(0, 0, i));
	}
	char pro[2], res[3];
	int last = 0, ans = 0;
	while (m--) {
		int tt;
		scanf("%s %s %d %s", name, pro, &tt, res);
		string na(name);
		int id = mp[na], od = (int)(pro[0] - 'A');
		if (res[0] == 'O') {
			cnt[id]++;
			tot[id] += 20 * t[id][od] + tt;
			q.push(team(cnt[id], tot[id], id));
			if (q.top().id == 1) {
				if (last != -1) ans += (tt - last);
				last = tt;
			}
			else {
				if (last != -1) ans += (tt - last);
				last = -1;
			}
		}
		else
			t[id][od]++;
	}
	if (q.top().id == 1 && last != -1) ans += (300 - last);
	printf("%d", ans);
	return 0;
}
