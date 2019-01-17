#include<cstdio>
#include<vector>
using namespace std;

const int MAXN=2e5+5;

int n,m;
int door[MAXN],fa[MAXN*2];
vector<int> open[MAXN];

int findfather(const int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

void unite(const int a,const int b)
{
    int p,q;
    p=findfather(a);
    q=findfather(b);
    if(p!=q)fa[q]=p;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&door[i]);
    int num;
    for(int i=1;i<=m;i++){
        fa[i]=i;fa[i+m]=i+m;
        scanf("%d",&num);
        int x;
        for(int j=1;j<=num;j++){
            scanf("%d",&x);
            open[x].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(door[i]==1){
            unite(open[i][0],open[i][1]);
            unite(open[i][0]+m,open[i][1]+m);
        }
        else{
            unite(open[i][0],open[i][1]+m);
            unite(open[i][0]+m,open[i][1]);
        }
    }
    bool flag=true;
    for(int i=1;i<=m;i++){
        if(findfather(i)==findfather(i+m)){
            flag=false;
            break;
        }
    }

    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
