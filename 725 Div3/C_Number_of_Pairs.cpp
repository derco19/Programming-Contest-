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
ll findPairs(ll arr[],ll n,ll x)
{
    ll l = 0, r = n-1;
    ll ans = 0;
 
    while (l < r)
    {
    
        if (arr[l] + arr[r] < x)
        {
            ans += (r - l);
            l++;
        }
 
        
        else
            r--;
    }
 
    return ans;
}
int main()
{
int t;
   cin>>t;
    while(t--)
    {
    ll l,h,n;
        cin>>n>>l>>h;
ll a[n];
     
       fr(i,0,n)
        cin>>a[i];
        sort(a,a+n);
        cout<<findPairs(a,n,h+1)-findPairs(a,n,l);
        
        

        
     cout<<"\n";
        
    }
    
     return 0;
}