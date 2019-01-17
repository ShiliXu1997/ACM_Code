#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;

char str[MAXN];

int main()
{
    scanf("%s", str);
    int len = strlen(str), ans = 0;
    for (int i = 0; i < len; i++) {
        int cnt_1 = 0, cnt_2 = 0;
        if (str[i] == 'A') {
            for (int j = 0; j < i; j++) if (str[j] == 'Q') cnt_1++;
            for (int j = i + 1; j < len; j++) if (str[j] == 'Q') cnt_2++;
            ans += cnt_1 * cnt_2;
        }
    }
    printf("%d", ans);
    return 0;
}
