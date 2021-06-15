#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;

#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
#define PB push_back
#define MP make_pair
#define show(a) for(auto el:a)cout<<el<<" "
#define ff first
#define ss second
#define pairv vector<pair<ll,ll>>
#define vec vector <ll> 
#define all(a) a.begin(),a.end()
#define fam(v,i) for(auto i=v.begin();i!=v.end();i++)
#define fai(v,i) for(auto i : v)
#define mo 1000000007
#define nn cout<<"\n";
#define Y cout<<"YES\n";
#define N cout<<"NO\n";
#define cout_dec cout << fixed << setprecision(9) 
#define casepr(ti)  cout<<"Case #"<<ti+1<<": "
#define fill(a,b) memset(a, b, sizeof(a))
#define pr pair<ll,ll>

ll pow1(ll n,ll p) {
if(p==0) return 1; 
ll x=pow1(n, p/2);
x=(x*x)%mo;
if(p%2==0)
return x;
else
return (x*n)%mo;
}


bool sortbysec(const pair<ll,ll> &a, 
const pair<ll,ll> &b) { 
return (a.second < b.second); 
} 

bool compare(const pair<ll, ll>&p1, const pair<ll,ll>&p2) {
if(p1.ff < p2.ff) return true;
if(p1.ff == p2.ff) return p1.ff < p2.ss;
return false;
}


ll const maxn=2000007;
ll nxt[maxn];

void seive(vector <ll> &prime,ll n) {
    fill(nxt,0);
    for (ll i = 2; i*i <= n; ++i) {
        if (nxt[i] == 0) {
            for (ll j = i * i; j <=n; j += i)
            nxt[j] = i;
        }
    }
    for(ll i=2;i<=n;i++){
        if(nxt[i]==0){
            prime.PB(i);
        }
    } 
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int test=1;
    cin>>test;
    for(int ti=0;ti<test;ti++)
    {
        ll n;
        cin>>n;
        ll a[n],mi=1e9,ma=-1*1e9,pi=-1,pa=-1;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<mi)
            {
                mi=a[i];
                pi=i;
            }
            if(a[i]>ma)
            {
                ma=a[i];
                pa=i;
            }    
        }
        ll ans=1e9;
         ans=min(max(pi,pa)+1,ans);
        ans=min(ans,max(n-pi,n-pa));
        ans=min(ans,min(pi,pa)+1+n-max(pi,pa));
        cout<<ans<<"\n";


    }
    return 0;
}