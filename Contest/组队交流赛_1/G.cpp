#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

string s;
int cnt1,cnt2;

int main()
{
    cin>>s;
    cnt1=0;cnt2=0;
    for(int i=0;i<s.length();i++)
        if(s[i]=='1')
            cnt1++;
        else
            cnt2++;
    cout<<min(cnt1,cnt2);
    return 0;
}
