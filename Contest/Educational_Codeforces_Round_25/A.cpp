#include<cstdio>
using namespace std;

int n;
char s[100];

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            cnt++;
            if(i==n-1)printf("%d",cnt);
        }
        else{
            printf("%d",cnt);
            cnt=0;
            if(i==n-1)printf("%d",cnt);
        }
    }
    return 0;
}
