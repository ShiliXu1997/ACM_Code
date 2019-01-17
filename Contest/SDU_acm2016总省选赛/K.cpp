#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const double INF=0x3f3f3f3f;

double path[20][20];
double thr[20];
bool visited[20][(1<<18)+5];
double dp[20][(1<<18)+5];
int x[20],y[20];
int w,l,n;

double min(const double a,const double b)
{
    return (a<b?a:b);
}

double dis(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double up(int x1,int y1,int x2,int y2)
{
    int xx=x1,yy=2*l-y1;
    return dis(xx,yy,x2,y2);
}

double down(int x1,int y1,int x2,int y2)
{
    int xx=x1,yy=-y1;
    return dis(xx,yy,x2,y2);
}

double left(int x1,int y1,int x2,int y2)
{
    int xx=-x1,yy=y1;
    return dis(xx,yy,x2,y2);
}

double right(int x1,int y1,int x2,int y2)
{
    int xx=2*w-x1,yy=y1;
    return dis(xx,yy,x2,y2);
}

double dfs(int num,int t)
{
    if(visited[num][t])return dp[num][t];
    visited[num][t]=true;
    double &ans=dp[num][t];
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(t>>(i-1)&1)cnt++;
    if(cnt==0)return ans=thr[num];
    else{
        ans=INF;
        for(int i=1;i<=n;i++)
            if(t>>(i-1)&1)
                ans=min(ans,path[num][i]+dfs(i,t&(~(1<<(i-1)))));
        return ans;
    }
}

double findthrow(int i)
{
    return min(min((double)l-y[i],(double)y[i]),min((double)x[i],(double)w-x[i]));
}

int main()
{
    freopen("kitchen.in","r",stdin);
    freopen("kitchen.out","w",stdout);
    scanf("%d %d",&w,&l);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i==j)
                path[i][j]=0;
            else
                path[i][j]=INF;
    }
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x[i],&y[i]);
        for(int j=1;j<=i-1;j++){
            path[i][j]=min(path[i][j],up(x[i],y[i],x[j],y[j]));
            path[i][j]=min(path[i][j],down(x[i],y[i],x[j],y[j]));
            path[i][j]=min(path[i][j],left(x[i],y[i],x[j],y[j]));
            path[i][j]=min(path[i][j],right(x[i],y[i],x[j],y[j]));
            path[i][j]=min(path[i][j],path[j][i]);
            path[j][i]=path[i][j];
        }
    }
    scanf("%d %d",&x[0],&y[0]);
    for(int i=1;i<=n;i++)
        thr[i]=findthrow(i);
    memset(visited,false,sizeof(visited));
    double ans=INF;
    for(int i=1;i<=n;i++)ans=min(ans,dfs(i,((1<<n)-1)&~(1<<(i-1)))+dis(x[0],y[0],x[i],y[i]));
    printf("%.14f",ans);
    return 0;
}
