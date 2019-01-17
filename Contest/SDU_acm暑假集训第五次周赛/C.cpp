#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=500;

int total,n,k;
int prime[MAXN+10],num[MAXN];
bool boolprime[MAXN+10];

void euler(int n)
{
    memset(boolprime,false,sizeof(boolprime));
    total=0;
    for(int i=2;i<=n;i++){
        if(!boolprime[i])prime[++total]=i;
        for(int j=1;j<=total&&i*prime[j]<=n;j++){
            boolprime[i*prime[j]]=true;
            if(i%prime[j]==0)break;
        }
    }
}

void add(int mes,int n)
{
    for(int i=1;i<=total&&prime[i]<=n;i++){
        int tmp=prime[i];
        while(tmp<=n){
            if(mes==1)
                num[i]+=n/tmp;
            else
                num[i]-=n/tmp;
            tmp*=prime[i];
        }
    }
}

int main()
{
    euler(431);
    while(scanf("%d %d",&n,&k)==2){
        memset(num,0,sizeof(num));
        add(1,n);
        add(0,k);
        add(0,n-k);
        long long ans=1;
        for(int i=1;i<=total;i++)
            ans*=(num[i]+1);
        printf("%lld\n",ans);
    }
    return 0;
}
