#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int s,v1,v2,t1,t2;

int main()
{
    scanf("%d %d %d %d %d",&s,&v1,&v2,&t1,&t2);
    long long res1=s*v1+2*t1,res2=s*v2+2*t2;
    if(res1<res2)
        printf("First\n");
    else
    if(res1>res2)
        printf("Second\n");
    else
        printf("Friendship\n");
    return 0;
}
