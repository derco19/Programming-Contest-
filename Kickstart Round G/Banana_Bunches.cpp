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

void check(map <ll,vector<pair<ll,ll>>> &mat){
    ll a=0,b=0;
    for(auto u:mat){
        for(auto v:u.S){
            a=a+v.F;
            b=b+v.S;
        }
    }
}


pair<ll,ll> frame(vector <pair<ll,ll>> & v, ll e,ll l , ll r)
{
    ll d=INT_MAX-1;
    for(ll i=0;i<v.size();i++)
    {
        if(v[i].F>e)
        {
            d=min(d,v[i].second-v[i].F);
        }
    }
    return {0,d};

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
        cout<<"Case #"<<t1<<": ";
        ll n,k;
        map <ll,vector<pair<ll,ll>>> matrix;
        cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        ll ans=INT_MAX;
        for(ll i=0;i<n;i++)
        {
            ll c=0;
            for(ll j=i;j<n;j++)
            {
                c+=a[j];
                if(c==k)
                ans=min(ans,j-i+1);
                if(matrix[c].size()==0)
                matrix[c].push_back({i,j});
                else
                {
                    pair<ll,ll> le=matrix[c].back();
                    if(le.first!=i)
                    matrix[c].push_back({i,j});
                }
            }
        }
        check(matrix);

        for(auto it=matrix.begin();it!=matrix.end();it++)
        {
            vector <pair<ll,ll>> v=it->S;
            ll cl=it->F;
            
            ll cr=k-cl;
            if(matrix[cr].size()==0){
                continue;
            }
            for(ll i=0;i<v.size();i++)
            {
                ll c=v[i].S-v[i].F+1;
                pair<ll,ll> fig = frame(matrix[cr],v[i].S,0,matrix[cr].size());
                ans=min(ans,c+fig.S-fig.F+1);
            }
        }
        
        if(ans==INT_MAX){
            check(matrix);
            ans=-1;
        }    
        cout<<ans<<"\n";
        check(matrix);
        t1++;
        
    }

    
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

