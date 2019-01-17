#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=105,MAXL=50;
const int TEN[4]={1,10,100,1000};

struct bignumber{
    int d[MAXL];

    bignumber()
    {
        *this=bignumber(string("0"));
    }

    bignumber(string s)
    {
        int len=s.size();
        d[0]=(len-1)/4+1;
        for(int i=1;i<MAXL;i++)d[i]=0;
        for(int i=len-1;i>=0;i--){
            int j=(len-i-1)/4+1,k=(len-i-1)%4;
            d[j]+=TEN[k]*(s[i]-'0');
        }
        while(d[0]>1&&d[d[0]]==0)d[0]--;
    }

    string tostring()
    {
        string s("");
        int i,temp;
        for(i=3;i>=1;i--)if(d[d[0]]>=TEN[i])break;
        temp=d[d[0]];
        for(int j=i;j>=0;j--){
            s=s+(char)(temp/TEN[j]+'0');
            temp%=TEN[j];
        }
        for(i=d[0]-1;i>0;i--){
            temp=d[i];
            for(int j=3;j>=0;j--){
                s=s+(char)(temp/TEN[j]+'0');
                temp%=TEN[j];
            }
        }
        return s;
    }
};

string n,k;
bignumber midl[15],d;

bool smaller(const bignumber &a,const bignumber &b,int delta)
{
    if(a.d[0]+delta!=b.d[0])return a.d[0]+delta<b.d[0];
    for(int i=a.d[0];i>0;i--)
        if(a.d[i]!=b.d[i+delta])return a.d[i]<b.d[i+delta];
    return true;
}

void mi(bignumber &a,const bignumber &b,int delta)
{
    int x=0;
    for(int i=1;i<=a.d[0]-delta;i++){
        x=10000+a.d[i+delta]-b.d[i]+x;
        a.d[i+delta]=x%10000;
        x=x/10000-1;
    }
    while(a.d[0]>1&&a.d[a.d[0]]==0)a.d[0]--;
}

bignumber operator*(const bignumber &a,const int &k)
{
    bignumber c;
    c.d[0]=a.d[0];
    int x=0;
    for(int i=1;i<=a.d[0];i++){
        x=a.d[i]*k+x;
        c.d[i]=x%10000;
        x/=10000;
    }
    while(x>0){
        c.d[++c.d[0]]=x%10000;
        x/=10000;
    }
    while(c.d[0]>1&&c.d[c.d[0]]==0)c.d[0]--;
    return c;
}

bignumber operator/(const bignumber &a,const bignumber &b)
{
    bignumber c;
    d=a;
    midl[0]=b;
    for(int i=1;i<=13;i++)
        midl[i]=midl[i-1]*2;
    for(int i=a.d[0]-b.d[0];i>=0;i--){
        int temp=8192;
        for(int j=13;j>=0;j--){
            if(smaller(midl[j],d,i)){
                mi(d,midl[j],i);
                c.d[i+1]+=temp;
            }
            temp/=2;
        }
    }
    c.d[0]=max(1,a.d[0]-b.d[0]+1);
    while(c.d[0]>1&&(c.d[c.d[0]==0]))c.d[0]--;
    return c;
}

int main()
{
    cin>>n>>k;
    bignumber N=bignumber(string(n)),K=bignumber(string(k)),res;
    res=(N/K);
    if(res.d[1]%2==0)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}
