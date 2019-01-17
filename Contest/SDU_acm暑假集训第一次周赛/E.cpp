#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

const int MAXN=2e5+2;

int nest,cnt,f;
map<string,int> id;
int fa[MAXN],num[MAXN];

int findfather(const int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

int main()
{
    while(scanf("%d",&nest)!=EOF){
        while(nest--){
            id.clear();
            cnt=0;
            for(int i=1;i<=MAXN;i++)num[i]=1;
            for(int i=1;i<=MAXN;i++)fa[i]=i;
            scanf("%d",&f);
            while(f--){
                char s[25],t[25];
                scanf("%s %s",s,t);
                if(!id.count(s))id[s]=++cnt;
                if(!id.count(t))id[t]=++cnt;
                int p,q;
                p=findfather(id[s]);
                q=findfather(id[t]);
                if(p!=q){
                    fa[q]=p;
                    num[p]=num[p]+num[q];
                }
                printf("%d\n",num[p]);
            }
        }
    }
    return 0;
}
