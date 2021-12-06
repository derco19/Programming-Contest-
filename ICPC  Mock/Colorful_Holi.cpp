#include <bits/stdc++.h>
using namespace std;

#define NFS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
#define endl "\n"

#define ll long long int 
#define ull unsigned long long  
#define vll vector<long long>
#define mll map<long long,long long>
#define pll pair<long long,long long>
#define v2d vector<vll>
#define vpll vector<pll>
#define mpll map<pll>
#define all(v) v.begin(),v.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define alla(v) v,v+n
#define acc(a) accumulate(alla(a),(ll)0)
#define PB push_back
#define MP make_pair
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mod 1000000007
#define PI 3.14159265358979323846

/*
bool prime[1000001];
ll fsp[10000001];
void sieve() {memset(prime, true, sizeof(prime));
for (ll i = 2; i * i <= 1000000; i++)if (prime[i])for (ll j = i * i; j <= 1000000; j+= i)prime[j] = false;
prime[0] = prime[1] = false;}
 
void fastsieve() {fsp[1]=1;for(int i=2;i<=1e7;i++) fsp[i]=i;for (int i=4;i<=1e7;i+=2) fsp[i] = 2; 
for (int i=3; i*i<=1e7; i++) {if(fsp[i]==i) {for (int j=i*i; j<=1e7; j+=i)if (fsp[j]==j) fsp[j] = i;}}}
*/

ll mul(ll a,ll b) {
	return ((a % mod) * (b % mod)) % mod;
}
 
ll add(ll a,ll b) {
	return (a % mod + b % mod) % mod;
}
ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll extgcd(ll a,ll b,ll& x,ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool isPrime(ll n){
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}
bool isPowerOfTwo(ll n) { 
   if(n==0) 
   return false; 
   return (ceil(log2(n)) == floor(log2(n))); 
}
//Prime factorization of integer n O(sqrt(n))
vector<ll> factors(ll  n)
{
    vector<ll> f;
    for (ll x = 2; x*x <= n; x++)
    {
        while (n%x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}


ll bin_exp_mod(ll a,ll n)
{
    ll res=1;
    a%=mod;
    if(a==0)
        return 0;
    while(n>0)
    {
        if(n&1)
            res=((res%mod)*(a%mod))%mod;
        n=n>>1;
        a=((a%mod)*(a%mod))%mod;
    }
    res%=mod;
    return res;
}

void solve()
{
    ll n,m,k;
    ll x,y;
    cin>>n>>x>>y>>k;
    ll c[n];
    fr(i,0,n)
        cin>>c[i];
    
    ll dif = y-x+1;
    map<ll,ll>mp,m1;
    fr(i,0,n)
    {
        if(x<=c[i] && y>=c[i]){dif--;}
        else
        m1[c[i]]++;
        mp[c[i]]++;
    }
    ll ans=mp.size();

    ll ans1 = 0;
    for(auto x:m1)
    {
        ans1+=(x.second-1);
    }
    cout<<ans+min(k,min(dif,ans1))<<endl;
}

int main() {
	// your code goes here
	NFS;
	ll t;
	cin>>t;
	while(t--)
	{
        solve();
	}
	return 0;
}