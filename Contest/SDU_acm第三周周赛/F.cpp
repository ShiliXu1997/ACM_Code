#include<cstdio>
using namespace std;

int main()
{
    int n,k,ans,total=0,time;
    scanf("%d %d",&n,&k);
    time=240-k;
    for(int i=1;i<=n;i++){
        if(total+i*5>time){
            printf("%d",i-1);
            break;
        }
        total+=i*5;
        if(i==n)printf("%d",i);
    }
	return 0;
}
