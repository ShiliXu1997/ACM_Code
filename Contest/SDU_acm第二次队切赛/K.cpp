#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int c[100005];
int k[10],score[10];
int T,a,b,n;

int main() {
    scanf("%d",&T);
    while (T--){
        scanf("%d %d %d",&a,&b,&n);
        memset(score,0,sizeof(score));
        int x=1,num=0;
        while(a*x*x+b*x<=n){
            c[num++]=a*x*x+b*x;
            x++;
        }
        if(num==0)
            printf("-1\n");
        else{
            for(int i=0;i<num;i++){
                memset(k,0,sizeof(k));
                while(c[i]!=0){
                    k[c[i]%10]++;
                    c[i]/= 10;
                }
                int times=0;
                for(int i=0;i<10;i++)
                    if(times<k[i])
                        times=k[i];
                for(int i=0;i<10;i++)
                    if(k[i]==times)score[i]++;
            }
            int ans,cnt=0;
            for(int i=0;i<10;i++)
                if(cnt<score[i]){
                    cnt=score[i];
                    ans=i;
                }
            printf("%d\n",ans);
        }
    }
    return 0;
}
