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
    cin>>t;
    while(t--)
    {
        ll x,y,k;
        cin>>x>>y>>k;
        ll ma[x+2][y+2],mi[x+2][y+2];
        fill(ma,0);
        fill(mi,0);
        ma[1][2]=1;
        ma[2][1]=1;
        mi[1][2]=1;
        mi[2][1]=1;
        for(ll i=2;i<=x;i++)
        {
            ma[i][1]=i-1;
        }
        for(ll i=2;i<=y;i++)
        {
            ma[1][i]=i-1;
        }
        for(ll i=2;i<=x;i++)
        {
            mi[i][1]=i-1;
        }
        for(ll i=2;i<=y;i++)
        {
            mi[1][i]=i-1;
        }
        for(ll i=2;i<=x;i++)
        {
            for(ll j=2;j<=y;j++)
            {
                if(ma[i][j]==0)
                ma[i][j]=max(ma[i-1][j]+j,ma[i][j-1]+i);
            }
        }
        for(ll i=2;i<=x;i++)
        {
            for(ll j=2;j<=y;j++)
            {
                if(mi[i][j]==0)
                mi[i][j]=min(mi[i-1][j]+j,mi[i][j-1]+i);
            }
        }
        if(ma[x][y]>=k && mi[x][y]<=k)
        cout<<"YES\n";
        else
        cout<<"NO\n";
        
    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

