                                     // Believe in yourself
#include<bits/stdc++.h>
#include<ctime>
 
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
    // clock_t time_req;
    // time_req = clock();
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll a[n+1],b[n+1];
        queue <ll> b1[n+1];
        queue <ll> b2[n+1];
        for(ll i=1;i<=n;i++)
        cin>>a[i];
        ll x=0;
        for(ll i=1;i<=n;i++)
        {
            cin>>b[i];
            if(a[i]!=b[i])
            {
                b1[b[i]].push(i);
                x++;
            }
            else 
            b2[b[i]].push(i);
        }
        ll c[m+1];
        for(ll i=1;i<=m;i++)
        {
            cin>>c[i];
        }
        if(m<x)
        cout<<"NO\n";
        else 
        {
            ll y=0;
            ll c1[m+1]={0};
            for(ll i=m;i>0;i--)
            {
                if(b1[c[i]].empty()==0)
                {
                    c1[i]=b1[c[i]].front();
                    b1[c[i]].pop();
                }
                else if(b2[c[i]].empty()==0 || i<m)
                {
                    if(i<m)
                    c1[i]=c1[m];
                    else
                    {
                        c1[i]=b2[c[i]].front();
                        b2[c[i]].pop();
                    }
                }
                else 
                y=1; 
            }
            for(ll i=1;i<n+1;i++)
            {
                if(b1[i].empty()==0)
                y=1;
            }
            if(y==1)
            cout<<"NO\n";
            else 
            {
            cout<<"YES\n";
            for(ll i=1;i<=m;i++)
            cout<<c1[i]<<" ";
            cout<<"\n";
            }
        }
    }
    // time_req = clock()-time_req;
    // cout<<"Time taken: "<<(float)time_req/CLOCKS_PER_SEC<<"s"<<endl;
}
 
/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/