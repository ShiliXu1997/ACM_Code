#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    char s[3];
    int x, a = 0, b = 1023;
    while (n--) {
        scanf("%s %d", s, &x);
        if (s[0] == '&') {a &= x; b &= x;}
        if (s[0] == '|') {a |= x; b |= x;}
        if (s[0] == '^') {a ^= x; b ^= x;}
    }
    int and_num = a | b, or_num = a & b, xor_num = 0;
    for (int i = 0; i < 10; i++)
        if (((a >> i) & 1) && !((b >> i) & 1)) xor_num |= (1 << i);
    printf("3\n");
    printf("& %d\n", and_num);
    printf("| %d\n", or_num);
    printf("^ %d\n", xor_num);
    return 0;
}
