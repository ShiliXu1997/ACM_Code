//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月18日 星期日 13时26分38秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50;

int n;
int g[MAXN][MAXN];
char s[MAXN];
bool cnt[MAXN];

int main()
{
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; i++) {
			scanf("%s", s);
			for (int j = 1; j <= n; j++) {
				if ('0' <= s[j - 1] && s[j - 1] <= '9')
					g[i][j] = (s[j - 1] - '0');
				if ('A' <= s[j - 1] && s[j - 1] <= 'Z')
					g[i][j] = s[j - 1] - 'A' + 10;
			}
		}
		bool is_latin = true, is_increase = true;
		for (int i = 1; i <= n && is_latin; i++) {
			memset(cnt, false, sizeof(cnt));
			for (int j = 1; j <= n && is_latin; j++) 
				if (!cnt[g[i][j]])
					cnt[g[i][j]] = true;
				else
					is_latin = false;
		}
		for (int i = 1; i <= n && is_latin; i++) {
			memset(cnt, false, sizeof(cnt));
			for (int j = 1; j <= n && is_latin; j++) 
				if (!cnt[g[j][i]])
					cnt[g[j][i]] = true;
				else
					is_latin = false;
		}
		if (!is_latin)
			printf("No\n");
		else {
			for (int i = 2; i <= n && is_increase; i++)
				if (g[1][i - 1] > g[1][i]) is_increase = false;
			for (int i = 2; i <= n && is_increase; i++)
				if (g[i - 1][1] > g[i][1]) is_increase = false;
			printf("%s\n", (is_increase ? "Reduced" : "Not Reduced"));
		}
	}
	return 0;
}
