#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

const int MAXN=100005;

int t,n,cnt;
int num[MAXN];
map<int,int> id;
priority_queue<int> q;

int main()
{
    scanf("%d",&t);
    while(t--){
        cnt=0;
        memset(num,0,sizeof(num));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(!id.count(x))
                id[x]=++cnt;
            num[id[x]]++;
        }
        sort(num+1,num+1+cnt);
        for(int i=1;i<=cnt;i++)
            q.push(num[i]);
        int ans=0,a,b;
        if(!q.empty()){
            a=q.top();q.pop();
        }
        if(!q.empty()){
            b=q.top();q.pop();
        }
        while(!q.empty()&&a>0&&b>0){
            int c=q.top();q.pop();
            a--;b--;c--;ans++;
            if(a>0)q.push(a);
            if(b>0)q.push(b);
            if(c>0)q.push(c);
            if(!q.empty()){
                a=q.top();q.pop();
            }
            if(!q.empty()){
                b=q.top();q.pop();
            }
        }
        printf("%d\n",ans);
        id.clear();
        while(!q.empty())q.pop();
    }
    return 0;
}
