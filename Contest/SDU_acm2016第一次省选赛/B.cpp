#define LOCAL
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int MAXN=10010;

map<string,int> cnt;
string words[MAXN];
int a[MAXN],ans[MAXN];
int n,num,t;

int main()
{
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif LOCAL
    t=0;
    scanf("%d",&n);
    while(n!=0){
        num=0;
        string str;
        char ch;
        while(cin>>str){
            if(!cnt.count(str)){
                cnt[str]=0;
                words[++num]=str;
            }
            cnt[str]++;
            if(scanf("%c",&ch)&&ch=='\n')break;
        }
        for(int i=1;i<=num;i++)
            a[i]=cnt[words[i]];
        sort(a+1,a+1+num);
        int start=1,wei=0;
        while(a[start]>0){
            ans[++wei]=num-start+1;
            for(int i=start;i<=num;i++)a[i]--;
            while(a[start]==0&&start<=num)start++;
        }
        printf("Case %d: ",++t);
        sort(ans+1,ans+1+wei);
        for(int i=1;i<=wei;i++)printf("%d",ans[i]);
        scanf("%d",&n);
        if(n!=0)printf("\n");
    }
    return 0;
}
