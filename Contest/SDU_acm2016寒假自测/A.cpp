#include<cstdio>
#include<cstring>
using namespace std;

int num[15];
bool visited[15];
int cnt;

int dist()
{
    int d=1e9,ans=1e9;
    for(int i=1;i<cnt;i++)
    	if(num[i]!=0) {
        	d=num[i+1]-num[i];
        	if(d<ans)ans=d;
    	}
    return ans;
}

int solve_even()
{
    int ans;
    if(cnt==2)
        ans=num[2]-num[1];
    else{
        int d=dist(),mid=cnt/2;
        ans=1e9;
        for(int i=1;i<cnt;i++)
            if(num[i]!=0&&num[i+1]-num[i]==d){
                memset(visited,false,sizeof(visited));
                visited[i]=true;visited[i+1]=true;
                int sum1=num[i],sum2=num[i+1],l=1,r=cnt,x=1;
                while(x<mid){
                    while(visited[l]&&l<=cnt)l++;
                    while(visited[r]&&r>=1)r--;
                    sum1=sum1*10+num[r--];
                    sum2=sum2*10+num[l++];
                    x++;
                }
                if(sum2-sum1<ans)ans=sum2-sum1;
            }
    }
    return ans;
}

int solve_odd()
{
    if(num[1]==0){
        int t=num[1];
        num[1]=num[2];
        num[2]=t;
    }
    int sum1=num[cnt],sum2=num[1],ans,mid=cnt/2+1,l=2,r=cnt-1;
    while(l<=mid)sum2=sum2*10+num[l++];
    while(r>mid)sum1=sum1*10+num[r--];
    return sum2-sum1;
}

int main()
{
    int n;
    char str[30];
    scanf("%d",&n);
    getchar();
    while(n--){
        gets(str);
        int len=strlen(str);
        cnt=0;
        for(int i=0;i<len;i++)
            if('0'<=str[i]&&str[i]<='9')
                num[++cnt]=str[i]-'0';
        if(cnt%2==0)
            printf("%d\n",solve_even());
        else
            printf("%d\n",solve_odd());
    }
	return 0;
}

