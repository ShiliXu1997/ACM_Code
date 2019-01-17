#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=100010;

int cnt;
int fa[MAXN];
bool used[MAXN];

int findfather(int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

int main()
{
    int x,y;
    while(scanf("%d %d",&x,&y)==2&&(x!=-1||y!=-1)){
        memset(used,false,sizeof(used));
        for(int i=1;i<=100005;i++)fa[i]=i;
        int a=x,b=y;
        bool flag=true;
        while(a!=0||b!=0){
            used[a]=true;used[b]=true;
            int p,q;
            p=findfather(a);
            q=findfather(b);
            if(p!=q)
                fa[q]=p;
            else
                flag=false;
            scanf("%d %d",&a,&b);
        }
        int cnt=0;
        for(int i=1;i<=100000;i++)
            if(used[i]&&fa[i]==i)cnt++;
        if(cnt>1)flag=false;
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
