//******************************************************************************
// File Name: J.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月02日 星期日 14时50分52秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 205;

struct card {
	int a, b;

	card() {}
	card(int _a, int _b) : a(_a), b(_b) {}

	bool operator==(const card &another) const
	{
		return (a == another.a && b == another.b);
	}

	bool operator<(const card &another) const
	{
		if (b == another.b) return a < another.a;
		return b < another.b;
	}
};

struct cards {
	card pp[6];
	
	bool operator<(const cards &another) const
	{
		for (int i = 1; i <= 5; i++) {
			if (pp[i] == another.pp[i]) continue;
			return pp[i] < another.pp[i];
		}
		return true;
	}
};

int A, B, cnt;
card p[MAXN], now[6];
int ans[15];
set<cards> st;
cards heihei;

bool cmp_rank(const card a, const card b)
{
	return a.a < b.a;
}

bool same_suit()
{
	int c = heihei.pp[1].b;
	return (heihei.pp[2].b == c && heihei.pp[3].b == c && heihei.pp[4].b == c && heihei.pp[5].b == c);
}

bool increase_rank()
{
	sort(heihei.pp + 1, heihei.pp + 1 + 5, cmp_rank);
	int c = heihei.pp[1].a;
	return (heihei.pp[2].a == c + 1 && heihei.pp[3].a == c + 2 && heihei.pp[4].a == c + 3 && heihei.pp[5].a == c + 4);
}

int kind()
{
	map<int, int> cnt;
	for (int i = 1; i <= 5; i++)
		if (!cnt.count(heihei.pp[i].a))
			cnt[heihei.pp[i].a] = 1;
		else
			cnt[heihei.pp[i].a]++;
	int cnt_2 = 0, cnt_3 = 0, cnt_4 = 0;
	for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
		if (it->second == 4) cnt_4++;
		if (it->second == 3) cnt_3++;
		if (it->second == 2) cnt_2++;
	}
	if (cnt_4) return 4;
	if (cnt_3 && cnt_2) {
		return 3;
	}
	if (cnt_3) return 2;
	if (cnt_2 == 2) return 1;
	if (cnt_2) return 0;
	return -1;
}

void check()
{
	if (same_suit()) {
		if (increase_rank())
			ans[1]++;
		else
			ans[4]++;
		return;
	}
	if (increase_rank()) {
		ans[5]++;
		return;
	}
	int k = kind();
	if (k == 0) {
		ans[8]++;
		return;
	}
	if (k == 1) {
		ans[7]++;
		return;
	}
	if (k == 2) {
		ans[6]++;
		return;
	}
	if (k == 3) {
		ans[3]++;
		return;
	}
	if (k == 4) {
		ans[2]++;
		return;
	}
	ans[9]++;
}

int main()
{
	scanf("%d %d", &A, &B);
	int a1, a2, b1, b2;
	scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
	now[1] = card(a1, b1); now[2] = card(a2, b2);
	cnt = 0;
	for (int i = 0; i < A; i++)
		for (int j = 0; j < B; j++) p[++cnt] = card(i, j);
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= cnt; i++) {
		if (p[i] == now[1] || p[i] == now[2]) continue;
		now[3] = p[i];
		for (int j = i + 1; j <= cnt; j++) {
			if (p[j] == now[1] || p[j] == now[2] || p[j] == now[3]) continue;
			now[4] = p[j];
			for (int k = j + 1; k <= cnt; k++) {
				if (p[k] == now[1] || p[k] == now[2] || p[k] == now[3] || p[k] == now[4]) continue;
				now[5] = p[k];
				for (int l = 1; l <= 5; l++) heihei.pp[l] = now[l];
				sort(heihei.pp + 1, heihei.pp + 1 + 5);
				if (!st.count(heihei)) {
					st.insert(heihei);
					check();
				}
			}
		}
	}
	for (int i = 1; i <= 9; i++) printf("%d ", ans[i]);
	return 0;
}
