#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=1e5+10;
int n;
long long k;
int a[MAXN];

bool check(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++){
		int pos=upper_bound(a+i,a+1+n,a[i]+x)-a;
		sum+=pos-i-1;
	}
	if(sum>=k)
		return true;
	else
		return false;
}

int main()
{
    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        k=((long long)n*(n-1)/2+1)/2;
        int l=0,r=a[n]-a[1];
        while(l<r){
        	int mid=(l+r)>>1;
        	if(check(mid))
				r=mid;
        	else
        		l=mid+1;
        }
		printf("%d\n",l);
    }
	return 0;
}
