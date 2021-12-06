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
vector <ll> pr;
void Sieve(int n) 
{ 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == 0) 
        { 
            pr.push_back(p);
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
ll parent[1000000];
ll findParent(ll x){
    if(parent[x]==x || parent[x]==-1)
    return parent[x]=x;
    return parent[x]=findParent(parent[x]);
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
    
    Sieve(1000006);
    // for(auto u:pr)
    // cout<<u<<"\n";

    ll t=1,t1=1;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<=1e6;i++)
        parent[i]=-1;
        ll n;
        cin>>n;
        ll a[n];
        ll co=0;
        set <ll> s2;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            ll x=-1;
            if(a[i]==1){
                co++;
                continue;
            }
            ll x1=0;
            for(auto u:pr){
                if(a[i]%u==0){
                    while(a[i]%u==0)
                    a[i]/=u;
                    x1=1;
                    if(x==-1){
                        ll p1=findParent(u);
                        if(p1>u)
                        parent[u]=u;
                        x=u;
                    }
                    else{
                        ll p1=findParent(x);
                        ll p2=findParent(u);
                        if(p1<p2){
                            parent[p2]=p1;
                        }
                        else{
                            parent[p1]=p2;
                        }
                    }
                }
            }

            if(x1==0){
                ll p1=findParent(a[i]);
                if(p1==a[i])
                s2.insert(a[i]);
            }
            else{
                if(a[i]>1000){
                    ll p1=findParent(x);
                    parent[a[i]]=p1;
                }
            }
        }
        vector <ll> v2;
        
        for(int i=0;i<=1e6;i++){
            if(parent[i]==i)
            v2.push_back(i);
        }
        // cout<<v2.size()<<"\n";
        // for(auto u:v2){
        //     cout<<u<<" ";
        // }
        // cout<<"\n";
        sort(all(v2));
		ll ans=0;
		if(v2.size()==0){
            if(co==1)
            ans=0;
            else
			ans=co*2;
        }    
		else
            ans=min(2*(v2.size()+co),v2[0]*(v2.size()-1+co));
        cout<<ans<<"\n";

    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

