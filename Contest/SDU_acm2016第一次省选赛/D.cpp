#define LOCAL
#include<cstdio>
using namespace std;

int qmul(int a,int b,int mod)
{
    int ans=0;
    while(b!=0){
        if(b&1==1)
            ans=(ans+a)%mod;
        a=(a+a)%mod;
        b=b>>1;
    }
    return ans;
}

int qpow(int a,int b,int mod)
{
    int ans=1,base=a;
    while(b!=0){
        if(b&1==1)
            ans=qmul(ans,base,mod);
        base=qmul(base,base,mod);
        b=b>>1;
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif LOCAL
    int cnt=0,N,K,A;
    int a[120];
    int ans[120];
    while(scanf("%lld %lld %lld",&N,&K,&A)==3&&(N!=0||K!=0||A!=0)){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            ans[i]=A;
        }
        while(N--){
            for(int i=1;i<=n;i++){
                ans[i]=qmul(K,ans[i],a[i]);
            }
        }
        printf("Case %d:\n",++cnt);
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
