#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=100,INF=0x3f3f3f3f;

struct block{
    int x,y,z;

    bool operator<(const block &another)const{
        return x*y<another.x*another.y;
    }
};

int n,cnt,kase,ans;
block b[MAXN];
int dp[MAXN];

int main()
{
    kase=0;
    while(scanf("%d",&n)==1&&n!=0){
        cnt=0;
        for(int i=1;i<=n;i++){
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            b[++cnt].x=x;b[cnt].y=y;b[cnt].z=z;
            b[++cnt].x=z;b[cnt].y=x;b[cnt].z=y;
            b[++cnt].x=y;b[cnt].y=z;b[cnt].z=x;
        }
        sort(b+1,b+1+cnt);
        ans=0;
        for(int i=1;i<=cnt;i++){
            dp[i]=b[i].z;
            for(int j=1;j<=i-1;j++)
                if(b[i].x>b[j].x&&b[i].y>b[j].y||b[i].x>b[j].y&&b[i].y>b[j].x)
                    dp[i]=max(dp[i],dp[j]+b[i].z);
            ans=max(ans,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",++kase,ans);
    }
    return 0;
}
