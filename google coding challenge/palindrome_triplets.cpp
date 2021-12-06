#include<bits/stdc++.h>
using namespace std;
int dp[1000];
bool isPalindrome[1001][1001];
int findpal(int strt,string &s)
{
    if(strt>s.size()-3)
    {
      return 1;
    }
    if(dp[strt]!=-1)
    return dp[strt];
    dp[strt]==0;
    for(int i=strt;i<=s.size()-3;i++)
    {
        if(isPalindrome[strt][i])
        {
            dp[strt]=dp[strt] + findpal(i+1,s);
        }
    }
    return dp[strt];
}
void checkPalindrome(string &s)
{
    for(int i=0;i<s.size();i++)
    {
        isPalindrome[i][i]=true;
    }
    if(s.size()>1)
    {
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                isPalindrome[i][i+1]=true;
            }
            else{
                isPalindrome[i][i+1]=false;

            }
        }
    }
    if(s.size()>2)
    {
        for(int k=2;k<s.size();k++)
        {
            for(int i=0;i<s.size()-k;i++)
            {
                int j=i+k;
                if(s[i]==s[j] && isPalindrome[i+1][j-1])
                {
                    isPalindrome[i][j]=true;
                }
                else
                {
                    isPalindrome[i][j]=false;
                }
            }
        }
    }
}
int main()
{
    string s;
    int n;
    cin>>n;
    for(int i=0;i<1001;i++)
    dp[i]=-1;
    cin>>s;
    if(n<3)
    cout<<0;
    checkPalindrome(s);
   cout<< findpal(0,s);
    
     return 0;
}