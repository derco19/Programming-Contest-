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

ll n,m;
ll p = 1e9 + 7;
 
const int maxn = 1e5 + 10;
ll f[maxn];

ll extend_gcd(ll a,ll b,ll &x,ll &y)
{
    if (a == 0 && b == 0) return -1; // no common divisor
    if(b==0){x=1;y=0;return a;}
    ll d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
 
ll mod_reverse(ll a,ll n)
{
   ll x,y;
   ll d=extend_gcd(a,n,x,y);
   if(d==1) return (x%n+n)%n;
   else return -1;
}
 
 
ll C(ll n, ll m)
{
   ll A = f[n];
   ll B = f[n - m] * f[m] % p;
   ll C = mod_reverse(B, p);
   return A * C % p;
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
    

    ll t;
    f[0] = 1;
    for(long long i = 1; i < maxn; i ++) {
      f[i] = f[i - 1] * i % mo;
    }
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n == 0) {
        cout<<"0\n";
        continue;
        }
        cout<<(C(n-1,m)*2)%mo<<"\n";
    }
    return 0;
 
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

