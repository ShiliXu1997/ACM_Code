#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1005,MOD=1e9+7;

int t,n,m;
int C[MAXN][MAXN];

void swap(int *a,int *b)
{
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void init()
{
    C[0][0]=1;C[0][1]=0;
    for(int i=1;i<=1000;i++){
        C[i][0]=1;C[i][i+1]=0;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
}

int main()
{
    init();
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        if(m<n)swap(&m,&n);
        printf("%d\n",C[m][n]);
    }
    return 0;
}
