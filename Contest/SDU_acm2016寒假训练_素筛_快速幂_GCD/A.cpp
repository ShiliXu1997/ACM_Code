#include<cstdio>
#include<cmath>
using namespace std;

const int MAXN=10005;
int prime[MAXN];
int total;

bool isprime(int k)
{
    for(int i=1;i<=total;i++)
        if(k%prime[i]==0)return false;
    return true;
}

void init()
{
    prime[++total]=2;
    for(int i=3;i<=MAXN;i++)
        if(isprime(i))
            prime[++total]=i;
}

int main()
{
    init();
    int num,sum,ans=0;
    while(scanf("%d",&num)==1&&num!=0){
        ans=0;
        for(int i=1;i<=total&&prime[i]<=num;i++){
            sum=0;
            for(int j=i;sum<num;j++)
                sum+=prime[j];
            if(sum==num)ans++;
        }
        printf("%d\n",ans);
    }
	return 0;
}

