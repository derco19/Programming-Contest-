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

ll query(ll l1,ll r1)
{
    ll p;
    cout<<"? "<<l1<<" "<<r1<<endl;
    cout<<flush;
    cin>>p;
    return p;
}


int main()
{
    // clock_t time_req;
    // time_req = clock();
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    ll t=1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll l=1,r=n,mid;
        ll m2=query(1,n);
        while(l<r)
        {
            if(r-l==1)
            {
                if(m2==r)
                {
                    m2=l;
                    break;
                }
                else
                {
                    m2=r;
                    break;
                }
            }
            ll m3,m4;
            mid=(l+r)/2;
            m3=query(l,mid);
            if(mid+1!=r)
            m4=query(mid+1,r);
            else
            {
                m4=r;
            }
            if(mid>=m2 && l<=m2 && m3==m2)
            {
                r=mid;
                m2=m3;
            }
            else if(mid>=m2 && l<=m2)
            {
                if(mid+1==r)
                {
                    m2=m4;
                    break;
                }
                else
                {
                m2=m4;
                l=mid+1;
                }
            }
            else if(mid<m2 && r>=m2 && m2==m4)
            {
                if(mid+1==r)
                {
                    r=mid;
                    m2=m3;
                }
                else
                {
                l=mid+1;
                }
            }
            else if(mid<m2 && r>=m2)
            {
                r=mid;
                m2=m3;
            }
            
        }
        cout<<"! "<<m2<<endl;
        cout<<flush;
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

