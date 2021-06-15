#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Pair vector<pair<ll,ll>>
#define vec vector <ll> 
#define all(a) a.begin(),a.end()
#define mo 1000000007
#define decimal(i,n) fixed << setprecision(i) << n
#define show(a) for(auto xyz:a)cout<<xyz<<" ";cout<<endl;
#define show_nl(a) for(auto xyz:a)cout<<xyz<<endl;
#define MAX (ll)(pow(2,63)-1)
#define fill(a,b) memset(a, b, sizeof(a))
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

//modular inverse
void eea(ll a,ll b,ll &x,ll &y)
{
    if (a == 1)
    {
        x = 1; y = 0;
        return;
    }
    ll x1, y1;
    eea(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
}
ll mi(ll a,ll m)
{
    ll x,y;
    eea(a,m,x,y);
    x= (x%m+m)%m;
    return x;
}
//complete

void Sieve(int n) 
{ 
    int prime[n+1];
    fill(prime,-1);
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == -1) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = 0; 
        } 
    } 
    for (int p=2; p<=n; p++) 
    {
        
    }       
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  

    // freopen("ladder.in", "r", stdin);   // name of input file
	// freopen("ladder.out", "w", stdout); // name of output file

    // ifstream fin("art.in");
    // ofstream fout("art.out");
    
    // fstream file, output;
	// file.open(R"()", ios::in);        // add the address of local input file
	// output.open(R"()", ios::out);  // add the address of local output file
      
    ll t=1,t1=1;
    // cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       ll a[2*n+2]={0},b[2*n+2]={0};
       for(ll i=1;i<=n;i++)
       cin>>a[i];
       for(ll i=1;i<=n;i++)
       cin>>b[i];
       ll pc[n+2]={0},poc[n+2]={0};

       for(ll i=1;i<=n;i++)
       {
           pc[i]=a[i]*b[i]+pc[i-1];
       }
       for(ll i=n;i>=1;i--)
       {
           poc[i]=a[i]*b[i]+poc[i+1];
       }
       ll dp[n+1][n+6];
       fill(dp,0);
       for(ll i=1;i<2*n;i++)
       {
           ll c=1;
           for(ll j=i;j>=1;j--)
           {
               if(j<=n)
               {
                    if(i<=n)
                    dp[i][j]=a[c]*b[j]+dp[i][j+1];
                    else
                    {
                        if(c<=n)
                        dp[i-n][j+4]=a[c]*b[j]+dp[i-n][j+5];
                    }    
               }    
               c++;
           }
       }
       for(ll i=1;i<=n;i++)
       {
           for(ll j=1;j<n+6;j++)
           cout<<dp[i][j]<<" ";
           cout<<"\n";
       }

       ll ma=pc[n];
       for(ll i=1;i<=n;i++)
       {
           for(ll j=i;j<=n;j++)
           {
               ll s;
               if(j+i-1<=n)
               s=pc[i-1]+poc[j+1]+dp[j+(i-1)][i]-dp[j+(i-1)][j+1];
               else
               s=pc[i-1]+poc[j+1]+dp[j+(i-1)-n][i+4]-dp[j+(i-1)-n][j+1+4];
               ma=max(ma,s);
           }
       }
       cout<<ma<<"\n";
        
    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

