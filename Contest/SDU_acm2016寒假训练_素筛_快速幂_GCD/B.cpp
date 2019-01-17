#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

const int MAXN=46500,MAXA=1000010;
int total,cnt;
long long prime[MAXN],a[MAXA];
bool boolprime[MAXN],boola[MAXA];

void init()
{
    total=0;
    memset(boolprime,false,sizeof(boolprime));
    for(int i=2;i*i<=MAXN;i++)
        if(!boolprime[i])
            for(int j=i*i;j<=MAXN;j+=i)
                boolprime[j]=true;
    for(int i=2;i<=MAXN;i++)
        if(!boolprime[i])
            prime[++total]=(long long)i;
}

void getprime(long long l,long long r)
{
    cnt=0;
    if(r<=prime[total]){
        for(int i=1;prime[i]<=r;i++)
            if(prime[i]>=l)
                a[++cnt]=prime[i];
    }
    else{
        memset(boola,false,sizeof(boola));
        for(int i=1;prime[i]*prime[i]<=r;i++){
            long long k=l/prime[i],pile;
            if(k*prime[i]<l)k++;
            if(k<=1)k++;
            pile=k*prime[i];
            while(pile<=r){
                boola[pile-l]=true;
                pile+=prime[i];
            }
        }
        for(int i=0;i<=r-l;i++)
            if(!boola[i])
                a[++cnt]=(long long)(i+l);
    }
}

int main()
{
    init();
    long long L,U;
    while(scanf("%lld %lld",&L,&U)==2){
        getprime(L,U);
        if(cnt<2)
            printf("There are no adjacent primes.\n");
        else{
            int mindist=MAXA,maxdist=0,dist;
            long long minl,minr,maxl,maxr;
            for(int i=1;i<cnt;i++){
                dist=a[i+1]-a[i];
                if(dist>maxdist){
                    maxdist=dist;
                    maxl=a[i];
                    maxr=a[i+1];
                }
                if(dist<mindist){
                    mindist=dist;
                    minl=a[i];
                    minr=a[i+1];
                }
            }
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",minl,minr,maxl,maxr);
        }
    }
	return 0;
}
