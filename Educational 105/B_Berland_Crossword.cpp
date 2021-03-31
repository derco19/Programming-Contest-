#include<bits/stdc++.h>

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
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  

    // freopen("div7.in", "r", stdin);   // name of input file
	// freopen("div7.out", "w", stdout); // name of output file

    // ifstream fin("art.in");
    // ofstream fout("art.out");
    
    // fstream file, output;
	// file.open(R"()", ios::in);        // add the address of local input file
	// output.open(R"()", ios::out);  // add the address of local output file
      
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,u,r,d,l;
        ll b[4];
        cin>>n>>u>>r>>d>>l;
        ll x=0,uu=u,rr=r,dd=d,ll=l;
        if(uu==n)
        {
            uu-=2;
            rr--;
            ll--;
        }
        else if(uu==n-1)
        {
            uu--;
            if(rr<ll)
            {
                ll--;
            }
            else
            {
                rr--;
            }
        }
        if(dd==n)
        {
            dd-=2;
            rr--;
            ll--;
        }
        else if(dd==n-1)
        {
            dd--;
            if(rr<ll)
            {
                ll--;
            }
            else
            {
                rr--;
            }
        }
        if(rr<0 || ll<0)
        {
            cout<<"NO\n";
            continue;
        }
        if(r==n)
        {
            r-=2;
            u--;
            d--;
        }
        else if(r==n-1)
        {
            r--;
            if(u<d)
            d--;
            else
            u--;
        }
        if(l==n)
        {
            l-=2;
            u--;
            d--;
        }
        else if(l==n-1)
        {
            l--;
            if(u<d)
            d--;
            else
            u--;
        }
        if(u<0 || d<0)
        cout<<"NO\n";
        else
        cout<<"YES\n";

    }
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

