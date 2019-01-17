//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月05日 星期三 14时43分16秒
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

const int MAXN = 1e5 + 5;

int n;
ll cnt;
int a[MAXN], b[MAXN], sum[MAXN], temp[MAXN];

ll merge_sort(int l, int r)
{
	if (l == r) return 0;
	ll ans = 0;
	int mid = (l + r) >> 1;
	ans += merge_sort(l, mid);
	ans += merge_sort(mid + 1, r);
	int i = l, j = mid + 1, index = l;
	while (i <= mid && j <= r) {
		if (sum[i] < sum[j])
			temp[index++] = sum[i++];
		else
			temp[index++] = sum[j++], ans += (mid + 1 - i);
	}
	while (i <= mid) temp[index++] = sum[i++];
	while (j <= r) temp[index++] = sum[j++];
	for (int i = l; i <= r; i++) sum[i] = temp[i];
	return ans;
}

bool check(int x)
{
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
		sum[i] = (a[i] <= x ? 1 : -1);
	for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	ll cnt1 = merge_sort(0, n);
	cnt1 = cnt - cnt1;
	return (cnt1 >= cnt / 2 + 1);
}

int main()
{
	scanf("%d", &n);
	cnt = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i], cnt += (ll)i;
	sort(b + 1, b + 1 + n);
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(b[mid]))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d\n", b[l]);
	return 0;
}
