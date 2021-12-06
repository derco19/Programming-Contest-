#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
#define pb push_back
#define mp make_pair
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
ll pow1(ll n,ll p)
{
if(p==0) return 1; 
ll x=pow1(n, p/2);
x=(x*x)%mo;
if(p%2==0)
return x;
else
return (x*n)%mo;
}
bool sortbysec(const pair<ll,ll> &a, 
const pair<ll,ll> &b) 
{ 
return (a.second < b.second); 
} 
bool compare(const pair<ll, ll>&p1, const pair<ll,ll>&p2)
{
if(p1.ff < p2.ff) return true;
if(p1.ff == p2.ff) return p1.ff < p2.ss;
return false;
}
ll const maxn=200007;
ll nxt[maxn];
void seive()
{
      for (ll i = 2; i < maxn; ++i) {
        if (nxt[i] == 0) {
            nxt[i] = i;
            for (ll j = i * i; j < maxn; j += i) {
                if(j>=maxn)
                {
                    break;
                }
                if (nxt[j] == 0) nxt[j] = i;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
      

    freopen("consistency_chapter_1_validation_input.txt", "r", stdin);   // name of input file
	freopen("output.txt", "w", stdout); // name of output file

    int test=1;
    cin>>test;
    for(int ti=0;ti<test;ti++)
    {
        
        ll i,j,k,e,f,n,c=0,x=0;
        cin>>n;
        string s;
        cin>>s;
        ll l=1,r=1;
        ll mod=1e9+7;
        vector<ll> vx(n,0);
        vector<ll>vo(n,0);
        ll cx=-1,co=-1;
        fr(i,0,n)
        {
if(s[i]=='X')
cx=i;
if(s[i]=='O')
co=i;
vx[i]=cx;
vo[i]=co;
        }
        fr(i,0,n)
        {
            if( s[i]=='X')
            {
                if(l==0)
                {
                    c=(c+((vo[i]+1)*(n-i))%mod)%mod;
                }
                l++;
                r=0;
              }
             if( s[i]=='O')
            {
                if(r==0)
               {
                    c=(c+((vx[i]+1)*(n-i))%mod)%mod;
               }

                r++;
                l=0;
              }
        }
        casepr(ti)<<max(0ll,c);
        nn
    }
    
     return 0;
}