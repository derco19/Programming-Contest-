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

vector <ll> special;
vector <ll> adj[200005];
ll n,k,ar;
ll visited[100005];
ll dp[2001][2001];

void dfs(ll x,ll c,ll i)
{
    dp[i][x]=c;
    visited[x]=1;
    for(auto u:adj[x])
    {
        if(visited[u]==0)
        dfs(u,c+1,i);
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
        cin>>n>>k>>ar;
        ll p,q;
        for(ll i=1;i<2005;i++)
        adj[i].clear();
        fill(dp,0);
        special.clear();
        for(ll i=0;i<k;i++)
        {
            cin>>p;
            special.PB(p);
        }
        if(n<=2000)
        {   
        for(ll i=1;i<n;i++)
        {
            cin>>p>>q;
            adj[p].PB(q);
            adj[q].PB(p);
        }
        for(ll i=1;i<=n;i++)
        {
            fill(visited,0);
            dfs(i,0,i);
        }
        vector <ll> ac;
        for(ll i=1;i<=n;i++)
        {
            ll ma=-1*mo;
            q=0;
            for(auto u:special)
            {
                ll s;
                s=dp[ar][u]-dp[i][u];
                if(s>ma)
                {
                    ma=s;
                    q=u;
                }
            }
            cout<<ma<<" ";
            ac.PB(q);
        }
        cout<<"\n";
        for(auto u:ac)
        cout<<u<<" ";
        cout<<"\n";
        }
        else
        {
            for(ll i=1;i<n;i++)
            cin>>p>>q;
            vector <ll> v1;
            for(ll i=1;i<=n;i++)
            {
                ll q1=special[0];
                ll q2=special.back();
                if(i<=ar)
                {
                    cout<<abs(ar-q1)-abs((i-q1))<<" ";
                    v1.PB(q1);
                }
                else
                {
                    cout<<abs(ar-q2)-abs(i-q2)<<" ";
                    v1.PB(q2);
                }
            }
            cout<<"\n";
            for(auto u:v1)
            cout<<u<<" ";
            cout<<"\n";
        }
        
    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

