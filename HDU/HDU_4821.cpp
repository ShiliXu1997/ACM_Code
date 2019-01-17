//************************************************************************
// File Name: HDU_4821.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月24日 星期六 20时53分34秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef unsigned long long ull;
const int MAXN = 1e5 + 5, BASE = 31;

int m, l;
char s[MAXN];
ull hsh[MAXN], p[MAXN];
map<ull, int> st;

void init()
{
	int len = strlen(s);
	hsh[0] = (ull)(s[0] - 'a');
	p[0] = (ull)1;
	for (int i = 1; i < len; i++) {
		hsh[i] = hsh[i - 1] * BASE + (ull)(s[i] - 'a');
		p[i] = p[i - 1] * BASE;
	}
}

ull get_hash(int l, int r)
{
	if (l == 0) return hsh[r];
	return (hsh[r] - hsh[l - 1] * p[r - l + 1]);
}

int main()
{
	while (scanf("%d %d", &m, &l) == 2) {
		scanf("%s", s);
		init();
		int len = strlen(s), ans = 0;
		for (int i = 0; i < l; i++) {
			int left = i, right = i + m * l - 1;
			if (right >= len) break;
			st.clear();
			for (int j = 0; j < m; j++) st[get_hash(left + j * l, left + j * l + l - 1)]++;
			if (st.size() == m) ans++;
			while (right + l < len) {
				left += l; right += l;
				st[get_hash(left - l, left - 1)]--;
				if (st[get_hash(left - l, left - 1)] == 0) st.erase(get_hash(left - l, left - 1));
				st[get_hash(right - l + 1, right)]++;
				if (st.size() == m) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

