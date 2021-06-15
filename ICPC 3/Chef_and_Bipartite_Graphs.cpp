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
        ll n,m,d,d1;
        cin>>n>>m>>d>>d1;
        vector <pair<ll,ll>> v;
        ll c=0,x=0,l=0,r=0;
        for(ll i=0;i<=n-1;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                ll p=j+i;
                if(p>n)
                p=p-n;
                v.PB(MP(j,p));
                c++;
                if(c==m)
                {
                    x=1;
                    if(j==n)
                    {
                        l=i+1 , r=i+1;
                    }    
                    else
                    {
                        l=i;
                        r=i+1;
                    }
                    break;
                }    
            }
            if(x==1)
            break;
        }
        if(d<=l && r<=d1)
        {
            for(auto u:v)
            cout<<u.F<<" "<<u.S<<"\n";
        }
        else
        cout<<"-1\n";

    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

