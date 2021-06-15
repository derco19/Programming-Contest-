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


vector <ll> pr;

void seive(ll n) {
    ll nxt[n+1]={0};
    for (ll i = 2; i*i <= n; i++) {
        if (nxt[i] == 0) {
            for (ll j = i * i; j <=n; j += i)
            nxt[j] = 1;
        }
    }
    for(ll i=2;i<=n;i++){
        if(nxt[i]==0){
            pr.PB(i);
        }
    } 
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    pr.clear();
    seive(40006);


    int t;
    cin>>t;
    for(int t1=1;t1<=t;t1++)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        
        ll c=0,d=0,mi=2,n1=n,m1=m;
        if(max(n,m)%min(n,m)==0)
        mi=1;
        for(auto u : pr)
        {
            if(n==1)
            break;
            while(n%u==0)
            {
                n/=u;
                c++;
            }   
        }
        if(n!=1)
        c++;
        
        for(auto u : pr)
        {
            if(m==1)
            break;
            while(m%u==0)
            {
                m/=u;
                d++;
            }   
        }
        if(m!=1)
        d++;
        if(c+d>=k && mi<=k)
        cout<<"YES\n";
        else
        cout<<"NO\n";   
    }
    return 0;
}