//clear adj and visited vector declared globally after each test case
//check for long long overflow
//while adding and subs check if mod becomes -ve
//while using an integer directly in a builtin function add ll
//Mod wale question mein last mein if dalo ie. Ans<0 then ans+=mod;
//Dont keep array name as size or any other key word
//Incase of close mle change language to c++17 or c++14 
 
#include <bits/stdc++.h>  
#define int long long
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);cout.precision(dbl::max_digits10);
#define pb push_back
#define mod 1000000007ll //998244353ll
#define lld long double
#define mii map<int, int>
#define mci map<char, int>
#define msi map<string, int>
#define pii pair<int, int>
#define ff first
#define ss second 
#define all(x) (x).begin(), (x).end()
#define rep(i,x,y) for(int i=x; i<y; i++)    
#define fill(a,b) memset(a, b, sizeof(a))
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define print2d(dp,n,m) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++)cout<<dp[i][j]<<" ";cout<<"\n";}
typedef std::numeric_limits< double > dbl;
using namespace std;

 
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int ar[n];
        rep(i,0,n)
        cin>>ar[i];
        int l=ar[0], u=ar[0]+k, f=0;
        for(int i=1;i<n;i++)
        {
            int nl=max(l-k+1, ar[i]);
            int nu;
            if(i<n-1)
            nu=min(ar[i]+k-1+k, u+k-1);
            else
            nu=min(ar[i]+k, u+k-1);
            if(nu-nl<k)
            {
                f=1;
                break;
            }
            u=nu;
            l=nl;
        }
        if(f)
        cout<<"NO\n";
        else
        cout<<"YES\n";
    }
}