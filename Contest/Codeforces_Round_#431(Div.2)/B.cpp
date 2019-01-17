#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1005;
const double EPS=1e-8;

int n,cnt,stand1,stand2,tmp;
int y[MAXN];
double gradient;

bool isequal(double a,double b)
{
    return -EPS<=(a-b)&&(a-b)<=EPS;
}

double getratio(int i,int j)
{
    return (double)(y[i]-y[j])/(i-j);
}

int main()
{
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&y[i]);
    bool flag,num;
    for(int i=1;i<=2;i++){
        stand1=i;
        for(int j=i+1;j<=3;j++){
            flag=true;num=false;
            gradient=getratio(stand1,j);
            for(int k=1;k<=n;k++){
                if(k==i||k==j)continue;
                if(!num&&!isequal(gradient,getratio(stand1,k))){
                    stand2=k;
                    num=true;
                    continue;
                }
                if(!isequal(gradient,getratio(stand1,k))&&!isequal(gradient,getratio(stand2,k))){
                    flag=false;
                    break;
                }
            }
            if(flag&&num)break;
        }
        if(flag&&num)break;
    }
    if(flag&&num)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
