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
        ll n;
        cin>>n;
        ll a[n][n];
        string s;
        vector <pair<ll,ll>> v[10];
        ll m[10]={0},a1[10],b1[10],a2[10],b2[10];
        for(ll i=0;i<10;i++)
        {
            a1[i]=1000000007;
            a2[i]=0;
            b1[i]=1000000007;
            b2[i]=0;
        }
        for(ll i=0;i<n;i++)
        {
            cin>>s;
            ll p=0,j=0;
            for(ll j=0;j<n;j++)
            {
                a[i][j]=(ll)(s[j]-'0');
                v[a[i][j]].PB(MP(i+1,j+1));
                if(a1[a[i][j]]>i+1)
                {
                    a1[a[i][j]]=i+1;
                }
                if(a2[a[i][j]]<i+1)
                a2[a[i][j]]=i+1;
                if(b1[a[i][j]]>j+1)
                {
                    b1[a[i][j]]=j+1;
                }
                if(b2[a[i][j]]<j+1)
                b2[a[i][j]]=j+1;
            }
        }
        for(ll i=0;i<=9;i++)
        {
            sort(all(v[i]));
            ll ans=0;
            ll j=v[i].size()-1;
            {
                for(ll k=0;k<v[i].size();k++)
                {
                    ans=max(ans,max(abs(v[i][k].S-b1[i]),abs(v[i][k].S-b2[i]))*(max(abs(v[i][k].F-1),abs(v[i][k].F-n))));
                    ans=max(ans,max(abs(v[i][k].F-a1[i]),abs(v[i][k].F-a2[i]))*(max(abs(v[i][k].S-1),abs(v[i][k].S-n))));
                }
            }
            cout<<ans<<" ";
        }
        cout<<"\n";

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

