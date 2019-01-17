#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=52,MOD=10000;

int n,m,st,ed,k,fish;
int t[25];
int f[25][5];

struct matrix{
    int a[MAXN][MAXN];

    matrix()
    {
        memset(a,0,sizeof(a));
    }

    matrix operator*(const matrix &another)const
    {
        matrix ans;
        for(int i=0;i<=n-1;i++)
            for(int j=0;j<=n-1;j++){
                for(int k=0;k<=n-1;k++)
                    ans.a[i][j]+=a[i][k]*another.a[k][j];
                ans.a[i][j]%=MOD;
            }
        return ans;
    }
};

matrix link[15];

matrix qpow(matrix a,int b)
{
    matrix ans;
    for(int i=0;i<=n-1;i++)ans.a[i][i]=1;
    while(b!=0){
        if(b&1==1)ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}

int main()
{
    scanf("%d %d %d %d %d",&n,&m,&st,&ed,&k);
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        link[0].a[a][b]=1;
        link[0].a[b][a]=1;
    }
    scanf("%d",&fish);
    for(int i=1;i<=fish;i++){
        scanf("%d",&t[i]);
        for(int j=0;j<t[i];j++)
            scanf("%d",&f[i][j]);
    }
    for(int i=1;i<=12;i++){
        link[i]=link[0];
        for(int j=1;j<=fish;j++)
            for(int k=0;k<=n-1;k++)
                link[i].a[k][f[j][i%t[j]]]=0;
    }
    matrix mat;
    for(int i=0;i<=n-1;i++)mat.a[i][i]=1;
    for(int i=1;i<=12;i++)mat=mat*link[i];
    mat=qpow(mat,k/12);
    for(int i=1;i<=k%12;i++)mat=mat*link[i];
    printf("%d",mat.a[st][ed]);
    return 0;
}
