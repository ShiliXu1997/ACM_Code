#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1e6+5,MAXM=3e6+5;

int n,m,p;
int a[MAXN],b[MAXN],cnt[MAXN];
long long res[MAXM];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int tot=unique(b+1,b+1+n)-(b+1);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+1+tot,a[i])-b;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
        cnt[a[i]]++;
    for(int i=1;i<=tot;i++)
        for(int j=1;j<=tot;j++)
            if(b[i]*b[j]<MAXM)
                res[b[i]*b[j]]+=cnt[i]*(cnt[j]-(i==j));
            else
                break;
    for(int i=1;i<MAXM;i++)res[i]+=res[i-1];
    scanf("%d",&m);
    long long all=(long long)(n-1)*n;
    while(m--){
        scanf("%d",&p);
        printf("%lld\n",all-res[p-1]);
    }
    return 0;
}
