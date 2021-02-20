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
       ll ma[n+1][30],mi[n+1][30];
       fill(ma,0);
       fill(mi,0);
       string s;
       cin>>s;
       ll a[n+1]={0};
       for(ll i=1;i<=n;i++)
       {
           if(s[i-1]=='+')
           {
               a[i]=a[i-1]+1;
               ma[i][0]=1;
               mi[i][0]=1;
           }
           else
           {
               a[i]=a[i-1]-1;
               ma[i][0]=-1;
               mi[i][0]=-1;
           }
       }
       ll c=2,d=1;
       while(c<=n)
       {
           for(ll i=1;i<=n;i++)
           {
               if(i+c-1<=n)
               {
                   ma[i][d]=max(ma[i][d-1],a[i+c/2-1]-a[i-1]+ma[i+c/2][d-1]);
                   mi[i][d]=min(mi[i][d-1],a[i+c/2-1]-a[i-1]+mi[i+c/2][d-1]);
               }
               else
               {
                   ma[i][d]=max(ma[i][d-1],a[n]-a[i-1]);
                   mi[i][d]=min(mi[i][d-1],a[n]-a[i-1]);
               }
           }
           c=c*2;
           d++;
       }
       ll l,r;
       for(ll i=0;i<m;i++)
       {
           cin>>l>>r;
           ll p=1,ma1=a[0],mi1=a[0];
           while(p<l)
           {
              c=1;
              d=0;
              while(p+c-1<l)
              {
                  ma1=max(ma1,a[p-1]+ma[p][d]);
                  mi1=min(mi1,a[p-1]+mi[p][d]);
                  d++;
                  c=c*2;
              }
              c/=2;
              p=p+c;
           }
           p=r+1;
           while(p<=n)
           {
               c=1;
              d=0;
              while(p+c-1<=n)
              {
                  ma1=max(ma1,a[l-1]+a[p-1]-a[r]+ma[p][d]);
                  mi1=min(mi1,a[l-1]+a[p-1]-a[r]+mi[p][d]);
                  d++;
                  c=c*2;
              }
              c/=2;
              p=p+c;
           }
           cout<<ma1-mi1+1<<"\n";
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