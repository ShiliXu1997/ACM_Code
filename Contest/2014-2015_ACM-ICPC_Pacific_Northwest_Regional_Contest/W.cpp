//************************************************************************
// File Name: W.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月15日 星期日 15时37分32秒
//************************************************************************

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 65;
const double INF = 1e15;

struct point {
	double x, y, z;
};

int t, n, w, q;
point p[MAXN];
double dist[MAXN][MAXN];
map<string, int> mp;

double get_dist(const point &a, const point &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
	scanf("%d", &t);
	for (int kase = 1; kase <= t; kase++) {
		printf("Case %d:\n", kase);
		mp.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			string name;
			double x, y, z;
			cin >> name >> p[i].x >> p[i].y >> p[i].z;
			mp[name] = i;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) dist[i][j] = dist[j][i] = INF;
		for (int i = 1; i <= n; i++) dist[i][i] = 0;
		for (int i = 1; i <= n - 1; i++)
			for (int j = i + 1; j <= n; j++) dist[i][j] = dist[j][i] = get_dist(p[i], p[j]);
		scanf("%d", &w);
		while (w--) {
			string a, b;
			cin >> a >> b;
			dist[mp[a]][mp[b]] = 0;
		}
		floyd();
		scanf("%d", &q);
		while (q--) {
			string a, b;
			cin >> a >> b;
			ll ans = (ll)floor(dist[mp[a]][mp[b]] + 0.5);
			cout << "The distance from " << a << " to " << b << " is " << ans << " parsecs." << endl;
		}
	}
	return 0;
}
