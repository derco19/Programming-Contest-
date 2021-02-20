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
        ll a[26];
        for(ll i=0;i<26;i++)
        cin>>a[i];
        ll c=2,y=0,x=0,x1=0,z=0;
        ll mi=100000000009;
        for(ll i=0;i<26;i++)
        {
            cin>>a
        }
        while(true)
        {
            x=0;
            x1=0;
        for(ll i=0;i<26;i++)
        {
            if(a[i]==0)
            continue;
            else if(a[i]>=c)
            {
                x++;
            }
            else if(a[i]==1)
            x1=1;
        }
        if(x>y)
        {
            y=x;
            c+=2;
            z++;
        }   
        else if(x<y || y==0)
        break;
        else
        {
            c+=2;
            z++;
        }
        }
        if(z==0 && x1==0)
        cout<<"0 0\n";
        else if(z==0 && x1==1)
        cout<<"1 1"<<"\n";
        else if(z==1 && x1==1)
        {
            cout<<y*2+1<<" "<<1<<"\n";
        }
        else if(z==1)
        {
            cout<<(y*2)<<" 1"<<"\n";
        }
        else if(z>1)
        {
            if(x1==0)
            cout<<y*2<<" "<<z<<"\n";
            else
            cout<<y*2+1<<" "<<1<<"\n";
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

