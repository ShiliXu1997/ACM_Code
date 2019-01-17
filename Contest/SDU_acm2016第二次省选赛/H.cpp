#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1050,INF=0x3f3f3f3f;
const double EPS=1e-8;

int x[MAXN],y[MAXN];
double k[MAXN*MAXN];

int max(const int a,const int b)
{
    return (a>b?a:b);
}

int main()
{
    int n,kase=0;
    while(scanf("%d",&n)==1&&n!=0){
        int ans=0;
        for(int i=1;i<=n;i++)scanf("%d %d",&x[i],&y[i]);
        for(int i=1;i<=n;i++){
            int j=i+1,cnt=0;
            while(j<=n){
                if(x[i]==x[j])
                    k[++cnt]=INF;
                else
                    k[++cnt]=((double)y[i]-y[j])/(x[i]-x[j]);
                j++;
            }
            sort(k+1,k+1+cnt);
            for(int p=1;p<=cnt;p++){
                int t=1;
                while(p+1<=cnt&&k[p+1]-k[p]<EPS){
                    p++;
                    t++;
                }
                ans=max(ans,t+1);
            }
        }
        if(ans<4)ans=0;
        printf("Photo %d: %d points eliminated\n",++kase,ans);
    }
    return 0;
}
