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


ll getBoundaryCount(ll x1,ll x2,ll y1,ll y2)
{

    // Check if line parallel to axes
    if (x1==x2)
        return abs(y1 - y2) - 1;
    if (y1 == y2)
        return abs(x1 - x2) - 1;
    return __gcd(abs(x1-x2), abs(y1-y2)) - 1;
}

ll polygonArea(ll X[], ll Y[], ll n)
{
    // Initialize area
    ll area = 0;
 
    // Calculate value of shoelace formula
    ll j = n - 1;
    for (ll i = 0; i < n; i++)
    {
        area =area + X[i]*Y[j]-Y[i]*X[j];
        j = i;  // j is previous vertex to i
    }
 
    // Return absolute value
    return abs(area);
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

        ll x[n+1],y[n+1];
        for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
        x[n]=x[0];
        y[n]=y[0];
        ll ans=(ll)polygonArea(x,y,n);
        for(int i=1;i<=n;i++){
            ans=ans-getBoundaryCount(x[i],x[i-1],y[i],y[i-1])-1;
            // cout<<ans<<"\n";
        }
        ans+=2;
        ans/=2;
        cout<<ans<<"\n";
        
    }


}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

