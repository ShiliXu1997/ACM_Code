#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1e5+5,MAXM=101;

int n,q,c;
int rec[MAXM][MAXM][11];

int main()
{
    memset(rec,0,sizeof(rec));
    scanf("%d %d %d",&n,&q,&c);
    for(int i=1;i<=n;i++){
        int x,y,s;
        scanf("%d %d %d",&x,&y,&s);
        rec[x][y][0]+=s;
        for(int j=1;j<=c;j++)rec[x][y][j]+=(s+j)%(c+1);
    }
    for(int k=0;k<=10;k++)
        for(int i=1;i<=100;i++)
            for(int j=1;j<=100;j++)
                rec[i][j][k]+=(rec[i-1][j][k]+rec[i][j-1][k]-rec[i-1][j-1][k]);
    while(q--){
        int t,x1,y1,x2,y2;
        scanf("%d %d %d %d %d",&t,&x1,&y1,&x2,&y2);
        int time=t%(c+1);
        printf("%d\n",rec[x2][y2][time]-rec[x1-1][y2][time]-rec[x2][y1-1][time]+rec[x1-1][y1-1][time]);
    }
    return 0;
}
