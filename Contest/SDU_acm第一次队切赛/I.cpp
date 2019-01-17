#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=2e5,INF=0x3f3f3f3f;

int n,m;
int deg[MAXN],a[MAXN],b[MAXN],ans[MAXN];

int main()
{
    scanf("%d %d",&n,&m);
    memset(deg,0,sizeof(deg));
    for(int i=1;i<=m;i++){
        int st,ed;
        scanf("%d %d",&st,&ed);
        a[i]=st;b[i]=ed;
        deg[st]++;deg[ed]++;
    }
    int mindeg=INF,u,cnt=0,first;
    for(int i=1;i<=n;i++){
        if(mindeg>deg[i]){
            mindeg=deg[i];
            u=i;
        }
        if(deg[i]==0){
            cnt++;
            if(cnt==1){
                first=i;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)ans[i]=1;
    if(cnt==1){
        ans[first]=0;
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    }
    else
    if(m==0){
        printf("0 ");
        for(int i=2;i<=n;i++)printf("%d ",ans[i]);
    }
    else{
        for(int i=1;i<=m;i++)
            if(a[i]==u||b[i]==u){
                ans[a[i]]=0;
                ans[b[i]]=0;
            }
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    }
    return 0;
}

