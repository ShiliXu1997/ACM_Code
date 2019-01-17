#include<cstdio>
#include<cmath>
using namespace std;

const int MAXN=105,INF=0x3f3f3f3f;

int n,m,k;
int a[MAXN];

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int dist=INF;
    for(int i=1;i<=n;i++)
        if(a[i]!=0&&abs(m-i)<dist&&a[i]<=k)
            dist=abs(m-i);
    printf("%d",dist*10);
    return 0;
}
