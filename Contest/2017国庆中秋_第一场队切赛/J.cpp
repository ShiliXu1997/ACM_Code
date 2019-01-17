#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 30;

int n, ord;
int cnt[MAXN];
char buff[MAXN][MAXN];
map<char, int> id;

int main()
{
    while (scanf("%d", &n) == 1) {
        ord = 0;
        id.clear();
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            scanf("%s", buff[i]);
            for (int j = 0; j < n; j++) {
                if (!id.count(buff[i][j]))
                    id[buff[i][j]] = ++ord;
                cnt[id[buff[i][j]]]++;
            }
        }
        int x, y;
        char c;
        bool flag = false;
        for (int a = 0; a < n; a++)
            for (int b = 0; b < n; b++) {
                if (cnt[id[buff[a][b]]] == n - 1)
                    c = buff[a][b];
                if (cnt[id[buff[a][b]]] == 1) {
                    x = a + 1;
                    y = b + 1;
                    flag = true;
                }
            }
        if (!flag) {
            for (int a = 0; a < n && !flag; a++)
                for (int b = 0; b < n && !flag; b++) {
                    if (cnt[id[buff[a][b]]] == n + 1 && !flag) {
                        for (int i = 0; i < n && !flag; i++)
                            if (i != a && buff[i][b] == buff[a][b]) {
                                int tag = true;
                                for (int j = 0; j < n; j++) if (buff[a][j] == c ) tag = false;
                                if (tag) {
                                    x = a + 1;
                                    y = b + 1;
                                    flag = true;
                                }
                            }
                    }
                }
        }
        printf("%d %d %c\n", x, y, c);
    }
    return 0;
}
