#include<cstdio>
#include<cstring>
using namespace std;

const int MOD=10000;

struct matrix{
    int a[2][2];

    matrix operator*(const matrix &another)
    {
        matrix ans;
        memset(ans.a,0,sizeof(ans.a));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++)
                    ans.a[i][j]+=a[i][k]*another.a[k][j];
                ans.a[i][j]%=MOD;
            }
        return ans;
    }
};

int n;

matrix qpow(matrix a,int b)
{
    matrix ans={{{1,0},{0,1}}};
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
    matrix mat={{{1,1},{1,0}}};
    while(scanf("%d",&n)==1&&n!=-1){
        if(n==0){
            printf("0\n");
            continue;
        }
        matrix res=qpow(mat,n-1);
        printf("%d\n",res.a[0][0]);
    }
    return 0;
}
