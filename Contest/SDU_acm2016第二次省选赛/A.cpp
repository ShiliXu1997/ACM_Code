#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1005;

int tickets[MAXN];

int max(const int a,const int b)
{
    return (a>b?a:b);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(tickets,0,sizeof(tickets));
        int n,x;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            tickets[x]++;
        }
        int ans=0,cnt=0;
        for(int i=1;i<=1000;i++)
            ans=(tickets[ans]>tickets[i]?ans:i);
        for(int i=1;i<=1000;i++)
            if(tickets[i]==tickets[ans])cnt++;
        if(cnt==1)
            printf("%d\n",ans);
        else
            printf("Nobody\n");
    }
    return 0;
}
