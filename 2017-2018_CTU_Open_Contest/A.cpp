#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int n;
int a[MAXN];

int main()
{
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		if (n == 1) {
			printf("1\n");
			continue;
		}
		int ans = n - 1, diff = a[n] - a[n - 1];
		while (ans - 1 > 0 && diff == a[ans] - a[ans - 1]) ans--;
		printf("%d\n", ans);
	}
    return 0;
}
