#include<cstdio>
using namespace std;

const int MAXN=50010;

int n,k,mes,a,b,ans;
int fa[MAXN],rank[MAXN];

int findfather(int x)
{
    if(x==fa[x])
        return x;
    else{
        int tmp=fa[x];
        fa[x]=findfather(fa[x]);
        rank[x]=(rank[x]+rank[tmp])%3;
        return fa[x];
    }
}

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        fa[i]=i;
        rank[i]=0;
    }
    ans=0;
    for(int i=1;i<=k;i++){
        scanf("%d %d %d",&mes,&a,&b);
        if(a>n||b>n){
            ans++;
            continue;
        }
        if(mes==1){
            int p,q;
            p=findfather(a);
            q=findfather(b);
            if(p!=q){
                fa[q]=p;
                rank[q]=(rank[q]+rank[a]-rank[b]+3)%3;
            }
            else
                if(rank[a]!=rank[b])ans++;
        }
        else{
            if(a==b){
                ans++;
                continue;
            }
            int p,q;
            p=findfather(a);
            q=findfather(b);
            if(p!=q){
                fa[q]=p;
                rank[q]=(rank[q]+rank[a]-rank[b]+4)%3;
            }
            else
                if((rank[b]-rank[a]+3)%3!=1)ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
