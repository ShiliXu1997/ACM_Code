//************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月11日 星期三 01时51分01秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 150005;

struct node {
	ll num;
	int pos;

	node() {}
	node(ll _num, int _pos) : num(_num), pos(_pos) {}

	bool operator<(const node &another) const
	{
		return pos > another.pos;
	}
};

int n, cnt;
ll a[MAXN];
bool visited[MAXN];
map<ll, priority_queue<node> > mp;

int main()
{
	scanf("%d", &n);
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		mp[a[i]].push(node(a[i], i));
	}
	int ans = 0;
	memset(visited, false, sizeof(visited));
	for (map<ll, priority_queue<node> >::iterator it = mp.begin(); it != mp.end(); ++it) {
		while (it->second.size() >= 2) {
			node fi = it->second.top(); it->second.pop();
			node se = it->second.top(); it->second.pop();
			mp[(ll)2 * se.num].push(node((ll)2 * se.num, se.pos));
		}
		if (it->second.size() == 1) {
			node p = it->second.top();
			visited[p.pos] = true;
			a[p.pos] = p.num;
			ans++;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) if (visited[i]) printf("%lld ", a[i]);
	return 0;
}
