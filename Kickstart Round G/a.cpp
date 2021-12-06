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
ll search(pairv & v, ll e,ll l , ll h)
{
    ll k=INT_MAX;
    while(l<=h)
    {
        ll m=(l+h)/2;
        if(v[m].ff<e)
        {
            l=m+1;
        }
        else
        {
           k=min(k,m);
           h=m-1;
        }
    }
    if(k!=INT_MAX)
    return v[k].ss;
    else
    return -1;
    // ll d=INT_MAX-1;
    // for(ll i=0;i<v.size();i++)
    // {
    //     if(v[i].ff>e)
    //     {
    //         d=min(d,v[i].second-v[i].ff);
    //     }
    // }
    // return {0,d};
//  ll m=(l+r)/2;
//  if(v[m].ff<e)
//  {
//      search(v,e,m+1,r);
//  }
//  else
//  {
//      search(v,)
//  }
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
        ll i,j,k,e,f,n,c=0,x=0;
        map<ll,pairv> m;
        map<ll,pairv> tm;
        cin>>n>>k;
        ll a[n];
        fr(i,0,n)
        cin>>a[i];
        // if(n>500 || k>10000)
        // break;
        ll ans=INT_MAX;
        fr(i,0,n)
        {
            c=0;
            for(j=i;j<n;j++)
            {
                c+=a[j];
                if(c==k)
              {  ans=min(ans,j-i+1);
              continue;
              }
                if(c==0)
                continue;
                if(m[c].size()==0 )
                m[c].push_back({i,j});
                else
                {
                    pair<ll,ll> le=m[c].back();
                    if(le.first!=i)
                    m[c].push_back({i,j});
                }
            }
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            pairv v=it->second;
            pairv tv(v.size());
            ll md=INT_MAX;
            for(i=v.size()-1;i>=0;i--)
        {
            md=min(md,v[i].ss-v[i].ff+ 1ll);
            tv[i]={v[i].ff,md};
        }
        tm[it->ff]=tv;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            pairv v=it->second;
            ll cl=it->ff;
            ll cr=k-cl;
            if(tm[cr].size()==0)
            continue;
            for(i=0;i<v.size();i++)
        {
            c=v[i].ss-v[i].ff+1;
           f=search(tm[cr],v[i].ss+1,0,tm[cr].size()-1);
           if(f!=-1)
           {
            //   cout<<it->ff<<" "<<f<<"\n ";
            ans=min(ans,c+f);
           }
        }
        }
       
        if(ans==INT_MAX)
        ans=-1;
        casepr(ti)<<ans;

        
     nn
        
    }
    
     return 0;
}
