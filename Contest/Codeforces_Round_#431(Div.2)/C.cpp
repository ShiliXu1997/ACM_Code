#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1005;

int k;

int main()
{
    scanf("%d",&k);
    int now=0;
    for(int i=0;i<26;i++){
        int j=1;
        while(now+(j+1)*j/2<=k)j++;
        for(int index=1;index<=j;index++)
            printf("%c",(char)(i+'a'));
        now+=j*(j-1)/2;
        if(now==k)break;
    }
    return 0;
}
