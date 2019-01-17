#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int TEN[4]={1,10,100,1000};
const int MAXL=1000;

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

    bignumber operator+(const bignumber &another)
    {
        bignumber c;
        c.d[0]=max(d[0],another.d[0]);
        int x=0;
        for(int i=1;i<=c.d[0];i++){
            x=x+d[i]+another.d[i];
            c.d[i]=x%10000;
            x/=10000;
        }
        while(x!=0){
            c.d[++c.d[0]]=x%10000;
            x/=10000;
        }
        return c;
    }
};

int main()
{
    string s1,s2,s3;
    bignumber x1,x2,x3;
    cin>>s1>>s2>>s3;
    x1=bignumber(s1);
    x2=bignumber(s2);
    x3=bignumber(s3);
    if((x1+x2).tostring()==x3.tostring()||(x2+x3).tostring()==x1.tostring()||(x1+x3).tostring()==x2.tostring()
    ||(x1+x1).tostring()==x2.tostring()||(x2+x2).tostring()==x1.tostring()||(x1+x1).tostring()==x3.tostring()
    ||(x3+x3).tostring()==x1.tostring()||(x2+x2).tostring()==x3.tostring()||(x3+x3).tostring()==x2.tostring())
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
