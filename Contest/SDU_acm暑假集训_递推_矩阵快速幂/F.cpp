#include<cstdio>
#include<cstring>
using namespace std;

int n,k,m;

struct matrix{
    long long a[62][62];

    matrix()
    {
        memset(a,0,sizeof(a));
    }

    matrix operator+(const matrix &another)
    {
        matrix ans;
        for(int i=1;i<=2*n;i++)
            for(int j=1;j<=2*n;j++)
                ans.a[i][j]=(a[i][j]+another.a[i][j]);
        return ans;
    }

    matrix operator*(const matrix &another)
    {
        matrix ans;
        for(int i=1;i<=2*n;i++)
            for(int j=1;j<=2*n;j++){
                for(int k=1;k<=2*n;k++)
                    ans.a[i][j]+=a[i][k]*another.a[k][j];
                ans.a[i][j]%=m;
            }
        return ans;
    }
};

matrix qpow(matrix a,int b)
{
    matrix ans;
    for(int i=1;i<=2*n;i++)ans.a[i][i]=1;
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
    matrix mat,ans;
    memset(mat.a,0,sizeof(mat.a));
    memset(ans.a,0,sizeof(ans.a));
    scanf("%d %d %d",&n,&k,&m);
    for(int i=n+1;i<=2*n;i++)
        ans.a[i][i]=1;
    for(int i=1;i<=n;i++)
        ans.a[i][i+n]=1;
    for(int i=n+1;i<=2*n;i++)
        ans.a[i][i-n]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&ans.a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mat.a[i][j]=ans.a[i][j];
    for(int i=n+1;i<=2*n;i++)
        for(int j=1;j<=n;j++)
            mat.a[i][j]=ans.a[i-n][j];
    for(int i=n+1;i<=2*n;i++)
            mat.a[i][i]=1;
    ans=ans*qpow(mat,k-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%lld ",ans.a[i][j]%m);
        printf("\n");
    }
    return 0;
}
