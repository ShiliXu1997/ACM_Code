#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=20;

int n,cnt;
long long len[MAXN];
bool visited[MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&len[i]);
    sort(len+1,len+1+n);
    cnt=0;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n-2;i++){
        if(visited[i])continue;
        for(int j=i+1;j<=n-1;j++){
            if(visited[j])continue;
            long long sum=len[i]+len[j];
            for(int k=j+1;k<=n;k++){
                if(visited[k])continue;
                if(!visited[i]&&!visited[j]&&!visited[k]
                &&sum>len[k]&&len[k]-len[i]<len[j]&&len[k]-len[j]<len[i]){
                    cnt++;
                    visited[i]=true;
                    visited[j]=true;
                    visited[k]=true;
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
