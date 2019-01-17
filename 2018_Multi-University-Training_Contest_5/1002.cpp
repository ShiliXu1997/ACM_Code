//******************************************************************************
// File Name: 1002.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月06日 星期一 12时51分51秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 15;

int t, n, k, cnt;
int num[15], b[15];
bool done[15];
vector<int> pos[10];

void get_num(int n)
{
	cnt = 0;
	for (int i = 0; i <= 9; i++) pos[i].clear();
	int x = n;
	while (x) x /= 10, cnt++;
	for (int i = cnt; i >= 1; i--) {
		num[i] = b[i] = n % 10;
		pos[num[i]].push_back(i);
		n /= 10;
	}
}

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		get_num(n);
		if (k >= cnt - 1) {
			sort(num + 1, num + 1 + cnt);
			memset(done, false, sizeof(done));
			int head = upper_bound(num + 1, num + 1 + cnt, 0) - num;
			printf("%d", num[head]); done[head] = true;
			for (int i = 1; i <= cnt; i++) if (!done[i]) printf("%d", num[i]);
			printf(" ");
			for (int i = cnt; i >= 1; i--) printf("%d", num[i]);
			puts("");
			continue;
		}
		memset(done, false, sizeof(done));
		for (int i = 0, ti = 1; i <= 9 && ti <= k; i++) {
			if (pos[i].size()) {
				sort(pos[i].begin(), pos[i].end(), cmp);
				for (int j = 0; j < pos[i].size() && ti <= k; j++) {
					for (int p = 1; p <= pos[i][j] && ti <= k; p++) {
						if (done[p]) continue;
						if (i == 0 && p == 1) continue;
						if (b[p] == i) {
							done[p] = true;
							continue;
						}
						pos[b[p]].back() = pos[i][j];
						swap(b[p], b[pos[i][j]]);
						done[p] = true;
						ti++;
						break;
					}
				}
				//printf("======= %d\n", i);
				//for (int i = 1; i <= cnt; i++) printf("%d", b[i]);
				//printf("\n");
				//for (int i = 1; i <= cnt; i++) printf("%d", done[i]);
				//printf("\n");
			}
		}
		for (int i = 1; i <= cnt; i++) printf("%d", b[i]);
		printf(" ");
		get_num(n);
		for (int i = 1; i <= cnt; i++) b[i] = num[i];
		memset(done, false, sizeof(done));
		for (int i = 9, ti = 1; i >= 0 && ti <= k; i--) {
			if (pos[i].size()) {
				sort(pos[i].begin(), pos[i].end(), cmp);
				for (int j = 0; j < pos[i].size() && ti <= k; j++) {
					for (int p = 1; p <= pos[i][j] && ti <= k; p++) {
						if (done[p]) continue;
						if (b[p] == i) {
							done[p] = true;
							continue;
						}
						pos[b[p]].back() = pos[i][j];
						swap(b[p], b[pos[i][j]]);
						done[p] = true;
						ti++;
						break;
					}
				}
				//printf("======= %d\n", i);
				//for (int i = 1; i <= cnt; i++) printf("%d", b[i]);
				//printf("\n");
				//for (int i = 1; i <= cnt; i++) printf("%d", done[i]);
				//printf("\n");
			}
		}
		for (int i = 1; i <= cnt; i++) printf("%d", b[i]);
		printf("\n");
	}
	return 0;
}
