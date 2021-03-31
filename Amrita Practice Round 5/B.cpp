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
        ll n,m,k;
        cin>>n>>m>>k;
        ll p,q,r;
        vector <pair<ll,ll>> v;
        for(ll i=0;i<k;i++)
        {
            cin>>p>>q>>r;
            v.PB(MP(n-q+m-r,p));
        }
        sort(all(v));
        for(ll i=1;i<k;i++)
        {
            v[i].S=max(v[i].S,v[i-1].S);
        }
        
        cin>>q;
        ll t;
        for(ll i=0;i<q;i++)
        {
            cin>>t;
            ll l=0,r=k,mid=(l+r)/2;
            while(l<r)
            {
                mid=(l+r)/2;
                if(v[mid].F<=t)
                {
                    l=mid+1;
                }
                else
                {
                    r=mid;
                }
            }
            cout<<v[l-1].S*(l)<<"\n";
        }

        
    }
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

