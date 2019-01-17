#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=10005;

int t,cnt,n,m;
int factor[MAXN],vis[MAXN],num[MAXN];

int gcd(int a,int b)
{
    return (b==0?a:gcd(b,a%b));
}

int main()
{
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        scanf("%d %d",&n,&m);
        cnt=0;
        for(int i=1;i*i<=m;i++){
            if(m%i==0){
                factor[++cnt]=i;
                if(i*i!=m)factor[++cnt]=m/i;
            }
        }
        sort(factor+1,factor+1+cnt);
        cnt--;
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++){
            int a,step;
            scanf("%d",&a);
            step=gcd(a,m);
            for(int j=1;j<=cnt;j++)
                if(factor[j]%step==0)vis[j]=1;
        }
        long long ans=0;
        for(int i=1;i<=cnt;i++){
            if(num[i]!=vis[i]){
                int diff=vis[i]-num[i],amount=m/factor[i];
                ans+=(long long)(amount-1)*amount/2*diff*factor[i];
                for(int j=i;j<=cnt;j++)
                    if(factor[j]%factor[i]==0)num[j]+=diff;
            }
        }
        printf("Case #%d: %lld\n",kase,ans);
    }
    return 0;
}
