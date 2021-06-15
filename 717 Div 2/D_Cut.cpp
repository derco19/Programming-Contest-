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

vector <ll> prime;

void Sieve(int n) 
{ 
    vector <ll> v(n+1,-1);
    for (int p=2; p*p<=n; p++) 
    { 
        if (v[p] == -1) 
        { 
            for (int i=p*p; i<=n; i += p) 
            v[i] = 0; 
        } 
    } 
    for (ll i=2; i<=n; i++) 
    {
        if(v[i]==-1)
        prime.PB(i);
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
    // cin>>t;
    Sieve(100005);
    
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        ll a[n+1];
        ll prefill[n+1];
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            prefill[i]=mo;
        }
        prefill[n]=n;
        
        map <ll,ll> m;
        for(auto u:prime)
        {
            m[u]=-1;
        }    
        for(auto u : m)
        {
            if(a[n]%u.F==0)
            m[u.F]=n;
            if(u.F>a[n])
            break;
        }
        for(ll i=n-1;i>0;i--)
        {
            ll s=n+1;
            if(binary_search(all(prime),a[i]))
            {
                if(m[a[i]]!=-1)
                {
                    s=m[a[i]];
                }
                m[a[i]]=i;
            }
            for(ll j=2;;j++)
            {
                if(j*j>a[i])
                break;
                if(binary_search(all(prime),j))
                if(a[i]%j==0)
                {
                    if(m[j]!=-1)
                    {
                        if(m[j]<s)
                        s=m[j];
                    }
                    m[j]=i;
                }
                if(a[i]%j==0 && a[i]/j!=j)
                if(binary_search(all(prime),a[i]/j))
                {
                    if(a[i]%j==0){
                    if(m[a[i]/j]!=-1)
                    {
                        if(m[a[i]/j]<s)
                        s=m[a[i]/j];
                    }
                    m[a[i]/j]=i;
                    }
                }
            }
            prefill[i]=s-1;
            if(i!=n)
            prefill[i]=min(prefill[i],prefill[i+1]);
        }
        
        ll dp[n+2][20];
        for (ll i = 0; i < 20; i++) 
        dp[n + 1][i] = n + 1;
        ll fu[n+1];
        for(ll i=1;i<=n;i++){
            fu[i]=n+1;
            dp[i][0]=prefill[i]+1;
        }
        
        for (ll i = n; i >0; i--) 
        {
            for (ll j = 1; j <20; j++) 
            {
                dp[i][j] = dp[dp[i][j-1]][j - 1];
            }  
        }
    
        ll l,r;
        for(ll i=0;i<q;i++)
        {
            ll ans=0;
            cin>>l>>r;
            for(int j=19;j>=0;j--)
		    {
			    if(dp[l][j]<=r)
				l=(dp[l][j]),ans+=(1<<j);
		    }
            ans++;
            cout<<ans<<"\n";
        }

    }  
}

/*
Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
3.) It can be solved
*/

