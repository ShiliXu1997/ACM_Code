#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=10;

int a[MAXN];
int n,m,x;

int main()
{
    freopen("acm.in","r",stdin);
    freopen("acm.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&x);
    for(int i=1;i<=n;i++){
        printf("( 10 ");
        for(int j=1;j<=a[i];j++)
            printf("- 1 ");
        if(i<n)
            printf(") * ");
        else
            printf(") = 0");
    }
    return 0;
}
