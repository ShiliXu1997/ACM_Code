#include<cstdio>
#include<cstring>
using namespace std;


int main()
{
    int t;
    char a[25][25],str[25];
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,m,cnt=0,x,y;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%s",str);
            int len=strlen(str);
            for(int j=1;j<=len;j++){
                a[i][j]=str[j-1];
                if(a[i][j]=='*'&&cnt==0){
                    x=i;
                    y=j;
                    cnt++;
                }
            }
        }
        for(int i=x+1;i<=n;i++)
            if(a[i][y+1]=='*')cnt++;
        if(cnt==3)
            printf("Case %d: Eight\n",i);
        else
            printf("Case %d: Zero\n",i);
    }
    return 0;
}
