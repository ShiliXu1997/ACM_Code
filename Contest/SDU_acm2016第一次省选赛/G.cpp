#define LOCAL
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[5][5];
bool visited[20];

int main()
{
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif LOCAL
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        memset(visited,false,sizeof(visited));
        for(int j=1;j<=4;j++)
            for(int k=1;k<=4;k++){
                scanf("%d",&a[j][k]);
                if(a[j][k]!=-1)visited[a[j][k]]=true;
            }

        printf("\n");
    }
    return 0;
}
