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
        ll a[n];
        ll p=0,q=0,r=0;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%3==0)
            p++;
            else if(a[i]%3==1)
            q++;
            else if(a[i]%3==2)
            r++;
        }    
        if(r>=n/3 && p<=n/3 && q<=n/3)
        {
            cout<<(n/3-q)*2+(n/3-p)*1<<"\n";
        }
        else if(p>=n/3 && r<=n/3 && q<=n/3)
        {
            cout<<(n/3-q)*1+(n/3-r)*2<<"\n";
        }
        else if(q>=n/3 && r<=n/3 && p<=n/3)
        {
            cout<<(n/3-p)*2+(n/3-r)*1<<"\n";
        }
        else if(r>=n/3 && p>=n/3 && q<=n/3)
        {
            cout<<(r-n/3)*2+(p-n/3)*1<<"\n";
        }
        else if(r>=n/3 && q>=n/3 && p<=n/3)
        {
            cout<<(r-n/3)*1+(q-n/3)*2<<"\n";
        }
        else if(p>=n/3 && q>=n/3 && r<=n/3)
        {
            cout<<(p-n/3)*2+(q-n/3)*1<<"\n";
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
