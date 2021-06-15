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
        cout<<"Case #"<<t1<<": ";
        ll n,k;
        cin>>n>>k;
        vector <ll> v;
        ll p;
        v.PB(1);
        for(ll i=0;i<n;i++)
        {
            cin>>p;
            v.PB(p);
        }
        v.PB(k);
        sort(all(v));
        vector <ll> co;
        for(ll i=1;i<v.size();i++)
        {
            if(i==1)
            co.PB(max(v[i]-v[i-1],0LL));
            else if(i==v.size()-1)
            co.PB(max(v[i]-v[i-1],0LL));
            else
            co.PB(max(v[i]-v[i-1]-1,0LL));
        }
        ll ma=co[0]+co[co.size()-1];
        for(ll i=1;i<co.size();i++)
        {
            ma=max(ma,co[i]);
        }
        for(ll i=0;i<co.size();i++)
        {
            ll s=0;
            if(i==0)
            s=s+co[i];
            else
            s=s+(co[i]+1)/2;
            for(ll j=i+1;j<co.size();j++)
            {
                if(j==co.size()-1)
                {
                    ma=max(ma,s+co[j]);
                }
                else
                {
                    ma=max(ma,s+(co[j]+1)/2);
                }
            }
        }
        ld ans=(ld)(ma)/(ld)(k);
        cout<<decimal(9,ans);


            


        cout<<"\n";
        t1++;
    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

