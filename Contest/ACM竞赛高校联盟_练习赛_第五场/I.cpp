#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const double PI=acos(-1),EPS=1e-8;

int n,R,r;

bool solve(int R,int r,int n)
{
    double dis=sqrt((double)2*R*R-(double)2*R*R*cos(PI*2/n));
    return dis-(double)2*r>=-EPS;
}

int main()
{
    while(scanf("%d %d %d",&n,&R,&r)==3){
        if(n==1){
            if(r<=R)
                printf("yes\n");
            else
                printf("no\n");
            continue;
        }
        if(solve(R-r,r,n))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
