#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=14,MOD=1e7+7;

int n,m;
int b[MAXN];

struct matrix{
    long long a[MAXN][MAXN];

    matrix()
    {
        memset(a,0,sizeof(a));
    }

    matrix operator*(const matrix &another)
    {
        matrix ans;
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=n+1;j++){
                for(int k=0;k<=n+1;k++)
                    ans.a[i][j]+=a[i][k]*another.a[k][j];
                ans.a[i][j]%=MOD;
            }
        return ans;
    }
};

matrix qpow(matrix a,int b)
{
    matrix ans;
    for(int i=0;i<=n+1;i++)ans.a[i][i]=1;
    while(b!=0){
        if(b&1==1)
            ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}

int main()
{
    while(scanf("%d %d",&n,&m)==2){
        b[0]=23;b[n+1]=3;
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        matrix mat;
        for(int i=0;i<=n;i++)
            mat.a[i][0]=10;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++)
                mat.a[i][j]=1;
            mat.a[i][n+1]=1;
        }
        mat.a[0][n+1]=1;
        mat.a[n+1][n+1]=1;
        matrix mat1=qpow(mat,m);
        long long ans=0;
        for(int i=0;i<=n+1;i++)
            ans=(ans+mat1.a[n][i]*b[i])%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
