#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1e6+5;

int n,m,k,pos;
bool hole[MAXN];
bool drop;

int main()
{
    pos=1;drop=false;
    memset(hole,false,sizeof(hole));
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        hole[x]=true;
    }
    if(hole[1])drop=true;
    for(int i=1;i<=k;i++){
        int st,ed;
        scanf("%d %d",&st,&ed);
        if(drop)continue;
        if(pos==st)pos=ed;
        if(pos==ed)pos=st;
        if(hole[pos])drop=true;
    }
    printf("%d",pos);
    return 0;
}
