#include<cstdio>
using namespace std;

const int MAXN=1e5,mod=9901;
int cnt;
int p[MAXN],n[MAXN];

int qmul(int a,int b)
{
    int ans=0;
    while(b!=0){
        if(b&1==1)
            ans=(ans+a)%mod;
        a=(a+a)%mod;
        b=b>>1;
    }
    return ans;
}

int qpow(int a,int b)
{
    int ans=1,base=a;
    while(b!=0){
        if(b&1==1)
            ans=qmul(ans,base);
        base=qmul(base,base);
        b=b>>1;
    }
    return ans;
}

int sum(int p,int n)
{
    if(n==0)return 1;
    if(n%2==1)
        return qmul(sum(p,n/2),(1+qpow(p,n/2+1)))%mod;
    else
        return (qmul(sum(p,n/2-1),(1+qpow(p,n/2+1)))+qpow(p,n/2))%mod;
}

int main()
{
    int a,b,ans=1;
    scanf("%d %d",&a,&b);
    cnt=0;
    for(int i=2;i*i<=a;i++)
        if(a%i==0){
            p[++cnt]=i;
            n[cnt]=0;
            while(a%i==0){
                a/=i;
                n[cnt]++;
            }
            n[cnt]*=b;
        }
    if(a>1){
        p[++cnt]=a;
        n[cnt]=b;
    }
    for(int i=1;i<=cnt;i++)
        ans=ans*sum(p[i],n[i])%mod;
    printf("%d",ans);
	return 0;
}
