#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        while(n--){
            char str[100];
            scanf("%s",str);
            int len=strlen(str);
            for(int k=1;k<=len;k++)
                if(len%k!=0)continue;
                else{
                    int time=len/k;
                    bool flag=true;
                    for(int j=0;j<k&&flag;j++)
                        for(int i=0;i<time;i++)
                            if(str[j]!=str[j+i*k]){
                                flag=false;
                                break;
                            }
                    if(flag){
                        printf("%d\n",k);
                        break;
                    }
                }
        }
        printf("\n");
    }
    return 0;
}
