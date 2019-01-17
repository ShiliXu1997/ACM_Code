//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月29日 星期日 12时41分30秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int t;
int a[4];

int main()
{
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 4; i++) scanf("%d", &a[i]);
		int ans = -0x3f3f3f3f;
		ans = max(ans, a[0] * a[1] - a[2] * a[3]); ans = max(ans, a[0] * a[1] - a[3] * a[2]);
		ans = max(ans, a[0] * a[2] - a[1] * a[3]); ans = max(ans, a[0] * a[2] - a[3] * a[1]);
		ans = max(ans, a[0] * a[3] - a[1] * a[2]); ans = max(ans, a[0] * a[3] - a[2] * a[1]);
		ans = max(ans, a[1] * a[2] - a[3] * a[0]); ans = max(ans, a[1] * a[2] - a[0] * a[3]);
		ans = max(ans, a[1] * a[3] - a[2] * a[0]); ans = max(ans, a[1] * a[3] - a[0] * a[2]);
		ans = max(ans, a[1] * a[0] - a[2] * a[3]); ans = max(ans, a[1] * a[0] - a[3] * a[2]);
		ans = max(ans, a[2] * a[1] - a[3] * a[0]); ans = max(ans, a[2] * a[1] - a[0] * a[3]);
		ans = max(ans, a[2] * a[3] - a[1] * a[0]); ans = max(ans, a[2] * a[3] - a[0] * a[1]);
		ans = max(ans, a[2] * a[0] - a[1] * a[3]); ans = max(ans, a[2] * a[0] - a[3] * a[1]);
		ans = max(ans, a[3] * a[1] - a[2] * a[0]); ans = max(ans, a[3] * a[1] - a[0] * a[2]);
		ans = max(ans, a[3] * a[2] - a[1] * a[0]); ans = max(ans, a[3] * a[2] - a[0] * a[1]);
		ans = max(ans, a[3] * a[0] - a[1] * a[2]); ans = max(ans, a[3] * a[0] - a[2] * a[1]);
		printf("%d\n", ans);
	}
	return 0;
}
