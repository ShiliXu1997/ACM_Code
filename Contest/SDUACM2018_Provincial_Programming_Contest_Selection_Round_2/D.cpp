//************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月24日 星期六 13时20分29秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n;
char s[15];
bool visited[15];

int main()
{
	freopen("scoreboard.in", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%s", s);
		int len = strlen(s);
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < len; i++)
			visited[s[i] - 'A'] = true;
		int mx = 0;
		char ans;
		for (int i = 0; i < 13; i++) {
			int x;
			scanf("%d", &x);
			if (!visited[i] && mx < x) {
				mx = x;
				ans = 'A' + i;
			}
		}
		printf("%c\n", ans);
	}
	return 0;
}
