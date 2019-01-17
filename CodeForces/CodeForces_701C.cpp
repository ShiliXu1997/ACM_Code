//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月21日 星期三 21时26分35秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

int n;
char s[MAXN];
int visited[52];

int get(char c)
{
	int index;
	if ('A' <= c && c <= 'Z') index = c - 'A';
	if ('a' <= c && c <= 'z') index = c - 'a' + 26;
	return index;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	int tot = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		int index = get(s[i]);
		if (!visited[index]) {
			tot++;
			visited[index] = 1;
		}
	}
	memset(visited, 0, sizeof(visited));
	int l = 1, r = 0, ans = INF, cnt = 0;
	while (r < n) {
		while (cnt < tot && r < n) {
			r++;
			int index = get(s[r]);
			if (!visited[index]) cnt++;
			visited[index]++;
		}
		while (l <= r && cnt == tot) {
			ans = min(ans, r - l + 1);
			int index = get(s[l]);
			visited[index]--;
			if (!visited[index]) cnt--;
			l++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
