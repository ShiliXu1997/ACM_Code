#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 35;

char s[MAXN];

int main()
{
    scanf("%s", &s);
    int len = strlen(s), x1, x2, y1, y2;
    x1 = 0; x2 = pow(2, len) - 1; y1 = 0; y2 = pow(2, len) - 1;
    for (int i = 0; i < len; i++) {
        int midx = (x1 + x2) / 2, midy = (y1 + y2) / 2;
        if (s[i] == '0') {
            x2 = midx;
            y2 = midy;
        }
        else
        if (s[i] == '1') {
            x1 = midx;
            y2 = midy;
        }
        else
        if (s[i] == '2') {
            x2 = midx;
            y1 = midy;
        }
        else
        if (s[i] == '3') {
            x1 = midx;
            y1 = midy;
        }
    }
    printf("%d %d %d\n", len, x2, y2);
    return 0;
}
