#include<cstdio>
using namespace std;

const int MAXN=1000;
int ans[MAXN+10],euler[MAXN+10];

void geteuler()
{
    for(int i=1;i<=MAXN;i++)
        euler[i]=i;
    for(int i=2;i<=MAXN;i++)
        if(euler[i]==i)
            for(int j=i;j<=MAXN;j+=i)
                euler[j]=euler[j]/i*(i-1);
}

void solve()
{
    geteuler();
    ans[1]=3;
    for(int i=2;i<=MAXN;i++)
        ans[i]=euler[i]*2+ans[i-1];
}

int main()
{
    int t;
    solve();
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        printf("%d %d %d\n",i,n,ans[n]);
    }
	return 0;
}
