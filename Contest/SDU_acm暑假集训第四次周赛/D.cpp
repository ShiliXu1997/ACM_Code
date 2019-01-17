#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1005;
const long long INF=0x3f3f3f3f3f3f3f3f;

int n,total;
long long ans;
int prime[MAXN];
bool boolprime[MAXN];

void getprime(int n)
{
    total=0;
    memset(boolprime,false,sizeof(boolprime));
    for(int i=2;i<=n;i++){
        if(!boolprime[i])prime[++total]=i;
        for(int j=1;j<=total&&i*prime[j]<=n;j++){
            boolprime[i*prime[j]]=true;
            if(i%prime[j]==0)break;
        }
    }
}

void dfs(int deep,long long res,int num)
{
    if(num==n){
        ans=min(ans,res);
        return;
    }
    long long tmp=prime[deep];
    for(int i=1;i<=1000;i++){
        if(res*tmp>ans||res*tmp<0||num*(i+1)>n)return;
        dfs(deep+1,res*tmp,num*(i+1));
        tmp*=prime[deep];
    }
}

int main()
{
    getprime(1000);
    scanf("%d",&n);
    ans=INF;
    dfs(1,1,1);
    printf("%lld\n",ans);
    return 0;
}
