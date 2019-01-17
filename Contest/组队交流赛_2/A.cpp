#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=200005;

int t,n,m;

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        long long ans=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            int res=x%m;
            if(res==0)continue;
            res=m-res;
            ans+=(long long)res;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
