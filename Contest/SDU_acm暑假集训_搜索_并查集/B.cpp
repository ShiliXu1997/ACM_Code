#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

const int MAXN=1010;

int n,d,a,b;
char s[10];
int fa[MAXN],x[MAXN],y[MAXN];
bool ok[MAXN];
vector<int> link[MAXN];

double dist(const int i,const int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int findfather(int x)
{
    return (x==fa[x]?x:fa[x]=findfather(fa[x]));
}

int main()
{
    memset(ok,false,sizeof(ok));
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x[i],&y[i]);
        fa[i]=i;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j&&dist(i,j)<=d){
                link[i].push_back(j);
            }
    while(scanf("%s",s)!=EOF){
        if(s[0]=='O'){
            scanf("%d",&a);
            ok[a]=true;
            for(int i=0;i<link[a].size();i++)
                if(ok[link[a][i]]){
                    int p,q;
                    p=findfather(a);
                    q=findfather(link[a][i]);
                    if(p!=q)fa[q]=p;
                }
        }
        else{
            scanf("%d %d",&a,&b);
            if(!ok[a]||!ok[b])
                printf("FAIL\n");
            else{
                int p,q;
                p=findfather(a);
                q=findfather(b);
                if(p==q)
                    printf("SUCCESS\n");
                else{
                    bool flag=false;
                    for(int i=0;i<link[a].size()&&!flag;i++)
                        if(link[a][i]==b){
                            printf("SUCCESS\n");
                            flag=true;
                        }
                    if(!flag){
                        for(int i=1;i<=n&&!flag;i++){
                            if(ok[i]&&findfather(i)==p)
                                for(int j=0;j<link[i].size()&&!flag;j++)
                                    if(ok[j]&&findfather(link[i][j])==q){
                                        printf("SUCCESS\n");
                                        flag=true;
                                    }
                        }
                    }
                    if(!flag)printf("FAIL\n");
                }
            }
        }
    }
    return 0;
}
