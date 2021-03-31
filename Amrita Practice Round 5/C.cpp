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
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
    {
        
    }       
}
vector <ll> adj[100005];
ll mxvalue[100005];
ll ma=0;
ll visited[100005];
ll mx[100005];
ll dfs(ll x)
{
    visited[x]=1;
    for(auto u:adj[x])
    {
        if(visited[u]==-1)
        {
            mx[x]=max(mx[x],dfs(u));
        }
    }
    return mx[x]=max(mx[x],mxvalue[x]);
}
ll ans=0;
void dfs1(ll x,ll p,ll ma1)
{
    visited[x]=1;
    vector <ll> premx;
    vector <ll> sufmx;
    ll ma2=0;
    premx.PB(0);
    for(auto u:adj[x])
    {
        if(visited[u]==-1)
        {
           ma2=max(ma2,mx[u]);
           premx.PB(ma2);
        }   
    }
    ma2=0;
    sufmx.PB(0);
    for(ll i=adj[x].size()-1;i>=0;i--)
    {
        if(visited[adj[x][i]]==-1)
        {
            ma2=max(ma2,mx[adj[x][i]]);
            sufmx.PB(ma2);
        }
    }
    
    reverse(all(sufmx));
    ma1=max(ma1,mxvalue[x]);
    ll c=0;
    for(ll i=0;i<adj[x].size();i++)
    {
        if(visited[adj[x][i]]==-1)
        {
            ll mx3=max(ma1,max(premx[c],sufmx[c+1]));
            ans=ans+abs(mx3-mx[adj[x][i]]);
            c++;
        }
    }
    c=0;
    for(ll i=0;i<adj[x].size();i++)
    {
        if(visited[adj[x][i]]==-1)
        {
            ll mx3=max(ma1,max(premx[c],sufmx[c+1]));
            dfs1(adj[x][i],x,mx3);
            c++;
        }
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
        ll n;
        cin>>n;
        ll u,v;
        ans=0;
        ma=0;
        fill(mx,0);
        fill(mxvalue,0);
        for(ll i=0;i<100005;i++)
        adj[i].clear();

        for(ll i=1;i<n;i++)
        {
            cin>>u>>v;
            adj[u].PB(v);
            adj[v].PB(u);
        }
        fill(visited,-1);
        for(ll i=1;i<=n;i++)
        {
            cin>>mxvalue[i];
        }
        dfs(1);
        fill(visited,-1);
        visited[0]=1;
        dfs1(1,0,0);
        ll ans1=((ans%mo)*(mi(n-1,mo))%mo)%mo;
        cout<<ans1<<"\n";
    }
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

