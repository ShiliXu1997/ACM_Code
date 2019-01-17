#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;

int n;
int a[MAXN];
bool visited[MAXN];

int main()
{
	while (scanf("%d", &n) == 1) {
		int ans = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
			for (int i = 1; i <= n; i++) {
			if (!visited[i] && a[i] != i) {
				int nxt = a[i], cnt = 1;
				visited[i] = true;
				if (a[nxt] == i) {
					visited[nxt] = true;
					cnt++;
				}
				while (a[nxt] != i) {
					visited[nxt] = true;
					nxt = a[nxt];
					cnt++;
					if (a[nxt] == i) {
						visited[nxt] = true;
						cnt++;
					}
				}
				ans += cnt - 1;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
