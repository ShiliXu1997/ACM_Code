#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=15;
const double EPS=1e-9;

double room,ans;
int t,s,cnt;
int w[MAXN];
bool ava[MAXN];
double l[MAXN],r[MAXN];

void build_tree(int deep)
{
    if(deep==s)return;
    for(int i=1;i<=11;i++)
        if(ava[i]){
            ava[i]=false;
            for(int j=1;j<=11;j++)
                if(ava[j]){
                    double left=max(l[i],l[j]-1),right=max(r[j],r[i]-1);
                    if(left+right+1>room-EPS)continue;
                    if(deep==s-1)ans=max(ans,left+right+1);
                    ava[j]=false;
                    cnt++;
                    w[cnt]=w[i]+w[j];
                    l[cnt]=left+(double)w[j]/w[cnt];
                    r[cnt]=right+(double)w[i]/w[cnt];
                    ava[cnt]=true;
                    build_tree(deep+1);
                    ava[cnt]=false;
                    cnt--;
                    ava[j]=true;
                }
            ava[i]=true;
        }
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lf",&room);
        scanf("%d",&s);
        cnt=0;
        memset(ava,false,sizeof(ava));
        for(int i=1;i<=s;i++){
            scanf("%d",&w[i]);
            ava[i]=true;
            cnt++;
        }
        if(s==1)
            printf("0.0000000000000000\n");
        else{
            memset(l,0,sizeof(l));
            memset(r,0,sizeof(r));
            ans=0;
            build_tree(1);
            if(fabs(ans)<EPS)
                printf("-1\n");
            else
                printf("%.16f\n",ans);
        }
    }
    return 0;
}
