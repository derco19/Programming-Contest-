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
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

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
    int prime[n+1];
    fill(prime,-1);
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == -1) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = 0; 
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

    // freopen("ladder.in", "r", stdin);   // name of input file
	// freopen("ladder.out", "w", stdout); // name of output file

    // ifstream fin("art.in");
    // ofstream fout("art.out");
    
    // fstream file, output;
	// file.open(R"()", ios::in);        // add the address of local input file
	// output.open(R"()", ios::out);  // add the address of local output file
      
    ll t=1,t1=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        set <ll> s,s1,s2;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            s.insert(a[i]);
            s1.insert(i+1);
        }
        if(n==1)
        {
            cout<<"1\n1\n";
            continue;
        }
        for(auto u:s)
        s1.erase(u);
        s2=s1;
        ll b[n+1],c[n+1];
        b[1]=a[0];
        c[1]=a[0];
        for(ll i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
            {
                b[i+1]=*(s1.begin());
                s1.erase(b[i+1]);
                auto itr=s2.lower_bound(a[i-1]);
                itr--;
                c[i+1]=*itr;
                s2.erase(c[i+1]);
            }
            else
            {
                b[i+1]=a[i];
                c[i+1]=a[i];
            }
        }
        
        for(ll i=1;i<=n;i++)
        cout<<b[i]<<" ";
        cout<<"\n";
        for(ll i=1;i<=n;i++)
        cout<<c[i]<<" ";
        cout<<"\n";

    }
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/
