#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int MAXN=100005;

int t,n,cnt;
int num[MAXN],sum[MAXN];
map<int,int> id;

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        id.clear();
        memset(num,0,sizeof(num));
        memset(sum,0,sizeof(sum));
        cnt=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(!id.count(x))id[x]=++cnt;
            num[id[x]]++;
        }
        bool flag=false;
        for(int i=1;i<=cnt;i++){
            sum[i]=sum[i-1]+num[i];
            if(num[i]>1)flag=true;
        }
        long long ans=0;
        for(int i=1;i<=cnt;i++)
            ans+=(long long)(n-sum[i])*num[i];
        printf("%lld\n",flag?ans+1:ans);
    }
    return 0;
}
