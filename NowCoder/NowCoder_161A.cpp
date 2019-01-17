//******************************************************************************
// File Name: NowCoder_161A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月01日 星期六 11时47分43秒
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

const int MAXN = 1e6 + 5, INF = 0x3f3f3f3f;

struct node {
	int cnt[26];
	
	node()
	{
		for (int i = 0; i <= 25; i++) cnt[i] = 0;
	}

	bool check()
	{
		for (int i = 0; i <= 25; i++) if (cnt[i] == 0) return false;
		return true;
	}
};

char s[MAXN];

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%s", s);
	int n = strlen(s);
	node now;
	int l = -1, r = -1, ans = INF;
	while (true) {
		while (!now.check() && r < n - 1) {
			r++;
			now.cnt[s[r] - 'a']++;
		}
		while (l < r && now.check()) {
			ans = min(ans, r - l);
			l++;
			now.cnt[s[l] - 'a']--;
		}
		if (r == n - 1) break;
	}
	printf("%d\n", ans);
	return 0;
}
