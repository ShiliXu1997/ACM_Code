#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10;

int t, n;
int a[MAXN], b[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--) {
        for (int i = 1; i <= 6; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= 6; i++) scanf("%d", &b[i]);
        int awin = 0, bwin = 0;
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 6; j++) {
                if (a[i] > b[j])
                    awin++;
                if (a[i] < b[j])
                    bwin++;
            }
        }
        if (awin > bwin)
            printf("Alice\n");
        else
        if (awin < bwin)
            printf("Bob\n");
        else
            printf("Tie\n");
    }
    return 0;
}
