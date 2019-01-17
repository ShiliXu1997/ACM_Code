#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXN=600005;

struct flight{
    int cost,id;

    bool operator<(const flight &another)const
    {
        return cost<another.cost;
    }
};

int n,k;
flight a[MAXN];
int pos[MAXN];
priority_queue<flight> q;

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].cost);
        a[i].id=i;
    }
    for(int i=1;i<=k;i++)q.push(a[i]);
    long long ans=0;
    for(int i=k+1;i<=k+n;i++){
        if(i<=n)q.push(a[i]);
        flight plane=q.top();q.pop();
        ans+=(long long)plane.cost*(i-plane.id);
        pos[plane.id]=i;
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)
        printf("%d ",pos[i]);
    return 0;
}
