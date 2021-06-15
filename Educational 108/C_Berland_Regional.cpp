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

ll prime[200005];
vector <ll> pr;

void Sieve(int n) 
{ 
    fill(prime,-1);
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == -1) 
        { 
            for (int i=p; i<=n; i += p)
            if(prime[p]==-1) 
            prime[i] = p; 
        } 
    } 
    for (int p=2; p<=n; p++) 
    {
        if(prime[p]==p)
        pr.PB(p);
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
    Sieve(20005);
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll p;
        vector <ll> v[n+1];

        for(ll i=0;i<n;i++)
        {
            cin>>p;
            v[a[i]].PB(p);
        }
        vector <ll> check;
        vector <ll> dc;
        ll s=0;
        for(ll i=1;i<=n;i++)
        {
            if(v[i].size()>0)
            {
                sort(all(v[i]));
                reverse(all(v[i]));
                for(ll j=1;j<v[i].size();j++)
                {
                    v[i][j]+=v[i][j-1];
                }
                if(v[i].size()>1)
                check.PB(i);
                s=s+v[i][v[i].size()-1];
            }    
        }
        cout<<s<<" ";
        for(ll i=2;i<=n;i++)
        {
            s=0;
            vector <ll> vr;
            for(auto u:check)
            {
                ll p=v[u].size();
                p=(p/i)*i-1;
                if(p!=-1)
                s=s+v[u][p];
                if(v[u].size()>i)
                vr.PB(u);
            }
            cout<<s<<" ";
            check.clear();
            check=vr;
        }
        cout<<"\n";
                
    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

