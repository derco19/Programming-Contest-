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

vector <ll> prime(1000006,0);
void Sieve(int n) 
{ 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == 0) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = 1; 
        } 
    } 
}

ll pow1(ll n, ll p)
{
    if (p == 0)
        return 1;
    ll x = pow1(n, p / 2);
    x = (x * x) % mo;
    if (p % 2 == 0)
        return x;
    else
        return (x * n) % mo;
}

vector <vector<ll>> v;
vector <ll> power;
vector <ll> av;

ll dfs(ll x,ll p){
    ll g=power[x];
    for(auto u:v[x]){
        if(u!=p){
            g=__gcd(g,dfs(u,x));
        }
    }
    return av[x]=g;
}

ll ans=0;
void dfs1(ll x,ll p,ll pr){
    vector <ll> fra;
    ll s=pr;
    for(auto u:v[x]){
        if(u!=p){
            fra.PB(av[u]);
            s=s+av[u];
        }
    }
    ans=max(ans,s);
    vector<ll> pre(fra.size()+1,0);
    vector<ll> post(fra.size()+1,0);
    for(ll i=1;i<pre.size();i++){
        pre[i]=__gcd(fra[i-1],pre[i-1]);
    }
    for(ll i=post.size()-2;i>=0;i--){
        post[i]=__gcd(post[i+1],fra[i]);
    }
    ll c=0;
    for(auto u:v[x]){
        if(u!=p){
            ll temp=__gcd(post[c+1],__gcd(pre[c],__gcd(pr,power[x])));
            dfs1(u,x,temp);
            c++;
        }
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  


    // freopen("input.txt", "r", stdin);   // name of input file
	// freopen("output.txt", "w", stdout); // name of output file
    
    // fstream file, output;
	// file.open(R"(input.txt)", ios::in);        // add the address of local input file
	// output.open(R"(output.txt)", ios::out);  // add the address of local output file
    
    ll t,t1=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        v.clear();
        v.resize(n+1);
        power.clear();
        power.resize(n+1);
        av.clear();
        av.resize(n+1,0);
        ll p,q;
        for(ll i=1;i<n;i++){
            cin>>p>>q;
            v[p].PB(q);
            v[q].PB(p);
        }
        for(ll i=1;i<=n;i++){
            cin>>power[i];
        }
        
        ans=0;
        p=dfs(1,0);
        
        dfs1(1,0,0);
        cout<<ans<<"\n";

    }

    
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/