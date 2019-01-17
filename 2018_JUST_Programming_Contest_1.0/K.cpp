//************************************************************************
// File Name: K.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月28日 星期六 14时27分07秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

struct sub {
	int x, y, z, m, s;

	bool operator<(const sub &another) const
	{
		if (m == another.m && s == another.s) return z < another.z;
		if (m == another.m) return s < another.s;
		return m < another.m;
	}
};

int t, n, m, k, first, last, solid;
char time[10];
int who[35], onetry[35];
int sometry[35][35];
bool ac[35][35];
sub sb[20005];

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		first = last = solid = -1;
		memset(ac, false, sizeof(ac));
		memset(who, 0xff, sizeof(who));
		memset(onetry, 0, sizeof(onetry));
		memset(sometry, 0, sizeof(sometry));
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= k; i++) {
			scanf("%d %d %d %s", &sb[i].x, &sb[i].y, &sb[i].z, time);
			sb[i].m = sb[i].s = 0;
			for (int j = 0; j <= 2; j++) sb[i].m = sb[i].m * 10 + time[j] - '0';
				for (int j = 4; j <= 5; j++) sb[i].s = sb[i].s * 10 + time[j] - '0';
		}
		sort(sb + 1, sb + 1 + k);
		for (int i = 1; i <= k; i++) {
			int x = sb[i].x, y = sb[i].y, z = sb[i].z;
			if (z) {
				ac[y][x] = true;
				if (first == -1) first = y;
				last = y;
				if (who[x] == -1) who[x] = y;
				if (!sometry[y][x]) {
					onetry[y]++;
					solid = (solid == -1 || onetry[y] > onetry[solid] || onetry[y] == onetry[solid] && y < solid ? y : solid);
				}
			}
			else
				sometry[y][x]++;
		}
		for (int i = 1; i <= n; i++) printf("%d ", who[i]);
		printf("\n");
		int ans = -1, mx = 0;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) if ((ans == -1 || sometry[i][j] > mx) && ac[i][j]) ans = i, mx = sometry[i][j];
		printf("%d %d %d %d\n", first, last, solid, ans);
	}
	return 0;
}
