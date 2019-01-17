#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN=10005;

int t;

long long solve(long long n)
{
    long long ans=0;
    for(int i=1;i<=n;i++){
         ans+=(n-i+1)*(n-i+2)/2;
         if(n>=2*i)ans+=(n-2*i+1)*(n-2*i+2)/2;
    }
    return ans;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        int a,b,s;
        scanf("%d %d %d",&a,&b,&s);
        int step=abs(a)+abs(b);
        if(s>=step&&(s-step)%2==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
