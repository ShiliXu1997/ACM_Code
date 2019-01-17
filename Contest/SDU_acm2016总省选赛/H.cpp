#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105;

int n;
bool discover[MAXN];

int main()
{
    freopen("horrible.in","r",stdin);
    freopen("horrible.out","w",stdout);
    scanf("%d",&n);
    memset(discover,false,sizeof(discover));
    if(n==1){
        printf("1\n");
        printf("1 0\n");
    }
    else{
        printf("%d\n",(2*n-1)*(n-1)+3);
        printf("2 -1\n");
        for(int i=1;i<=n-1;i++){
            printf("%d 0\n",i);
            int ii=1,jj=1;
            for(int j=1;j<=n-1;j++){
                if(ii==i){
                    printf("%d %d\n",++ii,i);
                    ii++;
                }
                else
                    printf("%d %d\n",ii++,i);
                if(jj==i+1){
                    printf("%d -%d\n",++jj,i+1);
                    jj++;
                }
                else
                    printf("%d -%d\n",jj++,i+1);
            }
        }
        printf("%d 0\n",n);
        printf("1 %d\n",n);
    }
    return 0;
}
close
